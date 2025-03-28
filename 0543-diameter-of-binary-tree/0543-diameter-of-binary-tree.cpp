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
    //first ->diameter
    //second-> height
    pair<int,int> diameter(TreeNode* root){
        if(root==NULL)return {0,0}; 
        pair<int,int>l=diameter(root->left);
        pair<int,int>r=diameter(root->right);
        int maxheight=max(l.second,r.second)+1;
        int maxdia=max({l.first,r.first,l.second+r.second+1});
        return {maxdia,maxheight};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first-1;
    }
};