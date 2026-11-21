class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        int left = 0, count = t.size();
        int minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};