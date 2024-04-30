import GHC.Float (rationalToDouble)

main = do
    putStrLn "Input X List:"
    x <- fmap (map read . words) getLine
    putStrLn "Input P List:"
    p :: [Double] <- fmap (map read . words) getLine
    let e = sum $ zipWith (*) x p
    putStrLn $ "E(X):" ++ show e
    let d = sum (zipWith (*) (map (\x -> x * x) x) p) - (e * e)
    putStrLn $ "D(X):" ++ show d ++ " " ++ show (toRational d)
    putStrLn $ "sig(X):" ++ show (sqrt d)