#!/usr/bin/python
n = int(input())
stk = [0] * 100
top = 0
while n > 0:
    item = input()
    if item == "+":
        a = stk[top]
        top -= 1
        b = stk[top]
        stk[top] = a + b
    elif item == "-":
        a = stk[top]
        top -= 1
        b = stk[top]
        stk[top] = a - b
    elif item == "*":
        a = stk[top]
        top -= 1
        b = stk[top]
        stk[top] = a * b
    else:
        top += 1
        stk[top] = int(item)
    n -= 1
print(stk[top])
