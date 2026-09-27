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
    bool Validate(TreeNode* root, long long minBound, long long maxBound){
        if(root==nullptr){
            return true;
        }
        if(root->val<=minBound || root->val>=maxBound ){
            return false;
        }
        return Validate(root->left,minBound, root->val) && Validate(root->right, root->val, maxBound);
    }
    bool isValidBST(TreeNode* root) {
        return Validate(root, LONG_MIN, LONG_MAX);
        
    }
};
