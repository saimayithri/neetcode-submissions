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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *traverse=root;
        while(traverse!=nullptr)
        {
            if(p->val<traverse->val && q->val< traverse->val){
                traverse=traverse->left;
            }
            else if(p->val > traverse->val && q->val > traverse->val){
                traverse=traverse->right;
            }
            else 
            {
                return traverse;
            }
        }
        
    }
};
