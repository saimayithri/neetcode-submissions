class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

bool dfs(int j, TrieNode* curr, string& word) {
       
        if (j == word.length()) {
            return curr->isWord;
        }
      
        char c = word[j];

     
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
               
                if (curr->children[i] != nullptr) {
                    
                    if (dfs(j + 1, curr->children[i], word) == true) {
                        return true;
                    }
                }
            }
    
            return false;
        } 
        
        else {
            int idx = c - 'a';
            
            
            if (curr->children[idx] == nullptr) {
                return false;
            }

            return dfs(j + 1, curr->children[idx], word);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }
};