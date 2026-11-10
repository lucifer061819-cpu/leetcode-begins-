class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int m = words.size();
        int len = words[0].size();

        int totalLen = m * len;

        if (n < totalLen) return ans;

        unordered_map<string, int> mp;

        for (auto &w : words) {
            mp[w]++;
        }

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> seen;

            int left = i, count = 0;

            for (int right = i; right + len <= n; right += len) {

                string word = s.substr(right, len);

                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > mp[word]) {
                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    count--;
                    left += len;
                }

                if (count == m) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    count--;
                    left += len;
                }
            }
        }

        return ans;
    }
};