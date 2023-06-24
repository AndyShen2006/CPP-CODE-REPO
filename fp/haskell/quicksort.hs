quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x : xs) =
    let smallSorted = quicksort (filter (<= x) xs)
        biggerSorted = quicksort (filter (> x) xs)
     in smallSorted ++ [x] ++ biggerSorted