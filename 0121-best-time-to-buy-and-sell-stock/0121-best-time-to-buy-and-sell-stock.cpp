class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;            // Kuch nahi kharida
        dp[0][1] = -prices[0];   // Aaj stock kharid liya
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(
                dp[i - 1][0],              // Kuch nahi kiya
                dp[i - 1][1] + prices[i]  // Stock sell kiya
            );
            dp[i][1] = max(
                dp[i - 1][1],  // Pehle se stock hai
                -prices[i]     // Aaj stock kharida
            );
        }
        return dp[n - 1][0];
    }
};