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
    int countNodes(TreeNode* root, int prevMax){
        if(root==NULL){
            return 0 ;
        }
        int res = 0;
        if(root->val >= prevMax){
            res++;
            prevMax = root->val;
        }

        res+=countNodes(root->left, prevMax);
        res+=countNodes(root->right, prevMax);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return countNodes(root,-200);
    }
};
