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
    TreeNode *rec(TreeNode* p)
    {
        if(p==nullptr || (p->left==nullptr && p->right==nullptr)) return p;
        TreeNode *h = p;
        if(p->left!=nullptr)
        {
            TreeNode *r = p->right;
            p->right = rec(p->left);
            p->left = nullptr;
            while(p->right!=nullptr)
                p = p->right;
            p->right = rec(r);
        }
        else
        {
            p->right = rec(p->right);
        }
        return h;
    }
    void flatten(TreeNode* root) {
        rec(root);
    }
};