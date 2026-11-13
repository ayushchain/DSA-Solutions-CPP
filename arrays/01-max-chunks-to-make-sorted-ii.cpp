// Max Chunks To Make Sorted II (LeetCode 768)
// Taught fully in C++ on 2026-11-13 (LeetCode prep), then solved and
// submitted by me — Accepted (Hard).
// Pattern: sorting + frequency balance.
// Idea: a chunk can end exactly where the multiset of elements seen so
// far in the original array equals the multiset in the sorted array at
// the same position. Keep a difference map: +1 for the original
// element, -1 for the sorted element; whenever no non-zero entries
// remain, the two multisets match and we can cut a chunk.
// (The simpler max-so-far trick from problem 769 fails here because
// duplicates are allowed.)
// Time: O(n log n) for the sort. Space: O(n).
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int maxChunksToSorted(std::vector<int>& arr) {
    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());

    std::unordered_map<int, int> diff;
    int nonZero = 0, chunks = 0;
    auto add = [&](int x, int delta) {
        if (diff[x] == 0) ++nonZero;
        diff[x] += delta;
        if (diff[x] == 0) --nonZero;
    };
    for (int i = 0; i < (int)arr.size(); ++i) {
        add(arr[i], +1);
        add(sorted[i], -1);
        if (nonZero == 0) ++chunks;
    }
    return chunks;
}

int main() {
    struct Case { std::vector<int> a; int want; const char* name; };
    std::vector<Case> cases = {
        {{2, 1, 3, 4, 4}, 4, "[2,1,3,4,4]"},
        {{5, 4, 3, 2, 1}, 1, "[5,4,3,2,1]"},
        {{1, 2, 3, 4}, 4, "[1,2,3,4]"},
        {{1, 1, 1}, 3, "[1,1,1]"},
        {{0, 0, 1, 1, 1}, 5, "[0,0,1,1,1]"},
    };
    int failures = 0;
    for (auto& c : cases) {
        int got = maxChunksToSorted(c.a);
        bool ok = (got == c.want);
        if (!ok) ++failures;
        std::cout << (ok ? "OK   " : "FAIL ") << c.name << " -> " << got
                  << " (want " << c.want << ")\n";
    }
    return failures ? 1 : 0;
}
