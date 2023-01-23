import Control.Monad
import Data.Array.IO

type A = IOUArray Int (IOUArray Int Int)

sumNum :: String -> Int -> Int -> Integer -- [from,to];"from" from 0
sumNum num from to = read (take to (drop from num))

main = do
    [n, m] <- map read . words <$> getLine
    num <- getLine