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
	int height(TreeNode *root) {
		if (root == NULL) return NULL;

		return 1 + max(height(root -> left), height(root -> right));
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return true;

		int lh = height(root -> left);
		int rh = height(root -> right);

		if (abs(lh - rh) > 1) return false;

		return isBalanced(root -> left) && isBalanced(root -> right);
	}
};


class Solution1 {
public:
	bool isBalanced(TreeNode* root) {
		int res = balanced(root);
		cout << res;
		if (res == -1)
			return false;
		return true;
	}
	int balanced(TreeNode *root) {
		if (root == NULL) return 0;

		int lh = balanced(root -> left);
		if (lh == -1) return -1;

		int rh = balanced(root -> right);
		if (rh == -1) return -1;

		if (abs(lh - rh) > 1) return -1;

		return 1 + max(lh, rh);
	}
};

int main() {
	inputOutput();


	return 0;
}
