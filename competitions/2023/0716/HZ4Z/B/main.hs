main = do
    [a,b] <- fmap (map read . words) getLine
    putStrLn $ foldl (\acc x->acc ++ (show x) ++ "\n") "" [x|x<-[a,a+1..b],show x == (reverse $ show x),null [y|y<-[2..x-1],x`mod`y==0]]