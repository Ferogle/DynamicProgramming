MOD = 1000000007
MOD2 = 998244353
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())

def LCSPrint(s1,s2,ln1,ln2):
    if ln1==0 or ln2==0:
        return ['']
    if s1[ln1-1]==s2[ln2-1]:
        lst=LCSPrint(s1,s2,ln1-1,ln2-1)
        for i in range(len(lst)):
            lst[i]=lst[i]+(s1[ln1-1])
        return lst
    if dp[ln1-1][ln2]>dp[ln1][ln2-1]:
        return LCSPrint(s1,s2,ln1-1,ln2)
    if dp[ln1-1][ln2]<dp[ln1][ln2-1]:
        return LCSPrint(s1,s2,ln1,ln2-1)
    left=LCSPrint(s1,s2,ln1-1,ln2)
    rgt=LCSPrint(s1,s2,ln1,ln2-1)
    left.extend(rgt)
    return left
for _ in range(ii()):
    ln1,ln2=f()
    s1=si()
    s2=si()
    dp=[[0 for j in range(ln2+1)] for i in range(ln1+1)]
    for i in range(1,ln1+1):
        for j in range(1,ln2+1):
            if s1[i-1]==s2[j-1]:
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    x=LCSPrint(s1,s2,ln1,ln2)
    print(dp[ln1][ln2])
    print(*x)
