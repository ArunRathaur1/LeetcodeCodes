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
    TreeNode* Tree(vector<int>&preorder,vector<int>& inorder,unordered_map<int,int>&m,int instart,int inend,int &preindex,int n){
       if(preindex>=n||instart>inend)return NULL;
       TreeNode* root=new TreeNode(preorder[preindex++]);
       int pos=m[root->val];
       root->left=Tree(preorder,inorder,m,instart,pos-1,preindex,n);
       root->right=Tree(preorder,inorder,m,pos+1,inend,preindex,n);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder[0]==-1)return new TreeNode(-1);
        int n=inorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
         int preindex = 0;
        return Tree(preorder, inorder, m, 0, n - 1, preindex, n);
    }
};