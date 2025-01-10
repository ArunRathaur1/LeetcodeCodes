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
    void totalpath(vector<vector<int>>&ans,vector<int>ar,TreeNode* root,int targetsum,int sum){
        if(root==NULL)return;
        if(root->left==NULL&& root->right==NULL){
            ar.push_back(root->val);
            sum=sum+root->val;
            if(targetsum==sum){
                ans.push_back(ar);
            }
            return;
        }
        ar.push_back(root->val);
        totalpath(ans,ar,root->left,targetsum,sum+root->val);
        totalpath(ans,ar,root->right,targetsum,sum+root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>ar;
        totalpath(ans,ar,root,targetSum,0);
        return ans;
    }
};