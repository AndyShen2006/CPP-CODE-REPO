main = do
    a <- fmap read getLine
    b <- fmap read getLine
    putStrLn (show a ++ "+" ++ show b ++ "=" ++ show (a + b))