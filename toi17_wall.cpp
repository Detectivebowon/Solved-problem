#include<bits/stdc++.h>
using namespace std;
const int N=1e3 +7;
int r,c,ans=INT_MIN;
char space[N][N];
bool visited[N][N],visitedx[N][N];
queue<pair<int,int>> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin>>space[i][j];
    //check outside
    q.push({1,1});
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
            {
                if(i==-1&&j==-1) continue;
                if(i==-1&&j==1) continue;
                if(i==1&&j==-1) continue;
                if(i==1&&j==1) continue;
                int xi=x+i;
                int yj=y+j;
                if(xi<1||yj<1||xi>r||yj>c) continue;
                if(visited[xi][yj]||space[xi][yj]=='X') continue;
                visited[xi][yj]=true;
                q.push({xi,yj});
            }
    }
    // check outside end
    // flood fill cnt
    for(int row=1;row<=r;row++)
        for(int cl=1;cl<=c;cl++)
        {
            if(visitedx[row][cl]||space[row][cl]=='.') continue;
            visitedx[row][cl]=true;
            q.push({row,cl});
            int cnt=0;
            while(!q.empty())
            {
                auto [x,y]=q.front();
                q.pop();
                for(int i=-1;i<=1;i++)
                    for(int j=-1;j<=1;j++)
                    {
                        if(i==-1&&j==-1) continue;
                        if(i==-1&&j==1) continue;
                        if(i==1&&j==-1) continue;
                        if(i==1&&j==1) continue;
                        int xi=x+i;
                        int yj=y+j;
                        if(xi<1||yj<1||xi>r||yj>c) continue;
                        if(visitedx[xi][yj]) continue;
                        if(space[xi][yj]=='.'&&visited[xi][yj])
                        {
                            // cout<<xi<<" "<<yj<<"\n";
                            cnt+=1;
                        }
                        if(space[xi][yj]=='X')
                        {
                            q.push({xi,yj});
                            visitedx[xi][yj]=true;
                        }
                    }
            }
            // cout<<"cnt "<<cnt<<"\n";
            ans=max(ans,cnt);
        }
        // flood fill cnt end
    cout<<ans;
}
/*
4 6
......
.X.X..
.X.XX.
......
*/
/*
5 5
.....
..X..
.X.X.
..X..
.....
*/
/*
4 6
......
.X.X..
..X.X.
......
*/
// 5 5
// . . . . .
// . . X . . 
// . X X X .
// . . X . .
// . . . . .
// 7 7
// . . . . . . .
// . X X X . X .
// . . . X . X .
// . X X X X X .
// . X . x . . .
// . X . X X X .
// . . . . . . .
// 27