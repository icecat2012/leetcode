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
    bool flag;
    int check(TreeNode* p)
    {
        if (p==nullptr) return 0;

        int left=0, right=0;
        if(p->left!=nullptr)
        {
            left = 1+check(p->left);
            if (flag==false)
                return -1;
        }
        if(p->right!=nullptr)
        {
            right = 1+check(p->right);
            if (flag==false)
                return -1;

        }
        
        if (abs(left-right)>1)
        {
            flag=false;
            return -1;
        }
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) 
    {
        flag = true;
        check(root);

        return flag;
    }
};