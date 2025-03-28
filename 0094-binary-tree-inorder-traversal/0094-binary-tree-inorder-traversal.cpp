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
    // void helper(TreeNode* root,vector<int> &ar){
    //     if(root==NULL)return ;
    //     helper(root->left,ar);
    //     ar.push_back(root->val);
    //     helper(root->right,ar);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        TreeNode*node=root;
        vector<int>ans;
        while(true){
           if(node!=NULL){
            st.push(node);
            node=node->left;
           } 
           else{
            if(st.empty())break;
            TreeNode* tem=st.top();
            st.pop();
            ans.push_back(tem->val);
            node=tem->right;
           }
        }
        return ans;
    }
};