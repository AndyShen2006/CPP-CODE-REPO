import Control.Monad (replicateM)
import Data.ByteString (sort)
import Data.List (sortBy)

-- get :: [[Int]] -> Int -> Int
-- get [] _ = 0
-- get (x:xs) t = if (t+x!!) 

main = do
    [n,t] <- fmap (map read . words) getLine
    things <- replicateM n $ fmap (map read . words) getLine
    let sorted_things = sortBy (\l r->(l!!0/l!!1)<(r!!0/r!!1)) things
    print sorted_things
