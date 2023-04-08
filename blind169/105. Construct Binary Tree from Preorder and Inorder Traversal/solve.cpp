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
    TreeNode *build(vector<int> &p, vector<int> &i, int pl, int pr, int il, int ir)
    {
        if(pl>pr || il>ir) return nullptr;
        TreeNode *node = new TreeNode(p[pl]);
        int t;
        for (t=il;t<ir;++t)
            if (i[t]==p[pl])
                break;
        node->left = build(p, i, pl+1, pl+(t-il), il, t-1);
        node->right = build(p, i, pl+(t-il)+1, pr, t+1, ir);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};