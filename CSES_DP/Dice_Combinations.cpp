#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007
int dicecombo(vector<int>&dp,int n)
{
  if(n==0) return 1;
   //int ans = 0;
   if(dp[n]!=0) return dp[n];
   for(int i =1;i<=6;i++)
   {
    if(n-i>=0)
    dp[n] = dp[n] + dicecombo(dp,n-i);
    dp[n]%=mod;
   }
   return dp[n];
}
int main()
{
    int n ;
    cin>>n;
    vector<int>dp(n+1,0);
    //dp[0] = 1;
    cout<<dicecombo(dp,n);

}