main = do
    getLine
    a <- map read . words <$> getLine
    print $ maximum a - minimum a