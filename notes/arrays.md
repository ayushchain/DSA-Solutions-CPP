# Arrays & Sorting — Pattern Notes

My notes from interview prep. The rule I follow: understand the pattern fully first, then solve.

## Max Chunks To Make Sorted II (768) — frequency balance
Goal: cut the array into the most chunks so that sorting each chunk and
joining them gives the fully sorted array.

- A cut is legal exactly where the **multiset** of elements so far equals the
  multiset of the sorted array over the same positions.
- Implementation: walk both arrays together, keeping a difference map
  (+1 for the original element, −1 for the sorted one). When every entry is
  zero again, the multisets match — cut there.
- Why not the 769 trick? Problem 769 has all-distinct elements, so
  "max so far == index" is enough. With **duplicates** (768), only the
  frequency balance is correct.

## Solved
1. **Max Chunks To Make Sorted II (768)** — sorting + frequency balance, O(n log n) time, O(n) space.
