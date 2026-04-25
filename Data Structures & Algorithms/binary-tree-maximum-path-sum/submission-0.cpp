class Solution {	
public:
    int fun(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }

        int leftMax = fun(root->left, ans);
        int rightMax = fun(root->right, ans);

        int pathSum = max(root->val,
                          root->val + max(leftMax, rightMax));

        ans = max(ans, max(pathSum, root->val + leftMax + rightMax));

        return pathSum;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
};