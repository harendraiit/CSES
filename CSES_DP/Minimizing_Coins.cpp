#include<bits/stdc++.h>
using namespace std;
# define ll long long 
# define mod 1000000007
int main()
{
   int n,x;
   cin>>n>>x;
   int coins[n];
   for(int i =0;i<n;i++)
   {
    cin>>coins[i];
   } 
   vector<ll>dp(x+1,INT_MAX);
   dp[0] = 0;
   for(int i =1;i<=x;i++)
   {
    for(int j = 0;j<n;j++)
    {
        if(coins[j]>i) continue;
        else
        dp[i] = min(dp[i],1+dp[i-coins[j]]);
    }
   }
   if(dp[x]==INT_MAX) cout<<-1<<endl;
   else cout<<dp[x] ;
   return 0;
}