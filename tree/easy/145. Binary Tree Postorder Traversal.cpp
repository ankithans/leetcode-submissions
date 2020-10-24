// https://leetcode.com/problems/binary-tree-postorder-traversal/


// iterative
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<int> v;
        if(root == NULL)
            return {};
        s1.push(root);
        while(s1.empty() == false) {
            TreeNode *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr -> left)
                s1.push(curr -> left);
            if(curr -> right)
                s1.push(curr -> right);
        }
        while(s2.empty() == false) {
            v.push_back(s2.top() -> val);
            s2.pop();
        }
        return v;
    }
};



// recursive
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
    void postorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;
        postorder(root -> left, v);
        postorder(root -> right, v);
        v.push_back(root -> val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(root, v);
        return v;
    }
};