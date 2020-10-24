// https://leetcode.com/problems/binary-tree-preorder-traversal/


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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        if(root == NULL)
            return {};
        
        s.push(root);
        while(s.empty() == false) {
            TreeNode *temp = s.top();
            v.push_back(temp -> val);
            s.pop();
            if(temp -> right)
                s.push(temp -> right);
            if(temp -> left)
                s.push(temp -> left);
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
    void preorder(TreeNode* root, vector<int>& v) {
        if(root == NULL)
            return;
        v.push_back(root -> val);
        preorder(root -> left, v);
        preorder(root -> right, v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }
};