# By Andy Shen
def sol(res: int, lis):
    if res == 0:
        print(lis)
        return
    if res < 5:
        return
    sol(res - 5, lis + [5])
    sol(res - 12, lis + [12])


sol(120, [])
