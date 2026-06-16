/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){return "N,";}

        return to_string(root->val)+","+ serialize(root->left)+ serialize(root->right);
        
    }
    TreeNode* buildTree(queue<string> &q)
    {
        string val = q.front();
        q.pop();

        if(val=="N"){return nullptr;}
        TreeNode *root=new TreeNode(stoi(val));

        root->left=buildTree(q); 
        root->right=buildTree(q); 
        return root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue <string>q; 
        stringstream ss(data); string item;
        while(getline(ss,item,','))
        {
           q.push(item); 
        }
        return buildTree(q);
        
    }
};
