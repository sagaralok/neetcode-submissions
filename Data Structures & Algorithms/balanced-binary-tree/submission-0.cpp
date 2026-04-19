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
    bool ans;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left ==NULL && root->right ==NULL){
            return 1;
        }
        int left = fun(root->left);
        int right = fun(root->right);

        if(abs(left-right)>1){
            ans = false;
        }

        return max(left,right)+1;

    }
    bool isBalanced(TreeNode* root) {
        ans = true;
        fun(root);
        return ans;
    }
};
