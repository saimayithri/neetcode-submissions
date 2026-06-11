class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int l=*max_element(weights.begin(),weights.end()),r=0; 
        
        for(int w:weights)
        {
            r+=w;
        }
        int ans=r;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int curr=0, daysneeded=1;
            for(int w:weights)
            {
                if(curr+w>mid)
                {
                    daysneeded++;curr=w;
                }
                else
                {
                    curr+=w;
                }
                
                
                

            }

            if(daysneeded<=days)
            {
                ans=mid;
                r=mid-1;

                
            }
            else
            {
                l=mid+1;
                
            }


            
        }
        return ans;




        
    }
};