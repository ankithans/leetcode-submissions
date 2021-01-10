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
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;

		return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
	}
};


// iterative
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;

		queue<TreeNode *> q;
		int height = 0;
		q.push(root);

		while (q.empty() == false) {
			int count = q.size();
			for (int i = 0; i < count; i++) {
				TreeNode *curr = q.front();
				q.pop();
				if (curr -> left != NULL) q.push(curr -> left);
				if (curr -> right != NULL) q.push(curr -> right);
			}
			height++;
		}
		return height;
	}
};

int main() {
	inputOutput();


	return 0;
}
