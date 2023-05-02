import Text.XHtml (base)

-- Program 9-3
-- Copyright (C) 2023  Andy Shen
-- This program is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.

-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.

-- You should have received a copy of the GNU General Public License
-- along with this program.  If not, see <https://www.gnu.org/licenses/>.
compute :: [Int] -> [Int] -> (Int, Int)
compute [] b = (0, length b)
compute a [] = (length a, 0)
compute a b
    | a > b = (fst tu + 1, snd tu)
    | a < b = (fst tu, snd tu + 1)
    | otherwise = tu
  where
    tu = compute (drop 1 a) (drop 1 b)

main = do
    [n :: Int, m] <- fmap (fmap read . words) getLine
    lis1 <- fmap (fmap read . words) getLine
    lis2 <- fmap (fmap read . words) getLine
    let tu = compute lis1 lis2 in putStrLn $ show (fst tu) ++ " " ++ show (snd tu)
