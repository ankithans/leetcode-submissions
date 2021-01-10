#include <bits/stdc++.h>
using namespace std;

void inputOutput() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}


// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> pre;
		preorder(root, pre);
		return pre;
	}
	void preorder(TreeNode *root, vector<int> &pre) {
		if (root == NULL) return;

		pre.push_back(root -> val);
		preorder(root -> left, pre);
		preorder(root -> right, pre);
	}
};


// iterative
class Solution1 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == NULL) return {};

		stack<TreeNode *> s;
		vector<int> res;
		s.push(root);

		while (s.empty() == false) {
			TreeNode *curr = s.top();
			s.pop();
			res.push_back(curr->val);

			if (curr -> right != NULL) s.push(curr -> right);
			if (curr -> left != NULL) s.push(curr -> left);
		}

		return res;
	}
};



int main() {
	inputOutput();


	return 0;
}
