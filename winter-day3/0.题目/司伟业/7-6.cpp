#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define int long long
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

struct node{
	int a,b,c;
}g[maxn];
int n,m,f[maxn],ans,tot;

bool cmp(node a,node b)
{
	return a.c<b.c;
}

int fi(int x)
{
	if(f[x]!=x) f[x]=fi(f[x]);
	return f[x];
}

signed main()
{
	while(cin>>n>>m)
	{
		ans=0;tot=0;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		{
			g[i].a=read();g[i].b=read();g[i].c=read();
		}
		sort(g+1,g+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int u=g[i].a,v=g[i].b;
			if(fi(u)==fi(v)) continue;
			tot++;
			f[fi(u)]=fi(v);
			ans+=g[i].c;
		}
		if(tot==n-1) cout<<ans<<endl;
		else puts("There is no minimum spanning tree.");
	}
	return 0;
} 
