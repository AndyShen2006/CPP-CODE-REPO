main = do
    [x, y] <- fmap (map read . words) getLine
    let l = max x y
    putStrLn $ foldl (\acc x -> acc ++ (show x) ++ " ") [] [l .. 6]