class Solution {
public:
    int count = 0;
    int answer = 0;

    void inorder(TreeNode* root, int k) {
        if (root == nullptr)
            return;

        inorder(root->left, k);

        count++;

        if (count == k) {
            answer = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inorder(root, k);
        return answer;
    }
};