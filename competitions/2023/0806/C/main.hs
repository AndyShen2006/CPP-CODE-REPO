dfs :: [Int] -> Int -> Int -> Int -> Int -> Int ->
dfs lis cnt sum start n k = if cnt == k and (null [x|x<-[2..n-1],n`mod`x==0])
                        then 1
                        else 


main = do
    [n,k] <- fmap (map read . words) getLine
    m <- fmap (map read . words) getLine
    print (dfs m 0 0 0 k)