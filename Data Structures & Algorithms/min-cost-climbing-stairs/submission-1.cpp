class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0],cost[1]);
        
        int prev1=0,prev2=0;
        for(int i=2;i<=n;i++)
        {
            int temp=min(cost[i-1]+prev1,cost[i-2]+prev2);
            prev2=prev1;

            prev1=temp;
        }
        return prev1;

        
    }
};
