# Dynamic Programming — Pattern Notes

My notes from interview prep. The rule I follow: understand the pattern fully first, then solve.

## What DP is
Break the problem into smaller versions of itself, solve each once, store the
answer, and build up. Two questions to ask:
1. What does `dp[i]` mean, in one exact sentence?
2. How does `dp[i]` follow from smaller answers (the transition)?

## Palindrome Partitioning II (132) — the two-table shape
- **Table 1 (facts):** `pal[i][j]` — is `s[i..j]` a palindrome?
  `pal[i][j] = (s[i] == s[j]) && (length <= 3 || pal[i+1][j-1])`
- **Table 2 (answer):** `dp[i]` — minimum cuts for the first `i` characters.
  If `s[j..i-1]` is a palindrome, `dp[i] = min(dp[i], dp[j] + 1)`.
- Trick worth remembering: set `dp[0] = -1` (empty string). Then a string that
  is itself a palindrome gets `-1 + 1 = 0` cuts with no special case.
- Greedy fails here: cutting the longest palindrome first is not always optimal,
  which is exactly why the full DP over all cut positions is needed.

## Solved
1. **Palindrome Partitioning II (132)** — palindrome table + cuts DP, O(n²) time and space.
