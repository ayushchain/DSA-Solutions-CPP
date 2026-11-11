// Longest Substring Without Repeating Characters
// Taught fully in C++ on 2026-10-29 (Amazon prep, Mock Round 1 — taught mode).
// Pattern: sliding window + last-seen index.
// Idea: keep a window [left, right] with all distinct characters. For each
// character, if it was seen inside the current window, move left just past
// its previous occurrence. Track the longest window seen.
// Time: O(n). Space: O(1) — fixed 128-entry table for ASCII.
// Edge case to remember: "abba" — left must never move backwards, so
// left = max(left, lastSeen[c] + 1).
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int lengthOfLongestSubstring(const std::string& s) {
    std::vector<int> lastSeen(128, -1);
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        unsigned char c = s[right];
        left = std::max(left, lastSeen[c] + 1);
        lastSeen[c] = right;
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    struct Case { std::string s; int want; };
    const Case cases[] = {
        {"abcabcbb", 3}, {"bbbbb", 1}, {"pwwkew", 3},
        {"abba", 2},     {"", 0},      {"abcdef", 6},
    };
    int failed = 0;
    for (const auto& tc : cases) {
        int got = lengthOfLongestSubstring(tc.s);
        std::cout << "\"" << tc.s << "\" -> " << got
                  << (got == tc.want ? " OK" : " FAIL (want " + std::to_string(tc.want) + ")")
                  << "\n";
        if (got != tc.want) ++failed;
    }
    return failed;
}
