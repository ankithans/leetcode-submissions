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
	int res;
	int hd(TreeNode *root) {
		if (root == NULL) return 0;

		int lh = hd(root -> left);
		int rh = hd(root -> right);

		res = max(res, 1 + lh + rh);

		return 1 + max(lh, rh);
	}
	int diameterOfBinaryTree(TreeNode* root) {
		res = 0;
		hd(root);
		if (res == 0)
			return res;
		else
			return res - 1;
	}
};


int main() {
	inputOutput();


	return 0;
}
