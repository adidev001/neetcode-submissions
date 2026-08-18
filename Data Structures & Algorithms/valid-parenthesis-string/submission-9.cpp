class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min_open++;
                max_open++;
            } else if (s[i] == ')') {
                min_open--;
                max_open--;
            } else if (s[i] == '*') {
                min_open--; 
                max_open++; 
            }

            if (max_open < 0) {
                return false;
            }
            
            if (min_open < 0) {
                min_open = 0;
            }
        }

        return min_open == 0;
    }
};