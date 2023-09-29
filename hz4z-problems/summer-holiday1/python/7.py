# By AndyShen
n = int(input())
flag = True
ans = 0
for x in range(1, n + 1):
    if flag:
        ans += x
        flag = False
    else:
        ans -= x
        flag = True
print(ans)
