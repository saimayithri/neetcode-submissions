class Solution {
public:
    int majorityElement(vector<int>& nums) {

        
        int candidate=nums[0];int freq=0;

        for(int i=0;i<nums.size();i++)
        {
            if(freq==0)
            {
                candidate=nums[i];
            }
            if(nums[i]==candidate)
            {
                freq++;
            }
            else
            {
                freq--;
            }
            
        
            
        }
        return candidate;
        
    }
};