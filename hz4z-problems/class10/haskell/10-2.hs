-- Program 10-2
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

import Data.Char

calc :: String -> (Int, Int)
calc [] = (0, 0)
calc (x : xs) = do
    let cur = calc xs
    if digitToInt x `mod` 2 == 1
        then (fst cur + 1, snd cur)
        else (fst cur, snd cur + 1)

main = do
    str <- getLine
    print $ calc str