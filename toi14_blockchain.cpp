#include<bits/stdc++.h>
using namespace std;
int b,q;
vector<pair<int,int>> bc[1007];
vector<pair<int,int>> ask[1007];
map<vector<pair<int,int>>,int> cnt;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>b>>q;//have ask
    for(int i=1;i<=b;i++)
    {
        int n;
        cin>>n;
        for(int j=1;j<n;j++)
        {
            int u,v;
            cin>>u>>v;
            bc[i].emplace_back(min(u,v),max(u,v));
        }
        sort(bc[i].begin(),bc[i].end());
        cnt[bc[i]]++;
    }
    for(int i=1;i<=q;i++)
    {
        int n;
        cin>>n;
        for(int j=1;j<n;j++)
        {
            int u,v;
            cin>>u>>v;
            ask[i].emplace_back(min(u,v),max(u,v));
        }
        sort(ask[i].begin(),ask[i].end());
        cout<<cnt[ask[i]]<<"\n";
    }
}