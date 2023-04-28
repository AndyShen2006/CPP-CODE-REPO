import Data.List

main = do
    [m :: Int, n :: Int] <- fmap (map read . words) getLine
    putStrLn $ foldl (\acc x -> acc ++ show x ++ " ") [] $ sort [2 * m * n, m * m - n * n, m * m + n * n]