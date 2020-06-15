def Erathosphene_sieve(n):
    allNumb=[]
    primes=[]
    j=0
    for i in range(2, n+1): #first all numbers are in list
        allNumb.append(i)
    for i in range(len(allNumb)):
        if allNumb[i]:
            primes.append(allNumb[i])
            j=i
            while j<=n-2: #!!!!!!! n-2!!!!
                allNumb[j]=False
                j+=primes[len(primes)-1] #last el of primes - needed one
    return primes

z=[int(i) for i in input().split()]
a, b = z[0], z[1]
#n=int(input())
#print(Erathosphene_sieve(n))
k = Erathosphene_sieve(b)
j=0
while (j<=len(k)-1) and (k[j]<a):
    j+=1
k=k[j:]
if not(len(k)):
    print(0)
else:
    for i in k:
        print(i, end=' ')
