class Solution {
public:
    int maxDistinct(string s) {
        bitset<26> bs;
        int result = 0;
        for (auto & ch : s) {
            if (!bs[ch - 'a']) {
                bs[ch - 'a'] = 1;
                result++;
            }
        }
        return result;
    }
};
