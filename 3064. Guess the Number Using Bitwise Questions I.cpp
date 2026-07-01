/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int g = 1;
        int result = 0;

        for (int i = 0; i < 31; i++) {
            if (commonSetBits(g) == 1) {
                result += g;
            }
            g <<= 1;
        }

        return result;
    }
};
