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
    pair<int,bool> Balanced(TreeNode* root)
    {
        if(root==NULL)return {0,true};
        pair<int,bool> p1=Balanced(root->left);
        pair<int,bool>p2=Balanced(root->right);
        if(!p1.second||!p2.second)return {false,-1};
        if(abs(p1.first-p2.first)<=1){
           return {max(p1.first,p2.first)+1,true}; 
        }
        return {-1,false};
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool>x=Balanced(root);
        cout<<x.first<<endl;
        return x.second;
    }
};