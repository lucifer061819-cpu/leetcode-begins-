class Solution {
public:
    int ans;

    int maxGain(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = max(0, maxGain(root->left));
        int right = max(0, maxGain(root->right));

        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        maxGain(root);
        return ans;
    }
};