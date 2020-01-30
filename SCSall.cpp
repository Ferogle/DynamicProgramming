#include<bits/stdc++.h>
#include<string>
using namespace std;
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define PB push_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long int int64;
typedef vector<int64> VI64;
typedef vector<pair<int64,int64>> VII64;
typedef vector<string> VS;
typedef vector<vector<int64>> VVI;
int lookup[100][100]={{0}};
int dp[100][100]={{0}};
void SCS(string s1,string s2,int n,int m)
{
	for(int i=0;i<=n;i++)
		dp[i][0]=i;
	for(int i=0;i<=m;i++)
		dp[0][i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<endl;
}
VS SCSOne(string s1,string s2,int n,int m)
{
	if(m==0)
	{
		VS tem;
		tem.PB(s1.substr(0,n));
		return tem;
	}
	else if(n==0)
	{
		VS tem;
		tem.PB(s2.substr(0,m));
		return tem;
	}
	if(s1[n-1]==s2[m-1])
	{
		VS tem=SCSOne(s1,s2,n-1,m-1);
		for(string &str : tem)
			str.PB(s1[n-1]);
		return tem;
	}
	else if(dp[n-1][m]<dp[n][m-1])
	{
		VS tem=SCSOne(s1,s2,n-1,m);
		for(string &str : tem)
			str.PB(s1[n-1]);
		return tem;
	}
	else if(dp[n-1][m]>dp[n][m-1])
	{
		VS tem=SCSOne(s1,s2,n,m-1);
		for(string &str : tem)
			str.PB(s2[m-1]);
		return tem;
	}
	VS top = SCSOne(s1,s2,n-1,m);
	for(string &str : top)
		str.PB(s1[n-1]);
	VS left = SCSOne(s1,s2,n,m-1);
	for(string &str : left)
		str.PB(s2[m-1]);
	top.insert(top.end(),ALL(left));
	return top;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	string s1,s2;
	cin>>s1>>s2;
	SCS(s1,s2,n,m);
	VS ans=SCSOne(s1,s2,n,m);
	for(string str : ans)
		cout<<str<<endl;
	return 0;
}
