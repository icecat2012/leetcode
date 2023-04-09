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
    vector<int> now;
    int ans;
    void dfs(TreeNode *p, int &t)
    {
        now.push_back(p->val);
        long long int tmp=0;
        for(int i=now.size()-1;i>=0;--i)
        {
            tmp+=now[i];
            if(tmp==t)
                ++ans;
        }
        if(p->left!=nullptr)
            dfs(p->left, t);
        if(p->right!=nullptr)
            dfs(p->right, t);
        now.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans=0;
        if (root==nullptr) return ans;
        dfs(root, targetSum);
        return ans;
    }
};