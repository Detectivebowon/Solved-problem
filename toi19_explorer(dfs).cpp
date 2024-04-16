#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5 + 7,mod=1e9+7;
int n,child[N],ans=1,fac[N];
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    for(auto v:adj[u])
    {
        if(visited[v]) continue;
        visited[v]=true;
        child[u]++;
        dfs(v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    fac[0]=1,fac[1]=1;
    for(int i=2;i<=5e5;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    cin>>n;
    int u,v,st;
    cin>>u; st=u;
    for(int i=2;i<=(2*n-1);i++)
    {
        cin>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        u=v;
    }
    visited[st]=true;
    dfs(st);
    for(int i=1;i<=n;i++)
    {
        ans*=fac[child[i]];
        ans%=mod;
    }
    cout<<ans;
}