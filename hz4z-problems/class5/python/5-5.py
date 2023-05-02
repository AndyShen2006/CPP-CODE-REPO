# Program 5-5
# Copyright (C) 2023  Andy Shen

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# Note: This is a O(n) program to judge a prime(Obviously correct), but
# Miller-Rabin Algorithm(May not correct) will be a better choice
n = int(input())
for x in range(2, n):
    if n % x == 0:
        print("NO")
        exit()
print("YES")