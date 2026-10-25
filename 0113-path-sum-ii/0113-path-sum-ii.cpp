class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(TreeNode* root, int targetSum) {
        if (root == NULL)
            return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (root->left == NULL && root->right == NULL) {
            if (targetSum == 0)
                ans.push_back(path);
        } else {
            solve(root->left, targetSum);
            solve(root->right, targetSum);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return ans;
    }
};