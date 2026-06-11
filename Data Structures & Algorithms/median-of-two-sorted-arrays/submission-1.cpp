class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>nums(n1+n2,0);
        for(int i=0;i<n1;i++)
        {
            nums[i]=nums1[i];
        }
        
        int k=0;
        for(int i=n1;i<n1+n2;i++)
        {
            nums[i]=nums2[k];k++;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());

        if((n1+n2)%2!=0)
        {
            return nums[n/2];
        }
        else
            return (nums[n/2]+nums[n/2-1])/2.0;
    
        
    }
};
