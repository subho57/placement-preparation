t = int(input())
while(t):
    n, k = map(int, input().split())
    chk = n//k;
    d = 0
    for i in range(1, chk+1):
        d+=2*i*k
    d+=n
    print(d%1000000007)
    t-=1