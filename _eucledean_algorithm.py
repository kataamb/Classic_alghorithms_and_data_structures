def gcd(a, b):
    if a<b:
        t=a
        a=b
        b=t
    while b>0:
        k = a % b
        a = b
        b = k
    return a
r=input().split()
a= int(r[0])
b= int(r[1])
print(gcd(a, b))
        
