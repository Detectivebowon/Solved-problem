#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[30];
vector<char> ans;
bool visited[30][30];
void dfs(int u,int cnt)
{
    if(ans.size()==n+1)
    {
        for(auto v:ans)
            cout<<v<<" ";
        exit(0);
    }
    for(auto v:adj[u])
    {
        if(visited[u][v]||visited[v][u]) continue;
        visited[u][v]=visited[v][u]=true;
        cnt++;
        ans.emplace_back(v+'A');
        dfs(v,cnt);
        visited[u][v]=visited[v][u]=false;
        ans.pop_back();
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int u=s[0]-'A';
        int v=s[1]-'A';
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i=0;i<=('Z'-'A');i++)
    {
        if(adj[i].size()%2==1)
        {
            ans.emplace_back(i+'A');
            dfs(i,0);
        }
    }
    for(int i=0;i<=('Z'-'A');i++)
    {
        if(adj[i].size()%2==0)
        {
            ans.emplace_back(i+'A');
            dfs(i,0);
        }
    }
}