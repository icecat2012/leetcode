/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void encoder(TreeNode* p, string &now)
    {
        if (p==nullptr)
        {
            now += "n,";
            return ;
        }
        now += (to_string(p->val) + ",");
        encoder(p->left, now);
        encoder(p->right, now);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        encoder(root, ans);
        return ans;
    }

    TreeNode* decoder(string &data)
    {
        if (data.size()==0) return nullptr;
        if (data[0]=='n')
        {
            data = data.substr(2);
            return nullptr;
        }
        int i;
        for(i=0;i<data.size();++i)
        {
            if (data[i]==',')
                break;
        }

        string now=data.substr(0,i);
        TreeNode *node = new TreeNode(stoi(now));
        data = data.substr(i+1);
        node->left = decoder(data);
        node->right = decoder(data);
        return node;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return decoder(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));