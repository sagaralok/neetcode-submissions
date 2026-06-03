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
    TreeNode* solve(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* leftchild = root->left;
        TreeNode* leftmost_child_in_right_subtree = root->right;

        while (leftmost_child_in_right_subtree->left) {
            leftmost_child_in_right_subtree =
                leftmost_child_in_right_subtree->left;
        }
        leftmost_child_in_right_subtree->left = leftchild;
        // Return the right subtree as the new root of the modified tree.
        return root->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return solve(root);
        }
        if(root->val<key){
            if(root->right && root->right->val==key){
                root->right = solve(root->right);
                return root;
            }
            root->right = deleteNode(root->right, key);
        }
        else if(root->val>key){
            if(root->left && root->left->val==key){
                root->left = solve(root->left);
                return root;
            }
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};