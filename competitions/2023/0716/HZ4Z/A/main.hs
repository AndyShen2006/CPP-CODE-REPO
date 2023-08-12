ans::[Char]->Int
ans [] = 0
ans(x:xs) = if x==' '
            then ans xs
            else ans xs+1

main = do
    str <- getLine
    print $ ans str