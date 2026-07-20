/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){return "N,";}
        string s=to_string(root->val)+",";
        s+=serialize(root->left);
        s+=serialize(root->right);

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue <string>q;
        string temp="";
        for(char c: data){
            if(c==','){
                q.push(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        return buildtree(q);
        
    }
    TreeNode * buildtree(queue<string> &q){
        string s=q.front();
        q.pop();

        if(s=="N"){
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(s));
        node->left=buildtree(q);
        node->right=buildtree(q);

        return node;

    }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));