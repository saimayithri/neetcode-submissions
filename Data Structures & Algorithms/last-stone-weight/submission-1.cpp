class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>maxHeap;
        for(int num:stones){
            maxHeap.push(num);
        }

        while(maxHeap.size()>1)
        {
            int y=maxHeap.top();
            maxHeap.pop();
            int x=maxHeap.top();
            maxHeap.pop(); 

            if(y-x>0)
            {
                maxHeap.push(y-x);
            }  

        }
        int ans=0;
        if(maxHeap.size()>0)
        {
            ans=maxHeap.top();
        }
        
        return ans;
        
    }
};
