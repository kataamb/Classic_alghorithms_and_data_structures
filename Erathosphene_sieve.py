def Erathosphene_sieve(n):
    allNumb=[]
    primes=[]
    j=0
    for i in range(2, n+1): #first all numbers are in list
        allNumb.append(i)
    for i in range(len(allNumb)):
        if allNumb[i]:
            primes.append(allNumb[i])

            for j in range(i, n+1, allNumb[i]):
                allNumb[j]=False
    return primes

n=int(input())
#print(Erathosphene_sieve(n))
k = Erathosphene_sieve(n)
for i in k:
    print(i, end=' ')
