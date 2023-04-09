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
    vector<vector<int>> ans;
    void preorder(TreeNode *p, int lvl)
    {
        if (p==nullptr) return;
        if (ans.size()==lvl) ans.push_back(vector<int>());
        ans[lvl].push_back(p->val);
        preorder(p->left, lvl+1);
        preorder(p->right, lvl+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        preorder(root, 0);
        for(int i=0;i<ans.size();++i)
        {
            if (i%2)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};