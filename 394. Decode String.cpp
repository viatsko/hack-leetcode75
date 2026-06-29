class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(const string &s, int &i) {
        string result = "";
        int mult = 0;

        while (i < s.size()) {
            auto & ch = s[i];
            i++;

            if (isdigit(ch)) {
                mult = mult * 10 + ch - '0';
            } else if (ch == '[') {
                string ret = decode(s, i);
                for (int j = 0; j < mult; j++) {
                    result += ret;
                }
                mult = 0;
            } else if (ch == ']') {
                return result;
            } else {
                result += ch;
            }
        }
        cout << result << endl;
        return result;
    }
};
