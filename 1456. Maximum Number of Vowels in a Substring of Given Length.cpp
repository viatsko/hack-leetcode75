class Solution {
public:
    int isvowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ? 1 : 0;
    }

    int maxVowels(string s, int k) {
        int vowels = 0;
        int result = 0;

        for (int i = 0; i < size(s); i++) {
            vowels += isvowel(s[i]);
            
            if (i >= k -1) {
                result = max(result, vowels);
                vowels -= isvowel(s[i - k + 1]);
            }
        }

        return result;
    }
};
