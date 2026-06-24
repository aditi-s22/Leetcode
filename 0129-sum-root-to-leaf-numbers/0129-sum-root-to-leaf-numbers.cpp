class Solution {
public:

    int dfs(TreeNode* root, int curr) {

        if(root == NULL)
            return 0;

        curr = curr * 10 + root->val;

        if(root->left == NULL && root->right == NULL)
            return curr;

        return dfs(root->left, curr) +
               dfs(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {

        return dfs(root, 0);
    }
};