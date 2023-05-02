-- Program 4-5
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
    [a, b, c, d] <- traverse (fmap read) [getLine, getLine, getLine, getLine]
    print ((a + b + c + d - maximum [a, b, c, d] - minimum [a, b, c, d]) / 2)