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
    TreeNode* build(vector<int> &nums, int l, int r)
    {
        if (r<l) return nullptr;
        int m = (l+r)>>1;
        TreeNode *curr = new TreeNode(nums[m]);
        curr->left = build(nums, l, m-1);
        curr->right = build(nums, m+1, r);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
        
    }
};