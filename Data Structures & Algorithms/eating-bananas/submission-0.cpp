class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1; int right = *max_element(piles.begin(),piles.end());

        int answer=right;
        while(left<=right)
        {

            int mid=(left+right)/2;
            int totalhours=0;
            for(int pile:piles)
            {
                totalhours+=ceil(pile/(double)mid);

            }

            if(totalhours<=h)
            {
                answer=mid;
                right=mid-1;
            }
            else
                left=mid+1;

        }
        return answer;



        
    }
};
