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
    int ans = 0;
    void countNodes(TreeNode* root, int prevMax){
        if(root==NULL){
            return;
        }
        int data = root->val;
        if(root->val >= prevMax){
            ans++;
            prevMax = root->val;
        }

        countNodes(root->left, prevMax);
        countNodes(root->right, prevMax);
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        countNodes(root,-200);
        return ans;
    }
};
