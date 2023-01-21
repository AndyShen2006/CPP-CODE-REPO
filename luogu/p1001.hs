main = do
    let x = (1, 2)
    [a, b] <- fmap (map read . words) getLine
    print (a + 0)
    print $ fst x