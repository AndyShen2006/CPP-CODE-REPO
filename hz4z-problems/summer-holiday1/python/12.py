# By Andy Shen
n: int = int(input())
k: int = int(input())
ans: int = 0
while n > k:
    ans += n
    n = n % k + n // k
print(ans)
