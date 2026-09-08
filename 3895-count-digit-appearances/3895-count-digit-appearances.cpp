class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for (int num : nums) {
            while (num > 0) {
                int lastDigit = num % 10;
                if (lastDigit == digit) {
                    count++;
                }
                num = num / 10;
            }
        }
        return count;
    }
};