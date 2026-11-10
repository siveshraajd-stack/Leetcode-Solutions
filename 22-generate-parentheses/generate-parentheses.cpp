class Solution {
public:
    vector<string> generateParenthesis(int n) {
        static const int catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430};
        vector<string> res;
        res.reserve(catalan[n]);
        string cur(2 * n, ' ');
        dfs(res, cur, 0, 0, n);
        return res;
    }

private:
    void dfs(vector<string>& res, string& cur, int pos, int open, int n) {
        if (pos == 2 * n) {
            res.push_back(cur);
            return;}
        if (open < n) {
            cur[pos] = '(';
            dfs(res, cur, pos + 1, open + 1, n);
        }
        if (pos - open < open) {   
            cur[pos] = ')';
            dfs(res, cur, pos + 1, open, n);
        }
    }
};