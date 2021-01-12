#include <bits/stdc++.h>
using namespace std;

void inputOutput() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}


// iterative
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (root == NULL) return {};

		vector<int> res;
		queue<TreeNode *> q;
		q.push(root);

		while (q.empty() == false) {
			int count = q.size();
			for (int i = 0; i < count; i++) {
				TreeNode *curr = q.front();
				q.pop();
				if (i == count - 1)
					res.push_back(curr -> val);

				if (curr -> left != NULL) q.push(curr -> left);
				if (curr -> right != NULL) q.push(curr -> right);
			}

		}
		return res;
	}
};


// recursive
class Solution {
public:
	int maxLevel = 0;
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		right(root, res, 1);
		return res;
	}
	void right(TreeNode *root, vector<int> &res, int level) {
		if (root == NULL) return;

		if (maxLevel < level) {
			res.push_back(root -> val);
			maxLevel = level;
		}

		right(root -> right, res, level + 1);
		right(root -> left, res, level + 1);
	}
};


// recursive
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		right(root, res, 1);
		return res;
	}
	void right(TreeNode *root, vector<int> &res, int level) {
		if (root == NULL) return;

		if (res.size() < level) {
			res.push_back(root -> val);
		}

		right(root -> right, res, level + 1);
		right(root -> left, res, level + 1);
	}
};


int main() {
	inputOutput();


	return 0;
}
