// Longest Substring with At Most K Distinct Characters
// Taught fully in C++ on 2026-10-31 (Amazon prep, sliding-window pattern).
// Pattern: sliding window + frequency map.
// Idea: expand right, counting characters. While the window holds more than
// k distinct characters, shrink from the left (dropping a character whose
// count falls to zero). Track the longest valid window.
// Time: O(n). Space: O(k) distinct characters in the map.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int lengthOfLongestSubstringKDistinct(const std::string& s, int k) {
    if (k == 0 || s.empty()) return 0;
    std::unordered_map<char, int> count;
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        count[s[right]]++;
        while ((int)count.size() > k) {
            if (--count[s[left]] == 0) count.erase(s[left]);
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    struct Case { std::string s; int k; int want; };
    const Case cases[] = {
        {"eceba", 2, 3}, {"aa", 1, 2}, {"a", 0, 0},
        {"abaccc", 2, 4}, {"abcdef", 3, 3}, {"", 2, 0},
    };
    int failed = 0;
    for (const auto& tc : cases) {
        int got = lengthOfLongestSubstringKDistinct(tc.s, tc.k);
        std::cout << "\"" << tc.s << "\", k=" << tc.k << " -> " << got
                  << (got == tc.want ? " OK" : " FAIL (want " + std::to_string(tc.want) + ")")
                  << "\n";
        if (got != tc.want) ++failed;
    }
    return failed;
}
