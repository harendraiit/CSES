#include <bits/stdc++.h>
# define mod 1000000007
using namespace std;

int canPartition(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return 0;
    
    else{
        int k = totSum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,0));
    
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        
        if(arr[0]<=k)
            dp[0][arr[0]] = 0;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                int notTaken = dp[ind-1][target];
        
                int taken = 0;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];
            
                dp[ind][target]= (notTaken%mod+taken%mod)%mod;
            }
        }
        
        return dp[n-1][k]%mod;

    } 
}

int main() {

   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i =0;i<n;i++)
   {
    arr[i] = i+1;
   }
                                 
  cout<<canPartition(n,arr);
    return 0;
}