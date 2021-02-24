#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr){}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode *left,TreeNode *right) :val(x),left(left),right(right) {}

};

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		queue<TreeNode*>q;
		int res = 0;
		if (root) q.push(root);
		while (q.size()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode* tr = q.front();
				q.pop();
				if (tr->val >= L && tr->val <= R) res += tr->val;
				if (tr->left) q.push(tr->left);
				if (tr->right) q.push(tr->right);
			}
		}
		return res;
	}
};