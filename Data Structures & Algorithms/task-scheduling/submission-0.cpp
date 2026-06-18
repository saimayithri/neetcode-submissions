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
            time++; // Clock ticks!
            
            // a. Do a task if we have one
            if (!maxHeap.empty()) {
                int temp = maxHeap.top() - 1;
                maxHeap.pop(); // FIXED: Remove it from heap!
                
                if (temp > 0) {
                    cooldown.push({temp, time + n}); // Go on break!
                }
            }
                
            // b. Check if anyone is done with their break
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first); // Let them back into the Heap
                cooldown.pop(); // Remove from queue
            }
        }
        
        return time;
    }
};