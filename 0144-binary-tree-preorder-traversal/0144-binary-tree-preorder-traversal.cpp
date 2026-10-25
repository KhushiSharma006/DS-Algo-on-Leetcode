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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> st;

        if (root == nullptr) return v;

        st.push(root);

        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            v.push_back(temp->val);

            if (temp->right != nullptr)
                st.push(temp->right);

            if (temp->left != nullptr)
                st.push(temp->left);
        }

        return v;
    }
};