
def printf(arr):
    for i in arr:
        print(i,end=' ')
    print()

planes = [8,6,5,5,2]
groups = [2,2,6,6,7,7,7,8,8]
for j in range(0,len(planes)):
    for i in range(0,len(groups)):
        print("Compare Between ",groups[len(groups)-i-1]," and ",
        planes[j]," I value ",i," J value ",j)
        if(groups[len(groups)-i-1]<=planes[j]):
            print(groups[len(groups)-i-1])
            c = groups.pop(len(groups)-i-1)
            print("Popped output ",c)
            printf(groups)
            j+=1
        else:
            i+=1
    