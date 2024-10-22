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
    vector<int> LevelOrder(TreeNode* root){
        vector<int>ar;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        while(!q.empty()){
            TreeNode* tem=q.front();
            q.pop();
            if(tem==NULL){
                ar.push_back(sum);
                sum=0;
                if(q.empty())break;
                q.push(NULL);
            }
            else{
                sum=sum+tem->val;
                if(tem->left)q.push(tem->left);
                if(tem->right)q.push(tem->right);
            }
        }
        // for(auto i: ar){
        //     cout<<i<<" ";
        // }
        return ar;
    }
    int maxLevelSum(TreeNode* root) {
        vector<int>ar=LevelOrder(root);
        int k=0;
        int p=ar[0];
        for(int i=0;i<ar.size();i++){
                if(p<ar[i]){
                    p=ar[i];
                    k=i;
                }
        }
        return k+1;
    }
};