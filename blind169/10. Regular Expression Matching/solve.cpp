class Solution {
public:
    int dp[21][21];
    bool solve(string &s, string &p, int i, int j) {
        if(j < 0)  return i < 0;
        if(i < 0) {
            if(p[j] == '*') {
                return solve(s, p, i, j - 2);
            }
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '.') return dp[i][j] = solve(s, p, i - 1, j - 1);
        if(p[j] == '*') {
            if(dp[i][j] = solve(s, p, i, j - 2)) return true;
            if(p[j - 1] == '.' || p[j - 1] == s[i]) return dp[i][j] = solve(s, p, i - 1, j);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, s.size() - 1, p.size() - 1);
    }
};