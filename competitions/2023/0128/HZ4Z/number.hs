import Control.Monad
import Data.List

main = do
    n <- read <$> getLine
    nums :: [String] <- replicateM n $ getLine
    let allAns = sort (filter (\x -> x == reverse x) nums)
    putStrLn $ last allAns