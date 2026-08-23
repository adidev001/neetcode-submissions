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
        for(int i=0;i<n-1;i++){
            if(intervals[i].end>intervals[i+1].start)count++;

        }
        return count;
    }
};
