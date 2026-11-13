// Palindrome Partitioning II (LeetCode 132)
// Taught fully in C++ on 2026-11-13 (LeetCode prep), then solved and
// submitted by me — Accepted. My first DP pattern problem (Hard).
// Pattern: DP — palindrome table + minimum-cuts DP.
// Idea: pal[i][j] tells whether s[i..j] is a palindrome, built from
// pal[i][j] = (s[i] == s[j]) && (length <= 3 || pal[i+1][j-1]).
// dp[i] = minimum cuts for the first i characters. With dp[0] = -1,
// whenever s[j..i-1] is a palindrome, dp[i] = min(dp[i], dp[j] + 1).
// The dp[0] = -1 trick makes a fully-palindromic string give 0 cuts.
// Greedy (cut the longest palindrome first) does not work — hence DP.
// Time: O(n^2). Space: O(n^2) for the palindrome table.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minCut(const std::string& s) {
    int n = (int)s.size();
    std::vector<std::vector<bool>> pal(n, std::vector<bool>(n, false));
    for (int i = n - 1; i >= 0; --i)
        for (int j = i; j < n; ++j)
            if (s[i] == s[j] && (j - i <= 2 || pal[i + 1][j - 1]))
                pal[i][j] = true;

    std::vector<int> dp(n + 1);
    dp[0] = -1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = i - 1;  // worst case: cut between every character
        for (int j = 0; j < i; ++j)
            if (pal[j][i - 1])
                dp[i] = std::min(dp[i], dp[j] + 1);
    }
    return dp[n];
}

int main() {
    struct Case { std::string s; int want; };
    const Case cases[] = {
        {"aab", 1}, {"a", 0}, {"ab", 1}, {"aa", 0},
        {"racecar", 0}, {"abc", 2}, {"aabbaa", 0},
    };
    int failures = 0;
    for (const auto& c : cases) {
        int got = minCut(c.s);
        bool ok = (got == c.want);
        if (!ok) ++failures;
        std::cout << (ok ? "OK   " : "FAIL ") << '"' << c.s << "\" -> "
                  << got << " (want " << c.want << ")\n";
    }
    return failures ? 1 : 0;
}
