class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sm[26];
        
        for  (int i = 0; i < s.size(); i++) {
            sm[s[i] - 'a'] = i;
        }

        int result = 0;
        for (int i = 0; i < t.size(); i++) {
            result += abs(i - sm[t[i] - 'a']);
        }
        return result;
    }
};
