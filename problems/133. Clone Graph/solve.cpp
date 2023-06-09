// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> index;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return node;
        if (index.count(node->val))
            return index[node->val];
            
        index[node->val] = new Node(node->val);
        for (int i=0;i<node->neighbors.size();++i)
        {
            index[node->val]->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }

        return index[node->val];
    }
};