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
    TreeNode* Tree(vector<int>&preorder,vector<int>& inorder){
        if(preorder.size()==0)return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        if(preorder.size()==1)return root;
        int index=-1;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            if(inorder[i]==preorder[0]){
                index=i;
                break;
            }
        }
        vector<int>inleft,inright,preleft,preright;
        for(int i=0;i<index;i++){
            inleft.push_back(inorder[i]);
        }
        for(int i=index+1;i<n;i++){
            inright.push_back(inorder[i]);
        }
        for(int i=1;i<index+1;i++){
            preleft.push_back(preorder[i]);
        }
        for(int i=index+1;i<n;i++){
            preright.push_back(preorder[i]);
        }
        root->left=Tree(preleft,inleft);
        root->right=Tree(preright,inright);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder[0]==-1)return new TreeNode(-1);
        return Tree(preorder,inorder);
    }
};