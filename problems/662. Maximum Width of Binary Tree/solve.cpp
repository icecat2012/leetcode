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
    vector<int> front;
    int find(TreeNode *p, long long int index, long long int level)
    {
        if(p==nullptr) return 0;
        if(front.size()==level)
            front.push_back(index);

        int w=index-front[level]+1;
        int lw=find(p->left, (index-front[level])*2, level+1);
        int rw=find(p->right, (index-front[level])*2+1, level+1);
        return max({w, lw, rw});
    }
    int widthOfBinaryTree(TreeNode* root) {
        return find(root, 0, 0);
    }
};