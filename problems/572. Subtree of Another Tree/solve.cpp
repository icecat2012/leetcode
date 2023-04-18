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
    bool same(TreeNode *p1, TreeNode *p2)
    {
        if(p1==nullptr && p2==nullptr) return true;
        else if(p1==nullptr || p2==nullptr) return false;
        if(p1->val!=p2->val) return false;
        return same(p1->left, p2->left) && same(p1->right, p2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (same(root, subRoot))
            return true;
        bool ans;
        if (root->left!=nullptr)
            ans = isSubtree(root->left, subRoot);
        if (ans) return true;
        if (root->right!=nullptr)
            return isSubtree(root->right, subRoot);
        return false;
    }
};