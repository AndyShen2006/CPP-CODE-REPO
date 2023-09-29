# By AndyShen
a = int(input())
b = int(input())
cnt = 0
for x in range(a, b + 1):
    if x // 100 == 1:
        cnt += 1
    if x // 10 % 10 == 1:
        cnt += 1
    if x % 10 == 1:
        cnt += 1
print(cnt)
