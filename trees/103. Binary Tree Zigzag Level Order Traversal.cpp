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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL) return {};

		vector<vector<int>> res;
		queue<TreeNode *> q;
		stack<int> s;
		bool reverse = false;
		q.push(root);

		while (q.empty() == false) {
			int count = q.size();
			vector<int> v;
			for (int i = 0; i < count; i++) {
				TreeNode *curr = q.front();
				q.pop();
				if (reverse) {
					s.push(curr -> val);
				} else {
					v.push_back(curr -> val);
				}

				if (curr -> left != NULL) q.push(curr -> left);
				if (curr -> right != NULL) q.push(curr -> right);
			}
			if (reverse) {
				while (s.empty() == false) {
					v.push_back(s.top());
					s.pop();
				}
			}
			res.push_back(v);
			reverse = !reverse;
		}
		return res;
	}
};


// efficient
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL) return {};

		vector<vector<int>> res;
		stack<TreeNode *> s1, s2;
		s1.push(root);

		while (s1.empty() == false || s2.empty() == false) {

			vector<int> temp1, temp2;
			while (s1.empty() == false) {
				TreeNode *curr = s1.top();
				s1.pop();
				temp1.push_back(curr -> val);
				if (curr -> left != NULL) s2.push(curr -> left);
				if (curr -> right != NULL) s2.push(curr -> right);
			}

			if (temp1.size() > 0) res.push_back(temp1);

			while (s2.empty() == false) {
				TreeNode *curr = s2.top();
				s2.pop();
				temp2.push_back(curr -> val);
				if (curr -> right != NULL) s1.push(curr -> right);
				if (curr -> left != NULL) s1.push(curr -> left);
			}

			if (temp2.size() > 0) res.push_back(temp2);

		}
		return res;
	}
};



int main() {
	inputOutput();


	return 0;
}
