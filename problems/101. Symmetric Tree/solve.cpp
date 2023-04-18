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
    void inverse(TreeNode *p)
    {
        if(p==nullptr) return;
        swap(p->left, p->right);
        inverse(p->left);
        inverse(p->right);
    }
    bool same(TreeNode *a, TreeNode *b)
    {
        if(a==nullptr && b==nullptr) return true;
        else if(a==nullptr || b==nullptr) return false;
        if (a->val!=b->val) return false;
        return same(a->left, b->left) && same(a->right, b->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left!=nullptr && root->right!=nullptr)
        {
            inverse(root->right);
            return same(root->left, root->right);
        }
        else if(root->left!=nullptr || root->right!=nullptr)
            return false;
        else
            return true;
    }
};