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
    vector<int> levelsum(TreeNode* root){
        queue<TreeNode*>q;
        vector<int>ar;
        int level=1;
        int sum=0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* tem=q.front();
            q.pop();
            if(tem==NULL){
                ar.push_back(sum);
                if(!q.empty()){
                    q.push(NULL);
                    level++;
                    sum=0;
                }
                else{
                    break;
                }
            }
            else{
                sum=sum+tem->val;
                if(tem->left){
                    q.push(tem->left);
                }
                if(tem->right){
                    q.push(tem->right);
                }
            }
        }
        return ar;
    }
    void cousins(TreeNode* root,int level,vector<int>&ar){
        if(root==NULL)return;
        if(level==0){
            root->val=0;
        }
            int currsum=0;
            if(root->left){
                currsum=currsum+root->left->val;
            }
            if(root->right){
                currsum=currsum+root->right->val;
            }
            int x=0;
            if(level+1<ar.size())
             x=ar[level+1]-currsum;
            if(root->left){
                root->left->val=x;
                cousins(root->left,level+1,ar);
            }
            if(root->right){
                root->right->val=x;
                cousins(root->right,level+1,ar);
            }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
       vector<int>ar= levelsum(root);
       cousins(root,0,ar);
       return root;
        
    }
};