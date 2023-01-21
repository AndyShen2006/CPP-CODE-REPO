import Control.Monad (replicateM)
import Data.List (transpose)

check :: [(Double, Int)] -> Int
check [] = 0
check (x : xs)
    | fst x > realToFrac (snd x) = check xs
    | otherwise = 1 + check xs

main = do
    [a, _] <- map read . words <$> getLine
    d <- replicateM a $ map read . words <$> getLine
    let aver = (/ realToFrac a) <$> (realToFrac <$> (sum <$> transpose d))
    let ans = check . zip aver <$> d
    putStr $ foldl (\acc x -> acc ++ show x ++ "\n") [] ans
