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
        int n=intervals.size();
        if(n==0){return 0;}

        vector<int> start(n);
        vector<int> end(n);

        for(int i=0;i<n;i++){
            start[i]=intervals[i].start;
            end[i]=intervals[i].end;

        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int s=0, e=0;
        int currentRooms=0, maxRooms=0;

        while(s<n){
            if(start[s]<end[e]){
                currentRooms++;
                maxRooms=max(currentRooms, maxRooms);
                s++;
            }
            else if(start[s]>=end[e]){
                currentRooms--;
                e++;
            }
        }

        return maxRooms;
    }
};
