#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        // Keep smashing as long as at least 2 stones remain
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop(); // Heaviest
            int x = pq.top(); pq.pop(); // Second heaviest

            if (y != x) {
                pq.push(y - x);
            }
        }

        // Return the remaining stone, or 0 if all stones were destroyed
        return pq.empty() ? 0 : pq.top();
    }
};