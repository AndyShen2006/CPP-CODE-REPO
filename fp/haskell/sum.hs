mysum :: (Num a) => [a] -> a
mysum xs = foldl (\acc x -> acc + x) 0 xs