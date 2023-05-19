-- Program 10-1
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

import Data.Map
import Data.Map qualified as Map

calc :: String -> Map Char Int
calc [] = Map.empty
calc (x : xs) = do
    let cur = calc xs
    if Map.member x cur
        then Map.insert x (cur ! x + 1) cur
        else Map.insert x 1 cur

main = do
    str <- getLine
    print $ toList $ calc str