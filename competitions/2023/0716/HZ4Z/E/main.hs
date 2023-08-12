import Control.Monad (replicateM)
import qualified Data.Map as Map

buildTree::[[Int]]->Map Int [Int]
buildTree [] = []
buildTree [[a,b]] = 

main = do
    n <- fmap read getLine
    edges <- replicateM n $ fmap (map read . words) getLine
