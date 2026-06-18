#include <vector>

class Solution {
public:
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
     
        vector<int> stops(1001, 0);
        
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            stops[from]+=numPassengers;
            stops[to]-=numPassengers;

        
        }
   
        int currentPassengers = 0;
        for (int i = 0; i <= 1000; i++) {
            currentPassengers+=stops[i];
            if(currentPassengers>capacity)
            {
                return false;
            }
            
        }

        return true;
    }
};