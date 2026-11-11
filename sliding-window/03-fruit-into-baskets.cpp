// Fruit Into Baskets (LeetCode 904)
// Taught fully in C++ on 2026-10-31 (Amazon prep, sliding-window pattern).
// Pattern: sliding window with at most 2 distinct values — the same window
// as "at most K distinct" with k = 2, applied to an array of fruit types.
// Idea: expand right, counting fruit types in the basket. While more than
// 2 types are present, shrink from the left. Track the longest valid run.
// Time: O(n). Space: O(1) — at most 2 types are ever tracked.
#include <iostream>
#include <unordered_map>
#include <vector>

int totalFruit(const std::vector<int>& fruits) {
    std::unordered_map<int, int> count;
    int left = 0, best = 0;
    for (int right = 0; right < (int)fruits.size(); ++right) {
        count[fruits[right]]++;
        while ((int)count.size() > 2) {
            if (--count[fruits[left]] == 0) count.erase(fruits[left]);
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    struct Case { std::vector<int> fruits; int want; };
    const Case cases[] = {
        {{1, 2, 1}, 3}, {{0, 1, 2, 2}, 3}, {{1, 2, 3, 2, 2}, 4},
        {{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}, 5}, {{}, 0},
    };
    int failed = 0;
    for (const auto& tc : cases) {
        int got = totalFruit(tc.fruits);
        std::cout << "-> " << got
                  << (got == tc.want ? " OK" : " FAIL (want " + std::to_string(tc.want) + ")")
                  << "\n";
        if (got != tc.want) ++failed;
    }
    return failed;
}
