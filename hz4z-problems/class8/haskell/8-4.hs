-- Program 8-4
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

-- The Word of this problem isn't clear, this program may be incorrect
import Data.Char (toUpper)
import Data.List

main = do
    ch <- fmap head getLine
    putStrLn $ case ch of
        'A' -> "1"
        'B' -> "2"
        'C' -> "3"
        'a' -> "YES"
        'b' -> "YES"
        'c' -> "YES"
        ch -> "NO"