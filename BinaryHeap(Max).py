class MaxHeap:
    ###
    def __init__(self, oneDimMas):
        oneDimMas.sort(reverse=True)
        self.heap = oneDimMas
        self.size= len(self.heap)-1 #index of last element in heap

    def deleteEl(self, ind=0):
       if ind <= self.size: # '=' too, 'cause size - last index of mas
           self.heap[ind], self.heap[self.size]=self.heap[self.size], self.heap[ind]
           del self.heap[self.size]
           self.size-=1
           self.siftDown(ind)
           
    def insert(self, n):
        self.heap.append(n)
        self.size+=1
        i=self.size
        while (((i-1)//2)>=0) and (self.heap[i]>self.heap[(i-1)//2]):
            self.heap[i], self.heap[(i-1)//2] = self.heap[(i-1)//2], self.heap[i]
            i=(i-1)//2
       
    def siftDown(self, ind=0): #
        i=ind
        # i=n
        #l, r = 1, 2
        l, r = 2*i+1, 2*i+2
        while ((l<=self.size) or (r<=self.size)):
            if r<=self.size:
                maxInd = l if self.heap[l]>self.heap[r] else r
                if self.heap[i]<self.heap[maxInd]:
                    self.heap[i], self.heap[maxInd] = self.heap[maxInd], self.heap[i]
                    i=maxInd
                    l, r=2*i+1, 2*i+2
                else:
                    break
            else:
                if self.heap[i]<self.heap[l]:
                    self.heap[i], self.heap[l] = self.heap[l], self.heap[i]
                    i=l
                    l, r=2*i+1, 2*i+2
                else:
                    break
        
        
    def extractMax(self):
        returnVal = self.heap[0]
        self.heap[0], self.heap[self.size]=self.heap[self.size], self.heap[0]
        del self.heap[self.size]
        self.size-=1
        self.siftDown()
        return returnVal

#n=int(input())
c = MaxHeap([int(i) for i in input().split()])
c.deleteEl(2)
print(c.heap)
