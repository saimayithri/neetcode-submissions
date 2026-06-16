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
    int helper(TreeNode* root, int &maxVal)
    {
        if(root==nullptr){return 0;}
        
        int leftSum=max(0,helper(root->left,maxVal));
        int rightSum=max(0,helper(root->right,maxVal));

        maxVal = max(maxVal, leftSum + rightSum + root->val);
        return (max(leftSum, rightSum) + root->val);

    }
    int maxPathSum(TreeNode* root) {
        int maxVal=INT_MIN;
        helper(root,maxVal);
        return maxVal;
    }
};
