#include<bits/stdc++.h>
using namespace std;
const int N=200007;
int n,m,k,bnn[N],ans;
vector<pair<int,int>> vec;
bool visited[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>bnn[i];
    for(int i=1;i<=k;i++)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        vec.emplace_back(tmp2,tmp1);
    }
    sort(vec.begin(),vec.end());
    int now;
    cin>>now;
    visited[now]=true;
    for(auto [h,t]:vec)
    {
        swap(visited[t],visited[t+1]);
        if(now-1==t)
            now--;
        else if(now==t)
            now++;
        visited[now-1]=visited[now]=visited[now+1]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i])
        {
            ans=max(ans,bnn[i]);
        }
    }
    cout<<ans<<"\n";
    if(ans==bnn[now]) cout<<"NO";
    else cout<<"USE";
}