class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removed = 0;
        int j = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == val) {
                removed++;
                continue;
            }
            nums[j++] = nums[i];
        }
        return size(nums) - removed;
    }
};
