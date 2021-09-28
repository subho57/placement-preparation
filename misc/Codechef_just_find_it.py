t=int(input())
while(t):
    n=int(input())
    arr=list(map(int, input().split()))
    sumarr=[]
    for i in range(n):
        try:
            ind=arr.index(arr[i], i+1, n)
        except:
            pass
        temp=arr[i+1:ind]
        if(len(temp)%2==0 and len(temp)!=0 and arr[i]%2==0):
            sumarr+=[sum(temp)]
        elif(len(temp)%2!=0 and len(temp)!=0 and arr[i]%2!=0):
            sumarr+=[sum(temp)]
    print(max(sumarr))
    t-=1