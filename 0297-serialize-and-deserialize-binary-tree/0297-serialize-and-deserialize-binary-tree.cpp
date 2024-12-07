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
        string ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tem=q.front();
            q.pop();
            if(tem==NULL){
                ans.append("# ");
            }
            else{
                ans.append(to_string(tem->val)+" ");
                q.push(tem->left);
                q.push(tem->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="# "||data.length()==0)return NULL;
        stringstream ss(data);
        string val;
        getline(ss,val,' ');
        TreeNode* root=new TreeNode(stoi(val));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tem=q.front();
            q.pop();
            getline(ss,val,' ');
            if(val=="#"){
                tem->left=NULL;
            }
            else{
                TreeNode* newnode=new TreeNode(stoi(val));
                tem->left=newnode;
                q.push(newnode);
            }
            getline(ss,val,' ');
            if(val=="#"){
                tem->right=NULL;
            }
            else{
                TreeNode* newnode=new TreeNode(stoi(val));
                tem->right=newnode;
                q.push(newnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));