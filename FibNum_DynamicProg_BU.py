def FibBU(n):
    if n<2:
        return n
    else:
        prev = 1
        cur = 1
        for i in range(n-2):
            t = cur
            cur = prev+cur
            prev = t
        return cur
print(FibBU(int(input())))
