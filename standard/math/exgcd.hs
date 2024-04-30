exgcd :: (Int, Int) -> ((Int, Int), Int)
exgcd (a, 0) = ((1, 0), a)
exgcd (a, b) = ((y, x - a `div` b * y), ret)
  where
    ((x, y), ret) = exgcd (b, a `mod` b)

main = do
    [a :: Int, b :: Int] <- fmap (map read . words) getLine
    let ((x, y), ret) = exgcd (a, b)
    putStrLn (show x ++ " " ++ show y)