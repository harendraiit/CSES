#include<bits/stdc++.h>
using namespace std;
vector<int> getdigits(int n)
{
    vector<int>result;
    while(n)
    {
        if(n%10!=0)
        {
         result.push_back(n%10);
        } 
        n/=10;
    }
    return result;
}
int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    for(int i =1;i<=9;i++) dp[i] = 1;
    for(int i =10;i<=n;i++)
    {
        vector<int> digits = getdigits(i); 
      for(int j =0;j<digits.size();j++)
      {
        dp[i] = min(dp[i],1+dp[i-digits[j]]);
      }
    }
    cout<<dp[n]<<endl;;
    return 0;
}