# Note: This is a O(n) program to judge a prime(Obviously correct), but
# Miller-Rabin Algorithm(May not correct) will be a better choice
n = int(input())
for x in range(2, n):
    if n % x == 0:
        print("NO")
        exit()
print("YES")
