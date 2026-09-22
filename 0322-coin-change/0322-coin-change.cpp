class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans=helper(n,amount,coins,dp);
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
    int helper(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(i==0) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount]; 
        int skip=helper(i-1,amount,coins,dp);
        int take=INT_MAX;
        if(coins[i-1]<=amount){
            int cal=helper(i,amount-coins[i-1],coins,dp);
            if(cal!=INT_MAX) take=1+cal;
        }
        return dp[i][amount]=min(take,skip);    
    }
};