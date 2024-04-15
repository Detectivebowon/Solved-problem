#include<bits/stdc++.h>
using namespace std;
const int mod=1e6+3;
int r,c,d,ncr[1507][1507],qs1[1507][1507],qs2[1507][1507],ans=0;
char space[1507][1507];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c>>d;
    for(int i=0;i<1507;i++)
        ncr[i][0]=ncr[i][i]=1;
    for(int i=1;i<1507;i++)
    {
        for(int j=1;j<=i&&j<=600;j++)
        {
            ncr[i][j]=(ncr[i-1][j]%mod+ncr[i-1][j-1]%mod)%mod;
        }
    }
    /////
    for(int i=601;i<=r+600;i++)
        for(int j=601;j<=c+600;j++)
        {
            cin>>space[i][j];
            if(space[i][j]=='#')
                qs1[i][j]=qs2[i][j]=1;
        }
    for(int i=1;i<1507;i++)
        for(int j=1;j<1507;j++)
        {
                qs1[i][j]+=qs1[i-1][j-1];//left
                qs2[i][j]+=qs2[i-1][j+1];//right
        }
    // for(int i=601;i<=r+600;i++)
    // {
    //     for(int j=601;j<=c+600;j++)
    //     {
    //             cout<<qs2[i][j]<<" "; 
    //     }
    //     cout<<"\n";
    // }
    for(int k=1;k<=(r+c);k++)
    {
        for(int i=601;i<=r+600;i++)
        {
            for(int j=601;j<=c+600;j++)
            {
                int cnt=0;
                cnt+=qs1[i+k-1][j-1]-qs1[i][j-k];
                cnt+=qs1[i-1][j+k-1]-qs1[i-k][j];
                cnt+=qs2[i+k][j]-qs2[i-1][j+1+k];
                cnt+=qs2[i][j-k]-qs2[i-1-k][j+1];
                if(cnt>=d)
                {
                    // cout<<i-600<<" "<<j-600<<"\n";
                    // cout<<cnt<<" "<<ncr[cnt][d]<<"\n";
                    ans+=ncr[cnt][d];
                    ans%=mod;
                }
            }
        }
    }
    cout<<ans;
}