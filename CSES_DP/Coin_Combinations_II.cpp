#include<bits/stdc++.h>
# define ll long long
# define mod 1000000007
using namespace std;
int main()
{
    ll n,x;
    cin>>n>>x;
    ll coins[n];
    for(int i = 0;i<n;i++)
    {
      cin>>coins[i];
    }
    vector<ll>dp(x+1,0);
    dp[0] = 1;
    for(int i =0;i<n;i++)
    {
        for(int j =1;j<=x;j++)
        {
            if(coins[i]>j) continue;
            dp[j] = dp[j]+dp[j-coins[i]];
            dp[j]%=mod;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}