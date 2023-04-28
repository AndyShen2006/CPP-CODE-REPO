main = do
    a :: Int <- fmap read getLine
    putStrLn (show (a + 8) ++ " " ++ show ((a + 8) `div` 5) ++ " " ++ show ((a + 8) `div` 5 - 10) ++ " " ++ show (((a + 8) `div` 5 - 10) * 10))