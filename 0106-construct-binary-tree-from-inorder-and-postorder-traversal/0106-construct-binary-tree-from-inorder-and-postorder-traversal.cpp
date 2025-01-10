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
    TreeNode* Tree(vector<int>&inorder,vector<int>& postorder,int& index,unordered_map<int,int>&m,int instart,int inend,int n){
        if(index<0 ||instart>inend)return NULL;
        TreeNode* root=new TreeNode(postorder[index--]);
        int pos=m[root->val];
        root->right=Tree(inorder,postorder,index,m,pos+1,inend,n);
        root->left=Tree(inorder,postorder,index,m,instart,pos-1,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        int index=n-1;
        return Tree(inorder,postorder,index,m,0,n-1,n);
    }
};