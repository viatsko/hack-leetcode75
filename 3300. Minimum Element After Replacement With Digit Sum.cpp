class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (auto & num : nums) {
            int ds = 0;
            while (num > 0) {
                ds += num % 10;
                num /= 10;
            }
            result = min(result, ds);
        }
        return result;
    }
};
