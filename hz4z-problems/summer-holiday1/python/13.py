# By Andy Shen
a = int(input())
Nega = False
if a < 0:
    Nega = True
    a = -a
while a % 10 == 0:
    a //= 10
lis = []
while a > 0:
    lis.append(a % 10)
    a //= 10
if Nega:
    print("-", end="")
for x in lis:
    print(x, end="")
print()
