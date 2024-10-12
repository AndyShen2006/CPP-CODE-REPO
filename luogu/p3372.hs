-- Data,LazyTag, LeftTree, RightTree
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Use bimap" #-}

data Tree a = Empty | Node a a (Tree a) (Tree a)

getData :: (Num t) => Tree t -> t
getData (Node a b lt rt) = a

-- oldT curl curr newT
pushDown :: Tree Int -> Int -> Int -> Tree Int
pushDown (Node d lz (Node ld llz llt lrt) (Node rd rlz rlt rrt)) curl curr =
    Node d 0 (Node (ld + lz * (mid - curl + 1)) (llz + lz) llt lrt) (Node (rd + lz * (curr - mid)) (rlz + lz) rlt rrt)
  where
    mid = curl + div (curr - curl) 2

-- a l r p
build :: (Num t) => [t] -> Int -> Int -> Tree t
build a l r =
    if l == r
        then Node (a !! l) 0 Empty Empty
        else Node (getData lt + getData rt) 0 lt rt
  where
    mid = div (l + r) 2
    lt = build a l mid
    rt = build a (mid + 1) r

-- l r curl curr oldT (newT,sum)
getsum :: Int -> Int -> Int -> Int -> Tree Int -> (Tree Int, Int)
getsum l r curl curr (Node d lz lt rt) =
    if l <= curl && r <= curr
        then (Node d lz lt rt, d)
        else (Node (getData pDT) 0 (fst lgs) (fst rgs), snd lgs + snd rgs)
  where
    mid = curl + div (curr - curl) 2
    pDT = if lz > 0 then pushDown (Node d lz lt rt) curl curr else Node d lz lt rt
    lgs = if l <= mid then getsum l r curl mid pDT else (Empty, 0)
    rgs = if mid < r then getsum l r curl mid pDT else (Empty, 0)

-- l r curl curr c oldT newT
update :: Int -> Int -> Int -> Int -> Int -> Tree Int -> Tree Int
update l r curl curr c (Node d lz lt rt) =
    if l <= curl && r <= curr
        then Node (d + (curr - curl + 1) * c) (lz + c) lt rt
        else Node (getData lgs + getData rgs) lz lgs rgs
  where
    mid = curl + div (curr - curl) 2
    pDT = if lz > 0 && curl /= curr then pushDown (Node d lz lt rt) curl curr else Node d lz lt rt
    lgs = if l <= mid then update l r curl mid c pDT else Empty
    rgs = if mid < r then update l r curl mid c pDT else Empty

main = do
    [n :: Int, m] <- fmap (map read . words) getLine
    putStrLn "AAA"