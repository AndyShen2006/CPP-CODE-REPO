main = do
    [x, y, n] <- fmap (map read . words) getLine
    print ((n `div` x) + (n `div` y) - (n `div` lcm x y))