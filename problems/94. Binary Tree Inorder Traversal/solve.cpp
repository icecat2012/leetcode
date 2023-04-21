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
    vector<int> ans;
    void find(TreeNode *p)
    {
        if(p==nullptr) return;
        find(p->left);
        ans.push_back(p->val);
        find(p->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        find(root);
        return ans;
    }
};