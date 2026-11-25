class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0;
        int star = -1, mark = 0;
        while (i < n) {
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                i++; j++;
            } else if (j < m && p[j] == '*') {
                star = j; mark = i; j++;
            } else if (star != -1) {
                mark++; i = mark; j = star + 1;
            } else {
                return false;
            }
        }
        while (j < m && p[j] == '*') j++;
        return j == m;
    }
};