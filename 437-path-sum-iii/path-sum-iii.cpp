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
    void yo(TreeNode *root, int& targetSum, int& count){
        if(!root) return;
        solve(root, targetSum, count, 0);
        yo(root->left, targetSum, count);
        yo(root->right, targetSum, count);
    }
    
    void solve(TreeNode *root, int& targetSum, int& count, long long sum){
        if(!root) return;
        if(sum+root->val == targetSum) ++count;
        solve(root->left, targetSum, count, sum+root->val);
        solve(root->right, targetSum, count, sum+root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        yo(root, targetSum, count);
        return count;
    }
};