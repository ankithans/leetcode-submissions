// https://leetcode.com/problems/n-ary-tree-postorder-traversal/


// iterative
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> s1, s2;
        vector<int> v;
        if(root == NULL)
            return {};
        s1.push(root);
        while(s1.empty() == false) {
            Node *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr -> children.size())
                for(int i = 0; i < curr -> children.size(); i++) 
                    s1.push(curr -> children[i]);
        }
        while(s2.empty() == false) {
            v.push_back(s2.top() -> val);
            s2.pop();
        }
        return v;
    }
};


// recursive
// same