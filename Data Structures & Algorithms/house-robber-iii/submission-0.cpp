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

    // Pair is to store max value at a node for {Robbing,NotRobbing}
    pair<int,int> robAlternateHouse(TreeNode* root){ 
        // Base case
        if(root==NULL){
            return {0,0};
        }
        //
        pair<int,int>leftAns = robAlternateHouse(root->left);
        pair<int,int>rightAns = robAlternateHouse(root->right);

        // If we rob current Node
        int rob = leftAns.second + rightAns.second + root->val;

        // If we not rob current Node 
        int notRob = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        pair<int,int>ans = robAlternateHouse(root);

        return max(ans.first, ans.second);
    }
};