/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<int, vector<int>> graph;
    void dfs(TreeNode *p)
    {
        if(p->left!=nullptr)
        {
            graph[p->val].push_back(p->left->val);
            graph[p->left->val].push_back(p->val);
            dfs(p->left);
        }

        if(p->right!=nullptr)
        {
            graph[p->val].push_back(p->right->val);
            graph[p->right->val].push_back(p->val);
            dfs(p->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==nullptr) return ans;
        dfs(root);

        vector<bool> visit(500, 0);
        queue<int> work;
        work.push(target->val);
        while (work.size()>0)
        {
            if (k==-1) break;
            for(int i=work.size();i>0;--i)
            {
                visit[work.front()] = 1;
                if(k==0)
                    ans.push_back(work.front());
                for (auto &p:graph[work.front()])
                {
                    if(visit[p]==0)
                        work.push(p);
                }
                work.pop();
            }
            --k;
        }
        return ans;
    }
};