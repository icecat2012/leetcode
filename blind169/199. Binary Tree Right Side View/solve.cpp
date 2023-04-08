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
    void find(TreeNode *p, vector<int> &a, int lvl)
    {
        if (p==nullptr) return;
        if (a.size()==lvl)
            a.push_back(p->val);
        find(p->right, a, lvl+1);
        find(p->left, a, lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        find(root, ans, 0);
        return ans;
    }
};