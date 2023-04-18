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
    int find(TreeNode *p, int &k)
    {
        int a;
        if (p->left!=nullptr)
            a = find(p->left, k);
        if (k<=0)
            return a;
        
        --k;
        if(k==0)
            return p->val;

        if (p->right!=nullptr)
            return find(p->right, k);
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};