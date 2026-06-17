class KthLargest {
public:
    int ki;priority_queue<int,vector<int>,greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
        ki=k;
        for (int num : nums) {
            add(num);
        }
        
    }
    
    int add(int val) {
        
        if(minHeap.size()<ki)
        {
            minHeap.push(val);
        }
        else if(minHeap.top()<val)
        {
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
        
    }
};
