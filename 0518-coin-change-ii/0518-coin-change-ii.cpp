class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return helper(n, amount, coins, dp);
    }
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int skip = helper(i - 1, amount, coins, dp);
        int take = 0;
        if (coins[i - 1] <= amount) {
            take = helper(i, amount - coins[i - 1], coins, dp);
        }
        return dp[i][amount] = take + skip;
    }
};