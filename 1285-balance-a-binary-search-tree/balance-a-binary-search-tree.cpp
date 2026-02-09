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
    TreeNode* buildTree(vector<TreeNode*>& vp, int start, int end){
        if(start>end) return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(vp[mid]->val);
        root->left = buildTree(vp,start,mid-1);
        root->right = buildTree(vp,mid+1,end);
        return root;

    }
    void inorder(TreeNode* root, vector<TreeNode*>& vp){
        if(!root) return;
        inorder(root->left,vp);
        vp.push_back(root);
        inorder(root->right,vp);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vp;
        inorder(root,vp);
        int start = 0;
        int end = vp.size()-1;
        return buildTree(vp,start,end);
    }
};