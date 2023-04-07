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
    void find(vector<vector<int>> &ans, TreeNode *p, int level)
    {
        if (p==nullptr) return;
        if (level>ans.size()) ans.push_back(vector<int>());
        ans[level-1].push_back(p->val);
        find(ans, p->left, level+1);
        find(ans, p->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        find(ans, root, 1);
        return ans;
    }
};