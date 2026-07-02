class Solution {
public:
    int helper(int i,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(i==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            return 1e9; 
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_take=helper(i-1,coins,amount,dp);
        int take=INT_MAX;
        if(amount>=coins[i]) take=1+helper(i,coins,amount-coins[i],dp);
        return dp[i][amount]=min(not_take,take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
       int ans= helper(n-1,coins,amount,dp);
       return (ans!=1e9)?ans:-1;

    }
};