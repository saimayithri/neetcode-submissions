class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // 1. Initialize indegree to 0 for EVERY unique character in the words
        for (string& word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // 2. Build the Graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // Edge Case: Prefix contradiction (e.g., "zomato" before "zom")
            if (w1.length() > w2.length() && w1.substr(0, w2.length()) == w2) {
                return ""; 
            }

            // Find the first mismatch
            for (int j = 0; j < min(w1.length(), w2.length()); j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]); // Directed edge: w1[j] -> w2[j]
                    indegree[w2[j]]++;           // w2[j] has a prerequisite
                    break; // Stop after first mismatch!
                }
            }
        }

        // 3. Kahn's Algorithm Setup
        queue<char> q;
        for (auto& pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        string ans = "";

        // 4. THE BFS LOOP 
        while (!q.empty()) {
            // [YOUR CODE HERE]
            // 1. Get front character from queue, pop it.
            char a=q.front();
            q.pop();
            ans+=a;
            for(auto neighbor:adj[a]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
            // 2. Append it to 'ans'.
            // 3. Loop through its neighbors in 'adj'.
            // 4. Decrease neighbor's indegree by 1.
            // 5. If neighbor's indegree becomes 0, push to queue.
        }

        // 5. Cycle Check
        if (ans.length() != indegree.size()) {
            return ""; // Cycle detected!
        }

        return ans;
    }
};