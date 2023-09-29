# By AndyShen
l1 = 1
l2 = 1
n = int(input())
for x in range(1, n):
    tmp = l1 + l2
    l1 = l2
    l2 = tmp
print(l1)
