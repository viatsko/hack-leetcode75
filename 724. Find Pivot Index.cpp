class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (auto & num: nums) {
            total += num;
        }
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto & num = nums[i];
            total -= num;
            if (left == total) {
                return i;
            }
            left += num;
        }

        return -1;
    }
};
