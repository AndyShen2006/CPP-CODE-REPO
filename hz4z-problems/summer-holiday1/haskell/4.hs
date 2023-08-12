main = do
    n <- fmap read getLine
    let s = sum [x|x<-[1..n-1],n`mod`x==0]
    if s==n then
        putStrLn "YES"
    else
        putStrLn "NO"