class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        int m = nums.size() / k;
        for (int i = 0; i < nums.size(); i += m) {
            reverse(nums.begin() + i, nums.begin() + i + m);
        }

        return nums;
    }
};
