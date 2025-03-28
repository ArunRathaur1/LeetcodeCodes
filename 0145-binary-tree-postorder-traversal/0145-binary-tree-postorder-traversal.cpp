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
    void postOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        postOrder(root->left,ans);
        postOrder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st1;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* tem=st1.top();
            st1.pop();
            ans.push_back(tem->val);
            if(tem->left)st1.push(tem->left);
            if(tem->right)st1.push(tem->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};