t = int(input())

for i in range(1, t+1):
    n = int(input())
    ans = 0
    for j in range(1, n+1):
        op = int(input())
        if (op == 1):
            ans = ans << 1
        elif (op == 2):
            d = int(input())
            ans = ans + d
    print(bin(ans))
