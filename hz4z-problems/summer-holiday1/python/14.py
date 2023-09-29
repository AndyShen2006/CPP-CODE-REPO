# By Andy Shen
def gcd(a: int, b: int) -> int:
    if a == 0:
        return b
    elif b == 0:
        return a
    else:
        return gcd(b, a % b)


a = int(input())
b = int(input())
print(gcd(a, b))
