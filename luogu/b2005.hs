main = do
    c <- fmap (head . head . words) getLine
    putStrLn ("  " ++ [c])
    putStrLn (" " ++ replicate 3 c)
    putStrLn (replicate 5 c)