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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            vector<int>res;
            int sz = qu.size();

            for(int i = 0;i<sz;i++){
                TreeNode* top = qu.front();
                qu.pop();
                if(top->left){
                    qu.push(top->left);
                }
                if(top->right){
                    qu.push(top->right);
                }
                res.push_back(top->val);
            }
            ans.push_back(res);
        }

        return ans;
    }
};
