class Solution {
public:
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* build(int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = nodes[mid];

        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);

        return build(0, nodes.size() - 1);
    }
};