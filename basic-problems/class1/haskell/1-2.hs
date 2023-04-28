main = do
    a <- fmap read getLine
    b <- fmap read getLine
    putStrLn (show (a + b) ++ "," ++ show (a - b) ++ "," ++ show (a * b) ++ "," ++ show (a / b))