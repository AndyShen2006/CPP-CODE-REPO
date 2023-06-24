(*
Program 5-3
Copyright (C) 2023  Andy Shen
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*)

let main =
  let b = read_int() in
  let s = read_int() in
  for x=1 to 9 do
    Printf.printf "%d," (b+s*x)
  done;
  Printf.printf "%d\n" (b+s*10)
;;