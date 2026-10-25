class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 2; // Null nodes are considered covered
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If a child needs a camera, place one here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If a child has a camera, this node is covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Both children are covered, but this node is not
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        cameras = 0;

        if (dfs(root) == 0) {
            cameras++;
        }

        return cameras;
    }
};