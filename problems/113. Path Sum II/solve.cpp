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
    void find(TreeNode *p, int t, int n, vector<int> &now)
    {
        if (p->left==nullptr && p->right==nullptr && n+p->val==t)
        {
            now.push_back(p->val);
            ans.push_back(now);
            now.pop_back();
            return;
        }
        now.push_back(p->val);
        if(p->left!=nullptr)
            find(p->left, t, n+p->val, now);
        if(p->right!=nullptr)
            find(p->right, t, n+p->val, now);
        now.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return vector<vector<int>>();
        vector<int> mem;
        find(root, targetSum, 0, mem);
        return ans;
    }
};