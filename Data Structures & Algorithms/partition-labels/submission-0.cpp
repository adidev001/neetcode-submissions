class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char , int > map;

        for (int i = 0; i < s.length(); i++) {
             map[s[i]] = i;
            }
        vector<int>res;
        for(int i=0;i<n;i++){
            int start =0;
            int end=0;
            end= max(end,map[s[i]]);

            if(i==end){
                res.push_back(end-start+1);
                start=i+1;
                end=i+1;
            }
        }
        return res;
    }
};
