class Solution {
private:
    vector<tuple<int, int, int>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (root == nullptr) {
            return;
        }

        nodes.push_back({col, row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        nodes.clear();

        dfs(root, 0, 0);

        // Sort by column, then row, then value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> result;

        int prevCol = INT_MIN;

        for (auto& [col, row, val] : nodes) {
            if (col != prevCol) {
                result.push_back({});
                prevCol = col;
            }

            result.back().push_back(val);
        }

        return result;
    }
};