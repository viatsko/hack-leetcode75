class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double runsum = 0;
        double result = -DBL_MAX;

        for (int i = 0; i < nums.size(); i++) {
            runsum += nums[i];

            if (i >= k - 1) {
                result = max(runsum / k, result);
                runsum -= nums[i - k + 1];
            }
        }

        return result;
    }
};
