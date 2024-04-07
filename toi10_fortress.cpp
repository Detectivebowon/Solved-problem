#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int q=20;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if((a-2*b)<0||(a-2*b)%2==1||(4*b-a)<0||(4*b-a)%2==1)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<(4*b-a)/2+1<<"\n";
        }
    }
}