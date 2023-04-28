import Control.Monad
import Data.List

main = do
    n <- read <$> getLine
    nums <- replicateM n getLine
    putStrLn $ maximum (filter (\x -> x == reverse x) nums)