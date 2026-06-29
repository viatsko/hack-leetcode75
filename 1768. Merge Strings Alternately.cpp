class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1p = 0;
        int word2p = 0;

        std::string result;
        result.reserve(word1.size() + word2.size());

        while (word1p < word1.size() || word2p < word2.size()) {
            if (word1p < word1.size()) {
                result += word1[word1p++];
            }
            if (word2p < word2.size()) {
                result += word2[word2p++];
            }
        }

        return result;
    }
};
