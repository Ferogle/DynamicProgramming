//solution to the question 510B
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
string g[51];
int vis[51][51]={{0}};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void DFS(int v1,int v2,int sv1,int sv2,char scolor)
{
	if(v1<0 || v2<0 || v1>=n || v2>=m || g[v1][v2]!=scolor)
		return;
	if(vis[v1][v2])
	{
		cout<<"Yes"<<endl;
		exit(0);
	}
	vis[v1][v2]=1;
	for(int i=0;i<4;i++)
	{
		int nextX=v1+dx[i];
		int nextY=v2+dy[i];
		if(sv1!=nextX || sv2!=nextY)
			DFS(nextX,nextY,v1,v2,scolor);
	}


}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>g[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j])
			{
				DFS(i,j,-1,-1,g[i][j]);
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
