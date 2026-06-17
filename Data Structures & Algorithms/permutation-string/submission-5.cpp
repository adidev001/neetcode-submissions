class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        if (len1 > len2) return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for (int i = 0; i < len1; i++) {
            count1[s1[i] - 'a']++;
        }

        int l = 0;
    for (int r = 0; r < len2; r++) {
            count2[s2[r] - 'a']++;

            if ((r - l + 1) > len1) {
                count2[s2[l] - 'a']--; 
                l++;
            }

            if ((r - l + 1) == len1) {
                if (count1 == count2) { 
                    return true;
                }
            }
        }

        return false;
    }
};