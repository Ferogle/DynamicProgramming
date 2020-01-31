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
int EDS(string s1,string s2,int n,int m)
{
	if(n==0)
		return m;
	else if(m==0)
		return n;
	if(s1[n-1]==s2[m-1])
		return EDS(s1,s2,n-1,m-1);
	return 1+min({EDS(s1,s2,n-1,m),EDS(s1,s2,n,m-1),EDS(s1,s2,n-1,m-1)});
}

void EDSiter(string s1,string s2,int n,int m)
{
	forz(i,n+1)dpit[i][0]=i;
	forz(i,m+1)dpit[0][i]=i;
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(s1[i-1]==s2[j-1])
				dpit[i][j]=dpit[i-1][j-1];
			else
				dpit[i][j]=1+min({dpit[i-1][j],dpit[i-1][j-1],dpit[i][j-1]});
		}
	}
	cout<<dpit[n][m]<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	string s1,s2;
	int n,m;
	cin>>n>>m>>s1>>s2;
	cout<<EDS(s1,s2,n,m)<<endl;
	EDSiter(s1,s2,n,m);
	return 0;
}
