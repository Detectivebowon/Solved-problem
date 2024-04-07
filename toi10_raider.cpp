#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
using namespace std;
int n,m,space[107][107];
queue<tuple<int,int,int>> q;
bool visited[107][107][1005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>space[i][j];
    int sx=(n+1)/2;
    // cout<<sx;
    // return 0;
    q.emplace(sx,0,0);
    while(!q.empty())
    {
        auto [x,y,cnt]=q.front();
        q.pop();
        // cout<<x<<" "<<y<<" "<<cnt<<"\n";
        if(x==sx&&y==m)
        {
            cout<<cnt;
            return 0;
        }
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
            {
                if(x%2==0)
                {
                    if(i==1&&j==1) continue;
                    if(i==-1&&j==1) continue;
                    if(i==0&&j==0) continue;
                }
                if(x%2==1)
                {
                    if(i==1&&j==-1) continue;
                    if(i==-1&&j==-1) continue;
                    if(i==0&&j==0) continue;
                }
                int xi=x+i;
                int yj=y+j;
                if(xi<1||yj<1||xi>n||yj>m) continue;
                if(space[xi][yj]==0) continue;
                if(visited[xi][yj][cnt+1]||(cnt+1)%space[xi][yj]!=0) continue;
                visited[xi][yj][cnt+1]=true;            
                q.emplace(xi,yj,cnt+1);
            }
    }
}