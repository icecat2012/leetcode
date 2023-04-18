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
    int best;
    int find(TreeNode *p)
    {
        if(p==nullptr) return 0;
        int a=0, b=0;
        if(p->left!=nullptr)
            a = find(p->left);
        if(p->right!=nullptr)
            b = find(p->right);
        if (a+b>best)
            best = a+b;
        // cout<<p->val<<' '<<a<<' '<<b<<endl;
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        best = 0;
        find(root);
        return best;
    }
};