# Sliding Window — Pattern Notes

My notes from interview prep. The rule I follow: understand the pattern fully first, then solve.

## When to use it
- The problem asks about a **contiguous** subarray / substring
- There is a condition on the window: distinct elements, at most K distinct, a sum limit, etc.
- Brute force would recheck overlapping parts again and again — a window reuses that work

## The core idea
Keep two pointers, `left` and `right`. Expand `right` one step at a time.
If the window breaks the condition, shrink from `left` until it is valid again.
The answer is the best valid window seen. Each pointer moves at most n times, so the total work is **O(n)**.

## Variable-size window template
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // include s[right] in the window (update counts)
    while (windowInvalid()) {
        // remove s[left] from the window, then left++
    }
    ans = max(ans, right - left + 1);
}
```

## What I learned from each problem
1. **Longest Substring Without Repeating Characters** — window + last-seen index.
   Edge case `"abba"`: `left` must never move backwards — take `max(left, lastSeen[c] + 1)`.
2. **Longest Substring with At Most K Distinct Characters** — frequency map;
   the window is invalid while the distinct count is greater than k.
3. **Fruit Into Baskets** — the same problem as #2 with k = 2, just dressed as a story.
   Recognising the pattern under a story is the real skill.

## Mistakes to avoid
- Updating the answer while the window is invalid
- Forgetting that a count reaching 0 must erase the key, otherwise the distinct count goes wrong
- Moving `left` backwards

## Next
Two Pointers — after the pending mock (Longest Repeating Character Replacement).
