class Solution {
public:
    bool isPredecessor(string a, string b) {
        if (b.size() != a.size() + 1)
            return false;
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),  [](string a, string b) {
                 return a.size() < b.size();
             });
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};