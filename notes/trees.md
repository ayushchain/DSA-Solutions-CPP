# Trees — Pattern Notes

My notes from interview prep. The rule I follow: understand the pattern fully first, then solve.

## Core traversals
- **Inorder** (left, root, right) — on a BST this visits values in sorted order
- **Preorder** (root, left, right), **Postorder** (left, right, root), **Level order** (BFS, queue)

## BST validation — the bounds idea
A BST is not just "left child < node < right child" at every parent. Every node
inherits a full allowed range from ALL its ancestors:
- Start with range (-inf, +inf) at the root
- Going left: the node's value becomes the new upper bound
- Going right: the node's value becomes the new lower bound
- A node outside its range means the tree is not a valid BST

Classic trap: `[10,5,15,null,null,6,20]` — 6 is a valid right child of 15
locally, but it sits in 10's right subtree while being smaller than 10.
Parent-only checks pass it; bounds catch it.

Implementation notes:
- Use `long long` bounds so a node equal to INT_MIN or INT_MAX is handled
- Bounds are strict — duplicates do not make a valid BST (LeetCode's rule)

## Solved
1. **Validate Binary Search Tree (98)** — DFS + bounds propagation, O(n) time, O(h) stack.
