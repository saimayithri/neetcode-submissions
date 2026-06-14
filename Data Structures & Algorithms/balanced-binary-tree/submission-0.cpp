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
    int helper(TreeNode *root)
    {
        if(root==nullptr){return 0;}
        int leftH = helper(root->left);
        int rightH = helper(root->right);
        if (leftH==-1 ||rightH==-1 || abs(leftH-rightH)>1)
        {
            return -1;
        }
        else
        {
            return max(leftH,rightH)+1;
        }
 


    }
    
    bool isBalanced(TreeNode* root) {
        int ans =helper(root);
        if(ans==-1)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
};
