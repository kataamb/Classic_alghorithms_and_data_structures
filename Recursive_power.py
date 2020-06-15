def natPow(a, n):
    if n==1:
        return a
    else:
        return(natPow(a, n-1)*a)
l=[int(i) for i in input().split()]
a, n = l[0], l[1]
print(natPow(a, n))
