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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};

		vector<vector<int>> res;
		queue<TreeNode *> q;
		q.push(root);

		while (q.empty() == false) {
			int count = q.size();
			vector<int> v;
			for (int i = 0; i < count; i++) {
				TreeNode *curr = q.front();
				q.pop();
				v.push_back(curr -> val);

				if (curr -> left != NULL) q.push(curr -> left);
				if (curr -> right != NULL) q.push(curr -> right);
			}
			res.push_back(v);
		}
		return res;
	}
};



int main() {
	inputOutput();


	return 0;
}
