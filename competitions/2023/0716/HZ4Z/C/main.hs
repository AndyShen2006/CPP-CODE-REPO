import qualified Data.Map as Map

makemap :: [Int] -> Map.Map Int Int
makemap [] = Map.empty
makemap (x:xs) = do
    let cur = makemap xs
    if Map.lookup x cur == Nothing then
        Map.insert x 1 cur
    else
        Map.insertWith (+) x 1 $ cur

ans :: [Int] -> Map.Map Int Int -> Int -> Int
ans [] _ _ = 0
ans (x:xs) m c = if Map.lookup (x+c) m == Nothing then
                    ans xs m c
                else
                    ans xs m c + (m Map.! (x+c))

main = do
    [n,c] <- fmap (Prelude.map read . words) getLine
    lis <- fmap (Prelude.map read . words) getLine
    let mymap = makemap lis
    print $ ans lis mymap c