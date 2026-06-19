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
    int kthSmallest(TreeNode* root, int k) {
        kth(root, k);
        return res;
    }

private:
    int counter = 0;
    int res = -1;
    void kth(TreeNode* root, int k)
    {
        if (root == nullptr) return;
        kth(root->left, k);
        counter++;
        if (counter == k)
        {
            res = root->val;
            return;
        }
        kth(root->right, k);
    }
};
