class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int x = INT_MAX;
        int y = INT_MAX;

        for (auto num: nums) {
            if (num <= x) {
                x = num;
            } else if (num <= y) {
                y = num;
            } else {
                return true;
            }
        }

        return false;
    }
};
