class Solution {
public:
    void backtrack(string& s, int index, unordered_set<string>& dict, vector<string>& current, vector<string>& result) {
        // 1. BASE CASE: We successfully sliced the whole string
        if (index == s.length()) {
            string sentence = "";
            // Join all words in our backpack with a space
            for (int i = 0; i < current.size(); i++) {
                sentence += current[i];
                if (i != current.size() - 1) {
                    sentence += " "; // Add space between words
                }
            }
            result.push_back(sentence);
            return;
        }

        // 2. ITERATE and SLICE
        for (int i = index; i < s.length(); i++) {
            // Cut the piece
            string piece = s.substr(index, i - index + 1);
            
            // 3. CONSTRAINT: Is this piece in our dictionary?
            // .count() is O(1) time for unordered_set!
            if (dict.count(piece)) {
                // DO
                current.push_back(piece);
                
                // EXPLORE (Move to i + 1, exactly like you wrote!)
                backtrack(s, i + 1, dict, current, result);
                
                // UNDO
                current.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<string> current;
        
        // OPTIMIZATION: Convert the vector into an unordered_set for O(1) lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        backtrack(s, 0, dict, current, result);
        return result;
    }
};