MOD = 1000000007
MOD2 = 998244353
ii = lambda: int(input())
si = lambda: input()
dgl = lambda: list(map(int, input()))
f = lambda: map(int, input().split())
il = lambda: list(map(int, input().split()))
ls = lambda: list(input())
let = '@abcdefghijklmnopqrstuvwxyz'

def prsbst(arr,sm,n,prdp):
    if sm==0:
        print('ans',*prdp)
        return
    if n==0:
        return
    if arr[n-1]<=sm and  dp[n][sm-arr[n-1]]:
        prdp.append(arr[n-1])
        prsbst(arr,sm-arr[n-1],n-1,prdp)
        if len(prdp)>0:
            prdp.pop()
    prsbst(arr, sm, n - 1, prdp)
def sbstsm(arr,sm,n):
    global dp
    for i in range(n+1):
        dp[i][0]=1
    for i in range(1,sm+1):
        dp[0][i]=0
    for i in range(1,n+1):
        for j in range(1,sm+1):
            dp[i][j]=dp[i-1][j]
            if arr[i-1]<=j:
                dp[i][j]+=dp[i-1][j-arr[i-1]]
for _ in range(ii()):
    n=ii()
    l=il()
    sm=ii()
    dp=[[0 for _ in range(sm+1)] for __ in range(n+1)]
    sbstsm(l,sm,n)
    prdp=[]
    prsbst(l,sm,n,prdp)
