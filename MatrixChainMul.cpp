#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef long double ldo;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
typedef vector<string> vs;
typedef vector<vector<ll>> vvl;
typedef vector<vector<int>> vvi;
#define forz(iter,n)	for(ll iter=0;iter<n;++iter)
#define rep(iter,s,e)	for(ll iter=s;iter<e;++iter)
#define urep(iter,s,e)	for(ll iter=s;iter>=e;--iter)
#define MOD				(ll)1000000007
#define pp				pair<ll,ll>
#define vii				vector<int>
#define vll				vector<ll>
#define vpp				vector<pp>
#define vss				vector<string>
#define take(A,n)		{forz(iter,n)cin>>A[iter];}
#define pb				push_back
#define pob				pop_back
#define eb				emplace_back
#define pf				push_front
#define pof				pop_front
#define mkp				make_pair
#define all(a)			a.begin(),a.end()
#define ff				first
#define ss				second
#define lcm(a,b)		(a*b)/__gcd(a,b)
#define bs(v,x)			binary_search(all(v),x)
#define ub(v,x)			upper_bound(all(v),x)
#define lb(v,x)			lower_bound(all(v),x)
#define zoom			ios_base::sync_with_stdio(false);cin.tie(NULL);
int dp[100][100]={{0}};
int dpit[100][100]={{0}};
int ans=0;
int MCM(int *inp,int l,int r)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(r<=l+1)
	{
		dp[l][r]=0;
		return 0;
	}
	int mn=INT_MAX;
	rep(i,l+1,r)
	{
		int cost=MCM(inp,l,i)+MCM(inp,i,r)+inp[l]*inp[i]*inp[r];
		mn=min(cost,mn);
	}
	dp[l][r]=mn;
	return mn;
}			
int MCMit(int *inp,int n)
{
	forz(i,n+1)dp[i][i]=0;
	rep(len,2,n+1)
	{
		rep(i,1,n-len+2)
		{
			int j=i+len-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j && j<n;k++)
			{
				cout<<i<<" "<<k<<" "<<j<<endl;
				int cost = dp[i][k]+dp[k+1][j]+inp[i-1]*inp[k]*inp[j];
				dp[i][j]=min(dp[i][j],cost);
			}
		}
	}
	return dp[1][n-1];
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n;
	int *inp=new int[n];
	take(inp,n);

	forz(i,100+1)forz(j,100+1)dp[i][j]=0;
	//int ans=MCM(inp,0,n-1);
	int ans=MCMit(inp,n);
	forz(i,n+1)
	{
		forz(j,n+1)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
