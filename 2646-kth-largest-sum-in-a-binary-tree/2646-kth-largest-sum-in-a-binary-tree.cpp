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
    vector<long long> levelOrder(TreeNode*root){
        queue<TreeNode*>q;
        vector<long long>output;
        q.push(root);
        q.push(NULL);
        long long sum=0;
        while(!q.empty()){
            TreeNode* tem=q.front();
            q.pop();
            if(tem==NULL){
               output.push_back(sum); 
               sum=0;
               if(q.empty())break;
               else{
                q.push(NULL);
               }
            }
            else{
                 sum=sum+tem->val;
                if(tem->left)
                q.push(tem->left);
                if(tem->right)
                q.push(tem->right);
            }
           
        }
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        return output;
    
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>x=levelOrder( root);
        if(k>x.size())return -1;

        sort(x.begin(),x.end());
        return x[x.size()-k];
    }
};