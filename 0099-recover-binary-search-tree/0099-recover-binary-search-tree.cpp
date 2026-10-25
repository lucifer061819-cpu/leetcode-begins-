class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        // Detect an inversion in inorder traversal
        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
            }

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = second = prev = nullptr;

        inorder(root);

        // Swap the misplaced values
        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};