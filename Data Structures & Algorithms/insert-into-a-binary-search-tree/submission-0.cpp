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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }

        TreeNode *traverse = root;
        TreeNode *prev = nullptr;


        while(traverse)
        {
            
            if(traverse->val < val )
            {
                prev=traverse;
                traverse=traverse->right;
            }
            else if(traverse->val > val )
            {
                prev=traverse;
                traverse=traverse->left;
            }

        }

        if (traverse==nullptr)
        {
            TreeNode *newNode=new TreeNode(val);
            if(prev->val > val)
            {
                prev->left=newNode;
            }
            else
            {
                prev->right=newNode;
            }
        }
        return root;
        
    }
};