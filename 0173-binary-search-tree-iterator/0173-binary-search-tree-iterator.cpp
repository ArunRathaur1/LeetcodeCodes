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
class BSTIterator {
private:
    void getElements(TreeNode* root,queue<int>&ar){
        if(root==NULL)return;
        getElements(root->left,ar);
        ar.push(root->val);
        getElements(root->right,ar);
    }
public:
    queue<int>ar;
    BSTIterator(TreeNode* root) {
       getElements(root,ar); 
    }
    
    int next() {
        int x=ar.front();
        ar.pop();
         return x;
         
    }
    
    bool hasNext() {
        return !ar.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */