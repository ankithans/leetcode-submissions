// https://leetcode.com/problems/n-ary-tree-preorder-traversal/


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
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> v;
        if(root == NULL)
            return {};
        s.push(root);
        while(s.empty() == false) {
            Node *curr = s.top();
            s.pop();
            v.push_back(curr -> val);
            for(int i = curr -> children.size() - 1; i >= 0; i--)
                s.push(curr -> children[i]);
        }
        return v;
    }
};



// recursive
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
    void preorder1(Node* root, vector<int>& v) {
        if(root == NULL)
            return;
        v.push_back(root -> val);
        if(root -> children.size() == 0)
            return;
        for(int i = 0; i <= root -> children.size() - 1; i++)
            preorder1(root -> children[i], v);     
    }
    
    vector<int> preorder(Node* root) {
        vector<int> v;
        preorder1(root, v);
        return v;
    }
};