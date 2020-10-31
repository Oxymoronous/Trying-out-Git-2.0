pset = []
def permute(anylist,l,r):
    if(l == r):
        temp = ''.join(anylist)
        pset.append(temp)
        return 
    for i in range(l, r+1):
        #swap
        anylist[l],anylist[i] = anylist[i],anylist[l]
        permute(anylist,l+1, r)
        anylist[l],anylist[i] = anylist[i],anylist[l]
    
l1 = ['1','2','3','4','5','6']
s = '123456'
count = 0
permute(l1, 0, 5)
for p in pset:
    #just looking at the results
    #checking for derangements
    pos = True
    for e1,e2 in zip(p,s):
        
        if (e1 == e2):
            pos = False
            break
    if (pos):
        cut = p[3:]
        if ('1' in cut and '2' in cut and '3' in cut):
            print(p)
            count += 1
print(count)
    
            
