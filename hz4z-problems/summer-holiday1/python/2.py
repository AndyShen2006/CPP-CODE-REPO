# 由于题设要求，我这段代码用了搜索法，但是这不是个好办法，正确的方法应该用辗转相除
a = int(input())
b = int(input())
m = min(a, b)
ans = 0
for x in range(1, m):
    if (a % x == 0) & (b % x == 0):
        ans = max(ans, x)
print(ans, end="\n")
