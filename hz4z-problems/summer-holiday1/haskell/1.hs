main = do
    n <- fmap read getLine
    putStrLn $ foldl (\cur x-> cur++show x++" ") "" [x|x<-[2..n-1],n`mod`x==0]
