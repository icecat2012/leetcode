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
    bool check(TreeNode *p, long long int low, long long int high)
    {
        if (p->val<=low ||p->val>=high)
            return false;
        bool flag=true;
        if(p->left!=nullptr)
            flag &= check(p->left, low, p->val);
        if(flag==false)
            return false;
        if(p->right!=nullptr)
            flag &= check(p->right, p->val, high);
        return flag;
            
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};