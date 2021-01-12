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
	bool isSymmetric(TreeNode* root) {
		return sym(root, root);
	}
	bool sym(TreeNode *t1, TreeNode *t2) {
		if (t1 == NULL && t2 == NULL) return true;
		if (t1 == NULL || t2 == NULL) return false;

		return t1 -> val == t2 -> val && sym(t1 -> right, t2 -> left)
		       && sym(t1 -> left, t2 -> right);
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode *> q1, q2;
		q1.push(root);
		q2.push(root);

		while (q1.empty() == false && q2.empty() == false) {
			TreeNode *t1 = q1.front(), *t2 = q2.front();
			q1.pop(); q2.pop();

			if (t1 == NULL && t2 == NULL) continue;
			if (t1 == NULL || t2 == NULL) return false;
			if (t1 -> val != t2 -> val) return false;

			q1.push(t1 -> left);
			q1.push(t1 -> right);
			q2.push(t2 -> right);
			q2.push(t2 -> left);
		}
		return true;
	}
};


int main() {
	inputOutput();


	return 0;
}
