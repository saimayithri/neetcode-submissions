#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_set <int>a;
       for(int i:nums)
       {
            if(a.find(i)!=a.end())
            {
                return true;
            }
            a.insert(i); 
       }

        return false; 
    }
};
