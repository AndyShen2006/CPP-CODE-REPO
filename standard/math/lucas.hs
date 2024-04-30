fact :: Int -> Int -> Int
fact 0 _ = 1
fact n p = n * fact (n - 1) p `mod` p

c :: (Int, Int) -> Int -> Int
c (n, m) p = fact n p `div` (fact m p * fact (n - m) p)

lucas :: (Int, Int) -> Int -> Int
lucas (_, 0) _ = 1
lucas (n, m) p = (lucas (n `div` p, m `div` p) p * c (n `mod` p, m `mod` p) p) `mod` p

main = do
    [n, m, p] <- fmap (map read . words) getLine
    print $ c (n, m) p

-- print $ lucas (n, m) p