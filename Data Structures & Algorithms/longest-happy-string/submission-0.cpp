class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string res = "";
        while (!pq.empty()) {
            auto current = pq.top(); pq.pop();
            int n = res.size();

            if (n >= 2 && res[n-1] == res[n-2] && res[n-1] == current.second) {
                if (pq.empty()) {
                    break;
                }

                char buffer = pq.top().second;
                int freq = pq.top().first;
                pq.pop();

                res += buffer; 

                if (freq - 1 > 0) {
                    pq.push({freq - 1, buffer});
                }
                pq.push(current); 

            } else {
                char c = current.second;
                int f = current.first;

                res += c;
                if (f - 1 > 0) { 
                    pq.push({f - 1, c});
                }
            }
        }
        return res;
    }
};