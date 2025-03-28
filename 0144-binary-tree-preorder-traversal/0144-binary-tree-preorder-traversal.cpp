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
    // void PostOrder(TreeNode* root,vector<int>&ans)
    // {
    //     if(root==NULL)return;
    //     ans.push_back(root->val);
    //     PostOrder(root->left,ans);
    //     PostOrder(root->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
       //iterative
       stack<TreeNode*>st;
       st.push(root);
       vector<int>ans;
       while(!st.empty()){
        TreeNode* tem=st.top();
        st.pop();
        ans.push_back(tem->val);
        if(tem->right)st.push(tem->right);
        if(tem->left)st.push(tem->left);
       }
       return ans;
    }
};