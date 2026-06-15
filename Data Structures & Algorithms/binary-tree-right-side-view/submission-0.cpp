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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){return {};}
        vector<int>res;

        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty())
        {
            int level = q.size();
            for(int i=0;i<level;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left!=nullptr){q.push(node->left);}
                if(node->right!=nullptr){q.push(node->right);}
                if(i==level-1){
                    res.push_back(node->val);
                }

            }
           
        }
        return res;
    }
};
