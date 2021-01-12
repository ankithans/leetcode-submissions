#include <bits/stdc++.h>
using namespace std;

void inputOutput() {
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
}


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return NULL;

		if (root -> val == p -> val || root -> val == q -> val)
			return root;

		TreeNode *leftLCA = lowestCommonAncestor(root -> left, p, q);
		TreeNode *rightLCA = lowestCommonAncestor(root -> right, p, q);

		if (leftLCA == NULL) return rightLCA;
		if (rightLCA == NULL) return leftLCA;

		return root;
	}
};


class Solution {
public:
	bool findPath(TreeNode *root, vector<TreeNode *> &v, int n) {
		if (root == NULL) return false;

		v.push_back(root);
		if (root -> val == n) return true;

		if (findPath(root -> left, v, n) || findPath(root -> right, v, n))
			return true;

		v.pop_back();
		return false;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode *> path1, path2;

		if (findPath(root, path1, p -> val) == false || findPath(root, path2, q -> val) == false)
			return NULL;

		for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++) {
			if (path1[i + 1] != path2[i + 1])
				return path1[i];
		}
		return NULL;
	}
};


int main() {
	inputOutput();


	return 0;
}
