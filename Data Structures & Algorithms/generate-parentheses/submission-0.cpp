class Solution {
public:
    void bt(int n, string s, vector<string>& res, int oc, int cc) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        
        if (oc < n) {
            s.push_back('(');
            bt(n, s, res, oc + 1, cc);
            s.pop_back();
        }
        
        if (oc > cc) {
            s.push_back(')');
            bt(n, s, res, oc, cc + 1);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;
        
        bt(n, s, res, 0, 0);
        
        return res;
    }
};