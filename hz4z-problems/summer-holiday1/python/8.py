# By AndyShen
# This algorithm is naive. Use Euler's Sieve or Eratosenes' Sieve will be a better choice
n = int(input())
for x in range(2, n):
    if n % x == 0:
        flag = True
        for y in range(2, x):
            if x % y == 0:
                flag = False
                break
        if flag:
            print(x, end=" ")
print()
