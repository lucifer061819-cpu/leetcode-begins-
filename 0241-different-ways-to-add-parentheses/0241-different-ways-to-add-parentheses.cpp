class Solution {
public:
    unordered_map<string, vector<int>> dp;

    vector<int> diffWaysToCompute(string expression) {

        if (dp.count(expression)) {
            return dp[expression];
        }

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftAns = diffWaysToCompute(left);
                vector<int> rightAns = diffWaysToCompute(right);

                for (int a : leftAns) {
                    for (int b : rightAns) {

                        if (ch == '+')
                            ans.push_back(a + b);

                        else if (ch == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If no operator exists, convert string to number
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return dp[expression] = ans;
    }
};