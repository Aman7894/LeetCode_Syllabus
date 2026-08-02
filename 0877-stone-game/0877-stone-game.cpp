class Solution {
public:
    int helper(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i==j){
            return piles[i];
            
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int n_t=piles[i]-helper(i+1,j,piles,dp);
        int t=piles[j]-helper(i,j-1,piles,dp);

        return dp[i][j]=max(n_t,t);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int> (n));
        int res=helper(0,n-1,piles,dp);
        if(res>=0) return true;
        return false;
    }
};