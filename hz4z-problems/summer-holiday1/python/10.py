# By AndyShen
def sol(lis, res: int, cnt: int):
    if cnt > 5:
        return
    sum = 0
    for x in lis:
        sum += x
    if sum > res:
        return
    if cnt == 5 and sum == res:
        print(lis)
        return
    sol(lis + [10], res, cnt + 1)
    sol(lis + [5], res, cnt + 1)
    sol(lis + [2], res, cnt + 1)
    sol(lis + [1], res, cnt + 1)


sol([], 7, 0)
