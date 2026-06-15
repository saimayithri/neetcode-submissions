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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==nullptr){return {};}
        vector<vector<int>>res;
        queue<TreeNode *>q;

        //inital setup
        q.push(root);

        while(!q.empty())
        {
            int level=q.size();
            vector<int> levelAns;

            for(int i=0;i<level;i++)
            {
                TreeNode* ans=q.front(); 
                q.pop();
                levelAns.push_back(ans->val);
                if(ans->left!=nullptr){q.push(ans->left);}
                if(ans->right!=nullptr){q.push(ans->right);}

            }

            res.push_back(levelAns);
        }
        return res;
        
    }
};
