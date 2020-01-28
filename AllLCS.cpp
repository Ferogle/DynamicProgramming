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
vector<int>l;
vector<vector<int>>gph(100010);
int dp[100][100]={{0}};

VS LCSAll(char *s1,char *s2,int n,int m)
{
	if(n==0||m==0)
	{
		VS v(1);
		return v;
	}
	if(s1[n-1]==s2[m-1])
	{
		VS temp=LCSAll(s1,s2,n-1,m-1);
		for(string &str:temp)
			str.PB(s1[n-1]);
		return temp;
	}
	else
	{
		if(dp[n-1][m]>dp[n][m-1])
		{
			VS top = LCSAll(s1,s2,n-1,m);
			return top;
		}
		if(dp[n-1][m]<dp[n][m-1])
		{
			VS left = LCSAll(s1,s2,n,m-1);	
			return left;
		}
		VS top=LCSAll(s1,s2,n-1,m);
		VS left=LCSAll(s1,s2,n,m-1);
		top.insert(top.end(),ALL(left));
		return top;

	}
}

string LCS(char *s1,char *s2,int n,int m)
{
	if(n==0||m==0)
		return string("");
	if(s1[n-1]==s2[m-1])
	{
		string lcs=LCS(s1,s2,n-1,m-1)+s1[n-1];
		return lcs;
	}
	else
	{
		if(dp[n-1][m]>dp[n][m-1])
		{
			return LCS(s1,s2,n-1,m);
		}
		return LCS(s1,s2,n,m-1);
	}
}

int DP(char *s1,char*s2,int ln,int lm)
{
	for(int i=1;i<=ln;i++)
	{
		for(int j=1;j<=lm;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[ln][lm];
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	char s1[n],s2[m];
	cin>>s1>>s2;
	int len=DP(s1,s2,n,m);
	cout<<len<<endl;
	VS ans=LCSAll(s1,s2,n,m);
	for(string i:ans)
		cout<<i<<endl;
	return 0;
}
