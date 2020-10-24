// https://leetcode.com/problems/binary-tree-inorder-traversal/


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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode *curr = root;
        while(curr || s.empty() == false) {
            while(curr) {
                s.push(curr);
                curr = curr -> left;
            }
            curr = s.top();
            s.pop();
            v.push_back(curr -> val);
            curr = curr -> right;
        }
        return v;
    }
};


