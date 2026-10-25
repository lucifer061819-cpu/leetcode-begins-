class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        unsigned long long maxWidth = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();

            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize indices to reduce overflow risk
                index -= minIndex;

                if (i == 0) {
                    first = index;
                }

                if (i == size - 1) {
                    last = index;
                }

                if (node->left) {
                    q.push({node->left, 2 * index});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
            }

            maxWidth = max(maxWidth, last - first + 1);
        }

        return static_cast<int>(maxWidth);
    }
};