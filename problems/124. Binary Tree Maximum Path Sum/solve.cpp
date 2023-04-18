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
    int best;
    int find(TreeNode *root)
    {
        if (root==nullptr) return 0;
        int a=find(root->left), b=find(root->right);
        
        best = max(best, root->val);
        best = max(best, a+root->val);
        best = max(best, b+root->val);
        best = max(best, a+b+root->val);

        return max(root->val, root->val + max(a, b));
    }

    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        find(root);
        return best;
    }
};