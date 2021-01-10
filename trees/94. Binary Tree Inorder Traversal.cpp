#include <bits/stdc++.h>
using namespace std;

void inputOutput() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}

// recursive
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
	void inorder(TreeNode *root, vector<int> &res) {
		if (root == NULL) return;

		inorder(root -> left, res);
		res.push_back(root -> val);
		inorder(root -> right, res);
	}
};

// iterative
class Solution1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL) return {};

		stack<TreeNode *> s;
		vector<int> res;
		TreeNode *curr = root;

		while (curr != NULL || s.empty() == false) {
			while (curr != NULL) {
				s.push(curr);
				curr = curr -> left;
			}

			curr = s.top();
			s.pop();
			res.push_back(curr -> val);
			curr = curr -> right;
		}

		return res;
	}
};

int main() {
	inputOutput();


	return 0;
}
