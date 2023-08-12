dfs :: [Int] -> Int -> Int -> Int
dfs [] l r = max l r
dfs (x:xs) l r = min (dfs xs (l+x) r) (dfs xs l (r+x))

main = do
    getLine
    a<-fmap (map read . words) getLine
    b<-fmap (map read . words) getLine
    c<-fmap (map read . words) getLine
    d<-fmap (map read . words) getLine
    print $ (dfs a 0 0) + (dfs b 0 0) + (dfs c 0 0) + (dfs d 0 0)