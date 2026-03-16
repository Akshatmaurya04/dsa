/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, int& targetSum, long long sum, bool& flag){
        if(!root) return;
        if(root->left == NULL && root -> right == NULL && sum+root->val == targetSum) flag = true;
        solve(root->left, targetSum, sum+root->val, flag);
        solve(root->right, targetSum, sum+root->val, flag);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        if(!root) return false;
        solve(root, targetSum, 0, flag);
        return flag;
    }
};