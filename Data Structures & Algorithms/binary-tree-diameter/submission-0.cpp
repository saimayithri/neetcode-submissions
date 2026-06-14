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
    int helper(TreeNode *root, int &maxDia){
        if(root==nullptr){return 0;}
        
        {
            int leftDepth=helper(root->left, maxDia);
            int rightDepth=helper(root->right, maxDia);
            maxDia=max(maxDia,leftDepth+rightDepth);
            return max(leftDepth, rightDepth) + 1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0;
        helper(root, maxDia);
        return maxDia;
        
    }
};
