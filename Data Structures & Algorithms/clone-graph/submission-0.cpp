class Solution {
private:
    // Maps original Node* to cloned Node*
    unordered_map<Node*, Node*> oldToNew;

public:
    Node* cloneGraph(Node* node) {
        // Base case: If the input graph is completely empty
        if (node == nullptr) return nullptr;
        
        // 1. If 'node' is already in the map, return its clone
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }
        
        // 2. Create the clone
        Node* clone = new Node(node->val);
        
        // 3. Save it to the map BEFORE traversing neighbors
        oldToNew[node] = clone;
        
        // 4. Loop through the original node's neighbors
        for (Node* neighbor : node->neighbors) {
            // Recursively clone the neighbor, and add it to our clone's neighbors list
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        
        // 5. Return the fully built clone
        return clone;
    }
};