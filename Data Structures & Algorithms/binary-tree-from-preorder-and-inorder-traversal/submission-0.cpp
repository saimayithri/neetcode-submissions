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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& pre_idx, int in_left, int in_right){
        if(in_left>in_right)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_idx]); pre_idx++;
        int i;
        for(i=in_left;i<=in_right;i++)
        {
            if(inorder[i]==root->val)
            {
                break;
            }
        }
        int mid=i;
        root->left=helper(preorder,inorder,pre_idx,in_left,mid-1);
        root->right=helper(preorder,inorder,pre_idx,mid+1,in_right);
        return root;
        

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx = 0;
        return helper(preorder, inorder, pre_idx ,0,inorder.size()-1);
        
    }
};
