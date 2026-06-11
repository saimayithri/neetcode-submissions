class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

       
        int l=0, r= arr.size()-1;

        while((r-l+1) !=k)
        {
            if (abs(arr[r]-x)<abs(arr[l]-x))
            {
                l++;

            }
            else
            {
                r--;
            }            
        }

        return vector<int>(arr.begin()+l,arr.begin()+r+1);
        


        
        
    }
};