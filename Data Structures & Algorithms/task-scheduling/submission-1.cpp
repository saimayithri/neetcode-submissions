class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char task : tasks) {
            counts[task]++;
        }
        
        priority_queue<int> maxHeap;
        for (auto const& pair : counts) {
            maxHeap.push(pair.second);
        }
        
        queue<pair<int, int>> cooldown;
        int time = 0;
        
        while (!maxHeap.empty() || !cooldown.empty()) {
            time++; 
            
            if (!maxHeap.empty()) {
                int temp = maxHeap.top() - 1;
                maxHeap.pop(); 
                
                if (temp > 0) {
                    cooldown.push({temp, time + n}); 
                }
            }
                
           
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first); 
                cooldown.pop(); 
            }
        }
        
        return time;
    }
};