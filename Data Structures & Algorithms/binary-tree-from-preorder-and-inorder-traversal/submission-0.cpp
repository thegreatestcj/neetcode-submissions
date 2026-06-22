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
    unordered_map<int, int> idx;  // value -> index in inorder
    vector<int> pre;
    int preIdx = 0;               // next root to consume, in preorder order

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        return build(0, inorder.size() - 1);
    }

private:
    // build subtree whose inorder range is [left, right]
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;        // empty subtree

        int rootVal = pre[preIdx++];             // root = next preorder element
        TreeNode* root = new TreeNode(rootVal);
        int mid = idx[rootVal];                  // root position in inorder

        // left must be built before right: preIdx follows preorder order
        root->left  = build(left, mid - 1);
        root->right = build(mid + 1, right);
        return root;
    }
};
