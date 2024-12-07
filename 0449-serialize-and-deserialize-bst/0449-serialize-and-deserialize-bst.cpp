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
   if(root==NULL){
    return "# ";
   }
   string ans="";
   queue<TreeNode*>q;
   q.push(root);
   while (!q.empty())
   {
        TreeNode* p=q.front();
        q.pop();
                if (p == nullptr) {
                ans += "# ";
            } else {
                ans += to_string(p->val) + " ";
                q.push(p->left);
                q.push(p->right);
            }

   }
   return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
          if(s.empty()||s=="# ")return NULL;
    stringstream ss(s);
    string g;
    getline(ss,g,' ');
    TreeNode* root=new TreeNode(stoi(g));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* p=q.front();
        q.pop();
        if(getline(ss,g,' ')){
        if(g=="#"){
            p->left=NULL;
        }
        else{
            TreeNode* tem=new TreeNode(stoi(g));
            p->left=tem;
            q.push(tem);
        }}
        if(getline(ss,g,' '))
        {
         if(g=="#"){
            p->right=NULL;
        }
        else{
            TreeNode* tem=new TreeNode(stoi(g));
            p->right=tem;
            q.push(tem);
        }}
    }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;