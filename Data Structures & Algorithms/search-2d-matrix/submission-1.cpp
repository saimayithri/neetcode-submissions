class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int l=0; int r=matrix[0].size()-1;

        int n=0;int row=0;

        while(n<=matrix.size()-1)
        {
            if(target>=matrix[n][l]&&target<=matrix[n][r])
            {
                row =n;
                break;
            }
            else
            {
                n++;
            }
        }

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target==matrix[row][mid])
            {
                return true;
            }
            else
            {
                if(target>matrix[row][mid])
                {
                    l=mid+1;
                }
                else if(target<matrix[row][mid])
                {
                    r=mid-1;
                }
            }
        }
        return false;



       
        
    }
};
