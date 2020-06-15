def Erathosphene_sieve(n):
    allNumb=[]
    primes=[]
    j=1000
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
n=int(input())
print(Erathosphene_sieve(n))
