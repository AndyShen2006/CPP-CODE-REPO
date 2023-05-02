-- Program 1-4
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
main = do
    a <- fmap read getLine
    b <- fmap read getLine
    c <- fmap read getLine
    putStrLn (show (a * b) ++ " " ++ show (a * c) ++ " " ++ show (b * c))
    print (a * b * c)