/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode* build(vector<int>&inorder, int inStart, int inEnd, vector<int>&preOrder, int preStart, int preEnd, unordered_map<int, int>&mp){

        if(preStart>preEnd || inStart > inEnd){
            return NULL;
        }

        // New Node
        TreeNode* root = new TreeNode(preOrder[preStart]);

        int rootNode = mp[preOrder[preStart]];

        int nodesInLeft = rootNode - inStart;

        root->left = build(inorder,inStart,rootNode-1, preOrder, preStart+1, preStart+nodesInLeft,mp);
        root->right = build(inorder,rootNode+1, inEnd, preOrder, preStart+nodesInLeft+1, preEnd,mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //your code goes here
        unordered_map<int,int>mp;
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(inorder,0, inorder.size()-1, preorder, 0, preorder.size()-1, mp);
    }
};