#include<bits/stdc++.h>
using namespace std;
int m,n,room[107],mx=INT_MIN;
bool check(int mid)
{
    int data=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(data+room[i]>mid)
        {
            cnt++;
            data=room[i];
        }
        else
        {
            data+=room[i];
        }
    }
    if(cnt>m)
        return false;
    else
        return true;
}
int main()
{
    cin>>m>>n;//internet room
    for(int i=1;i<=n;i++)
    {
        cin>>room[i];
        mx=max(room[i],mx);
    }
    int l=mx,r=1e7;
    while(l<r)
    {
        int mid=(l+r)/2;
        // cout<<l<<" "<<r<<" "<<mid<<"\n";
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l;
}