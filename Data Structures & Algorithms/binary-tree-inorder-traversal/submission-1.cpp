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
    void fun(TreeNode* root, vector<int>&arr){
        if(root==NULL){
            return ;
        }
        fun(root->left,arr);
        arr.push_back(root->val);
        fun(root->right,arr);
    }



    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        // fun(root,ans);

        
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || st.size()>0){
            while(curr){
                st.push(curr);
                curr=curr->left;
            }
            curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            curr= curr->right;
        }
        return ans;
    }








};