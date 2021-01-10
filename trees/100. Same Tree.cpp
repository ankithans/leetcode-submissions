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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;

		if (p -> val != q -> val) return false;

		return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
	}
};


int main() {
	inputOutput();


	return 0;
}
