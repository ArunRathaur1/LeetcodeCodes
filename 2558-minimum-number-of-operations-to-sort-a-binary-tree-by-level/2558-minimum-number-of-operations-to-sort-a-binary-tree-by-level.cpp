class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<TreeNode*> q;
        vector<vector<int>> ar;
        
        q.push(root);
        q.push(NULL); // Level separator
        
        vector<int> temp;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == NULL) {
                ar.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        int totalSwaps = 0;
        for (const auto& level : ar) {
            vector<pair<int, int>> indexedLevel;
            for (int i = 0; i < level.size(); i++) {
                indexedLevel.push_back({level[i], i});
            }
            
            sort(indexedLevel.begin(), indexedLevel.end()); // Sort by value.
            
            vector<bool> visited(level.size(), false);
            for (int i = 0; i < indexedLevel.size(); i++) {
                if (visited[i] || indexedLevel[i].second == i) {
                    continue;
                }
                
                // Count the size of the cycle.
                int cycleSize = 0;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = indexedLevel[j].second;
                    cycleSize++;
                }
                
                // Add (cycleSize - 1) swaps to sort the cycle.
                if (cycleSize > 1) {
                    totalSwaps += (cycleSize - 1);
                }
            }
        }
        
        return totalSwaps;
    }
};
