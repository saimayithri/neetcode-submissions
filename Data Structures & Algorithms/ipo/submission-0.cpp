class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> p;
        for(int i = 0; i < profits.size(); i++){
            p.push_back({capital[i], profits[i]});
        }

        sort(p.begin(), p.end());
        priority_queue<int> maxHeap;

        int ptr = 0; 

        for(int i = 0; i < k; i++) {
            
            
            while(ptr < p.size() && p[ptr].first <= w) {
                maxHeap.push(p[ptr].second);
                ptr++; 
            }


            if(maxHeap.empty()){ break;}

            w+=maxHeap.top(); maxHeap.pop();
            
        }

        return w; 
    }
};