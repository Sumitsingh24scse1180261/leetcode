class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int x : stones) {
            total += x;
        }
        int target = total / 2;
        vector<int> dp(target + 1, 0);
        for (int stone : stones) {
            for (int j = target; j >= stone; j--) {
                dp[j] = max(dp[j], stone + dp[j - stone]);
            }
        }
        return total - 2 * dp[target];
    }
};