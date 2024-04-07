#include<bits/stdc++.h>
using namespace std;
bool dp[267][267][3];//n n checkstatus
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int num=20;
    while(num--)
    {
        memset(dp,false,sizeof(dp));
        int n;
        string str;
        cin>>n>>str;
        str=" "+str;
        for(int i=1;i<=n;i++)
            dp[i][i][str[i]-'0']=true;
        for(int len=2;len<=n;len++)
        {
            for(int l=1,r=len;r<=n;l++,r++)
            {
                for(int i=l;i<r;i++)
                {
                    if(dp[l][i][0]&&dp[i+1][r][0]) dp[l][r][2]=true;
                    if(dp[l][i][0]&&dp[i+1][r][1]) dp[l][r][1]=true;
                    if(dp[l][i][0]&&dp[i+1][r][2]) dp[l][r][0]=true;
                    if(dp[l][i][1]&&dp[i+1][r][0]) dp[l][r][2]=true;
                    if(dp[l][i][1]&&dp[i+1][r][1]) dp[l][r][1]=true;
                    if(dp[l][i][1]&&dp[i+1][r][2]) dp[l][r][1]=true;
                    if(dp[l][i][2]&&dp[i+1][r][0]) dp[l][r][1]=true;
                    if(dp[l][i][2]&&dp[i+1][r][1]) dp[l][r][2]=true;
                    if(dp[l][i][2]&&dp[i+1][r][2]) dp[l][r][1]=true;
                }
            }
        }
        if(dp[1][n][0])
            cout<<"yes\n";
        else 
            cout<<"no\n";
    }
}