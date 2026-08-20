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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int prev = intervals[end];
        
        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(prev>intervals[i][start])return false;
            else{
                prev=intervals[i][end];
            }
        }
        return true;

    }
};
