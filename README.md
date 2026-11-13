# DSA Solutions in C++

My own solutions from Amazon SDE Intern interview prep (NIT Patna '27).
Every problem here was first taught fully, then solved — no copied code.
Language: C++17. One file per problem, each with its own runnable tests.

## How to run

```bash
g++ -std=c++17 -O2 -Wall sliding-window/01-longest-substring-without-repeating.cpp -o /tmp/p1 && /tmp/p1
```

Each file prints `OK` per test case and exits non-zero if any case fails.

## Contents

### Sliding Window (taught 29–31 Oct 2026)
| # | Problem | Status |
|---|---------|--------|
| 01 | Longest Substring Without Repeating Characters | ✅ solved — sliding window + last-seen index, O(n). Remember the `"abba"` edge case: left never moves backwards. |
| 02 | Longest Substring with At Most K Distinct Characters | ✅ solved — sliding window + frequency map, O(n) |
| 03 | Fruit Into Baskets | ✅ solved — same window with k = 2, O(n) |
| 04 | Longest Repeating Character Replacement | ⏳ practice — mock pending, Step 1 approach first, no solution yet |

### Trees (started 13 Nov 2026)
| # | Problem | Status |
|---|---------|--------|
| 01 | Validate Binary Search Tree (LeetCode 98) | ✅ solved — DFS + bounds propagation, O(n). Trap to remember: parent-only checks pass [10,5,15,null,null,6,20]; bounds catch it. |

### Arrays & Sorting (started 13 Nov 2026)
| # | Problem | Status |
|---|---------|--------|
| 01 | Max Chunks To Make Sorted II (LeetCode 768) | ✅ solved — sorting + frequency balance, O(n log n). The 769 max-so-far trick fails here because duplicates are allowed. |

### Dynamic Programming (started 13 Nov 2026)
| # | Problem | Status |
|---|---------|--------|
| 01 | Palindrome Partitioning II (LeetCode 132) | ✅ solved — palindrome table + minimum-cuts DP, O(n²). Trick to remember: dp[0] = −1 makes a fully-palindromic string give 0 cuts. |

## Next (in prep-plan order)
Two Pointers, more Trees and DP — taught fully first, then one mock, same as above.

## Prep plan
`Amazon_Interview_Prep_Plan.md` — the full pattern order (arrays/hashmap,
sliding window, two pointers, stack/queue, linked list, binary search,
trees, heap, backtracking, graphs, DP) and the Leadership Principles stories.
