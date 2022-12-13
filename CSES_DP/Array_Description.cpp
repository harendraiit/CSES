// good question
// have to think about the intuition again
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    long long a, b;
    cin>>a>>b;
    long long c[a];
    for(int i = 0;i<a;i++) cin>>c[i];
    long long d[a][b];
 
        for(long long j = 0;j<b;j++)
        {
             if(c[0] == 0 || c[0] == j+1)  d[0][j] = 1;
             else d[0][j] = 0;
        }
 
    for(long long i = 1;i<a;i++)
    {
        for(long long j = 0;j<b;j++)
        {
             if(c[i] == 0 || c[i] == j+1)  {d[i][j] = d[i-1][j];
             if(j!=0) d[i][j] = (d[i-1][j-1]%mod + d[i][j]%mod)%mod;
             if(j!= b-1) d[i][j] = (d[i-1][j+1]%mod + d[i][j]%mod)%mod;}
             else d[i][j] = 0;
        }
    }
     long long ans = 0;
     for(long long j = 0;j<b;j++)
     {
        ans=(ans%mod + d[a-1][j]%mod)%mod;
     }
 
 
     cout<<ans<<"\n";
 
 
 
}