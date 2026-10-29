class Solution {
public:
    bool validate(TreeNode* root, long long low, long long high) {
        if (root == nullptr)
            return true;

        if (root->val <= low || root->val >= high)
            return false;

        return validate(root->left, low, root->val) &&
               validate(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};