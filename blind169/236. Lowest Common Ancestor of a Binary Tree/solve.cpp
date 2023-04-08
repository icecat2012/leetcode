/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) return root;
        if (root->val==p->val) return root;
        if (root->val==q->val) return root;

        TreeNode *a=nullptr, *b=nullptr;
        if (root->left!=nullptr)
            a=lowestCommonAncestor(root->left, p, q);
        if (root->right!=nullptr)
            b=lowestCommonAncestor(root->right, p, q);

        if (a!=nullptr && b!=nullptr)
            return root;
        else if(a!=nullptr)
            return a;
        else
            return b;
    }
};