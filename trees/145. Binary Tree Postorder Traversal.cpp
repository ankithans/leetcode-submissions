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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorder(root, res);
		return res;
	}
	void postorder(TreeNode *root, vector<int> &res) {
		if (root == NULL) return;

		postorder(root -> left, res);
		postorder(root -> right, res);
		res.push_back(root -> val);
	}
};


int main() {
	inputOutput();


	return 0;
}
