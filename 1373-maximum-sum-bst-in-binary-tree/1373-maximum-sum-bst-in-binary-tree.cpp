class Solution {
public:
    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int ans = 0;

    Info dfs(TreeNode* root) {
        if (root == nullptr)
            return {true, INT_MAX, INT_MIN, 0};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int sum = root->val + left.sum + right.sum;

            ans = max(ans, sum);

            return {
                true,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                sum
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};