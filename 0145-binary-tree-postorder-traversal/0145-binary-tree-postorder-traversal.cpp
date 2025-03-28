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
    vector<int> onestackSolution(TreeNode* root){
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
    vector<int> twostackSoution(TreeNode* root){
        if(root==NULL)return {};
        stack<TreeNode*> st1,st2;
        st1.push(root);
        vector<int>ans;
        while(!st1.empty()){
            TreeNode* tem=st1.top();
            st1.pop();
            st2.push(tem);
            if(tem->left)st1.push(tem->left);
            if(tem->right) st1.push(tem->right);
        }
        while(!st2.empty()){
            int x=st2.top()->val;
            st2.pop();
            ans.push_back(x);
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode* root) {
      return  twostackSoution(root);
    }
};