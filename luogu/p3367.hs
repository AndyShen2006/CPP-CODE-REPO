{-# LANGUAGE Strict #-}
{-# OPTIONS_GHC -O2 #-}

import Control.Monad
import Data.Array.IO
import Data.Time.Format.ISO8601 (yearFormat)
import GHC.CmmToAsm.AArch64.Instr (x0)
import GHC.Float (fabsDouble)

type A = IOUArray Int Int

findpar :: A -> Int -> IO Int
findpar a x = do
    fa <- readArray a x
    if fa == x
        then return fa
        else do
            fb <- findpar a fa
            writeArray a x fb
            return fb

unite :: A -> Int -> Int -> IO ()
unite a x y = do
    fx <- findpar a x
    fy <- findpar a y
    when (fx == fy) $ do
        writeArray a fx fy
        unite a fy fx

isSamePar :: A -> Int -> Int -> IO String
isSamePar a x y = do
    fx <- findpar a x
    fy <- findpar a y
    if fx == fy
        then return "Y"
        else return "N"

initA :: Int -> IO A
initA n = newListArray (1, n) [1 .. n]
main = do
    [n, m] <- fmap (map read . words) getLine
    a <- initA n
    replicateM_ m $ do
        [op, x, y] <- fmap (map read . words) getLine
        case op of
            1 -> unite a x y
            2 -> isSamePar a x y >>= putStrLn