main = do
    a<-fmap read getLine
    b<-fmap read getLine
    print $ gcd a b