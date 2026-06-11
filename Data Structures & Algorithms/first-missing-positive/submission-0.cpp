class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        set<int>st;

        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        

        int i=1;
        while(st.find(i)!=st.end())
        {
            i++;

            
        }
        return i;
        

        
        
    }
};