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
        int n = intervals.size();
        vector<int>starts(n); vector<int> ends(n);
        for(int i=0; i<n; i++){
            starts[i]=intervals[i].start;
            ends[i]=intervals[i].end;

        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int s=0, e=0; int rooms=0; int maxRooms=0;

        while(s<n){
            if(starts[s]<ends[e]){
                rooms++;
                s++;
            }
            else{
                e++;
                rooms--;
            }
            maxRooms=max(rooms, maxRooms);
        }
        return maxRooms;

    }
};
