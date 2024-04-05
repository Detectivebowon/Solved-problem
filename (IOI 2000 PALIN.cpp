#include<bits/stdc++.h>
using namespace std;
int n,dp[5007][5007];
string str;
int main()
{
    cin>>n;
    cin>>str;
    string restr=str;
    reverse(restr.begin(),restr.end());
    str=" "+str;
    restr=" "+restr;
    for(int i=1;i<str.size();i++)
        for(int j=1;j<restr.size();j++)
        {
            if(str[i]==restr[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    cout<<n-dp[str.size()-1][str.size()-1];
    // int ans=(str.size()-1)-dp[str.size()-1][str.size()-1];
    // cout<<ans;
}