class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }
        int m = squares.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(m, n, squares, dp);
    }
    int helper(int i, int n, vector<int>& squares,
               vector<vector<int>>& dp) {
        if (n == 0)
            return 0;
        if (i == 0)
            return INT_MAX;
        if (dp[i][n] != -1)
            return dp[i][n];
        int skip = helper(i - 1, n, squares, dp);
        int take = INT_MAX;
        if (squares[i - 1] <= n) {
            int cal = helper(i, n - squares[i - 1],
                             squares, dp);
            if (cal != INT_MAX)
                take = 1 + cal;
        }
        return dp[i][n] = min(take, skip);
    }
};