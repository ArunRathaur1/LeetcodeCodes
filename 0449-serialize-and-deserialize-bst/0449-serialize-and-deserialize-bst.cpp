/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "# ";
        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (p == nullptr) {
                ans += "# ";
            } else {
                ans += to_string(p->val) + " ";
                q.push(p->left);
                q.push(p->right);
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty() || s == "# ") return nullptr;

        stringstream ss(s);
        string val;
        getline(ss, val, ' ');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            // Process left child
            if (getline(ss, val, ' ')) {
                if (val == "#") {
                    parent->left = nullptr;
                } else {
                    TreeNode* leftNode = new TreeNode(stoi(val));
                    parent->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Process right child
            if (getline(ss, val, ' ')) {
                if (val == "#") {
                    parent->right = nullptr;
                } else {
                    TreeNode* rightNode = new TreeNode(stoi(val));
                    parent->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};

// Usage example:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
