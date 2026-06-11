class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int water=0,leftmax=0,rightmax=0;

        while(l<r)
        {
            leftmax=max(height[l],leftmax);
            rightmax=max(height[r],rightmax);
            
           
            if(leftmax<=rightmax)
            {
                water+=min(leftmax,rightmax)-height[l];
                l++;
            }
            else if(leftmax>rightmax)
            {
                water+=min(leftmax,rightmax)-height[r];
                r--;
            }           
        }

        return water;
      
    }
};
