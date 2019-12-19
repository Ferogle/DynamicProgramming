MOD = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
def CoinChangeMeth2(dpt,lm,N,ind,m):
    for i in range(m):
        dpt[0][i]=1
    for i in range(1,N+1):
        dpt[i][0]=0
    for i in range(1,N+1):
        for j in range(m):
            x=0
            if i-lm[j]>=0:
                x=dpt[i-lm[j]][j]
            y=dpt[i][j-1] if j>=1 else 0
            dpt[i][j]=x+y
    return dpt[N][m-1]

def CoinChangeMeth1(dpt,lm,N,ind,m):
    if N==0:
        return 1
    if N<0 or ind>=m:
        return 0
    if dpt[N][ind]>-1:
        return dpt[N][ind]
    dpt[N][ind]=CoinChangeMeth1(dpt,lm,N-lm[ind],ind,m)+CoinChangeMeth1(dpt,lm,N,ind+1,m)
    return dpt[N][ind]
for _ in range(ii()):
    m=ii()
    lm=il()
    N=ii()
    dpt=[[-1 for i in range(m)] for j in range(N+1)]
    print(CoinChangeMeth1(dpt,lm,N,0,m))

