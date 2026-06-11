class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        for(int num:nums)
        {
            freq[num]++;
        }
        priority_queue<pair<int,int>> maxheap;
        for(auto &pair:freq)
        {
            maxheap.push({pair.second,pair.first});
        }

        vector <int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(maxheap.top().second);
            maxheap.pop();

        }
        return ans;



        
        
    }
};
