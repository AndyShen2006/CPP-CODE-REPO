main = do
    n <- fmap read getLine
    if null  [x|x<-[2..n-1],n`mod`x==0]
        then putStrLn "YES"
    else putStrLn "NO"
