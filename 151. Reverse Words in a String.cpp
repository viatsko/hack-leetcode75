class Solution {
public:
    string reverseWords(string s) {
        vector<string_view> words;
        for (auto word : s | views::split(' ')) {
            if (auto sv = string_view(word); !sv.empty()) {
                words.push_back(sv);
            }
        }

        string result;
        result.reserve(s.size());
        for (auto word : words | std::views::reverse) {
            result += word;
            result += ' ';
        }
        if (!result.empty()) result.pop_back();
        return result;
    }
};
