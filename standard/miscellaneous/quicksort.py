def quicksort(a):
    if len(a) == 0:
        return []
    head = a[0]
    ss = quicksort([x for x in a[1:] if x <= head])
    bs = quicksort([x for x in a[1:] if x > head])
    return ss + [head] + bs


print(quicksort([1, 5, 4, 3, 2]))
