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
//unordered_map<string,int> ump
int lookup[100][100]={{0}};
int dp[100][100]={{0}};

int SCS(string s1,string s2,int n,int m)
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
			{
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			lookup[i][j]=0;
	string s1,s2;
	cin>>s1>>s2;
	cout<<SCS(s1,s2,n,m)<<endl;
	return 0;
}

