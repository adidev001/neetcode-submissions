/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
         sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x.start < y.start;
        });
        int n=intervals.size();
        int count=1;
        priority_queue<int ,vector<int>,greater<int>>min_heap;
        if (intervals.empty()) return 0;
        min_heap.push(intervals[0].end);
        for(int i=1;i<n;i++){
            if(intervals[i].start>=min_heap.top()){
                min_heap.pop();
                min_heap.push(intervals[i].end);
            }
            else{
                min_heap.push(intervals[i].end);
            }

        }
        return min_heap.size();
    }
};
