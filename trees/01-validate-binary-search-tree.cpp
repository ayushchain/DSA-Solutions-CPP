// Validate Binary Search Tree (LeetCode 98)
// Taught fully in C++ on 2026-11-13 (LeetCode prep), then solved and
// submitted by me — Accepted.
// Pattern: DFS with valid-range (bounds) propagation.
// Idea: every node must lie strictly inside an allowed range (low, high).
// Going left tightens the high bound to the node's value; going right
// tightens the low bound. Comparing a node only with its parent is NOT
// enough — a node deep in the right subtree can still break the root's
// lower bound (classic trap: [10,5,15,null,null,6,20] -> false).
// Bounds use long long so nodes equal to INT_MIN / INT_MAX stay valid.
// Time: O(n). Space: O(h) recursion stack, h = tree height.
#include <climits>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

bool dfs(TreeNode* node, long long low, long long high) {
    if (!node) return true;
    if (node->val <= low || node->val >= high) return false;
    return dfs(node->left, low, node->val) &&
           dfs(node->right, node->val, high);
}

bool isValidBST(TreeNode* root) {
    return dfs(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    // [2,1,3] -> true
    TreeNode* t1 = new TreeNode(2);
    t1->left = new TreeNode(1);
    t1->right = new TreeNode(3);
    // [5,1,4,null,null,3,6] -> false
    TreeNode* t2 = new TreeNode(5);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(4);
    t2->right->left = new TreeNode(3);
    t2->right->right = new TreeNode(6);
    // [10,5,15,null,null,6,20] -> false (6 is in 10's right subtree but < 10)
    TreeNode* t3 = new TreeNode(10);
    t3->left = new TreeNode(5);
    t3->right = new TreeNode(15);
    t3->right->left = new TreeNode(6);
    t3->right->right = new TreeNode(20);
    // [1] -> true
    TreeNode* t4 = new TreeNode(1);
    // [2147483647] -> true (single node at INT_MAX; needs long long bounds)
    TreeNode* t5 = new TreeNode(INT_MAX);

    struct Case { TreeNode* root; bool want; const char* name; };
    const Case cases[] = {
        {t1, true, "[2,1,3]"},
        {t2, false, "[5,1,4,null,null,3,6]"},
        {t3, false, "[10,5,15,null,null,6,20]"},
        {t4, true, "[1]"},
        {t5, true, "[INT_MAX]"},
    };
    int failures = 0;
    for (const auto& c : cases) {
        bool got = isValidBST(c.root);
        bool ok = (got == c.want);
        if (!ok) ++failures;
        std::cout << (ok ? "OK   " : "FAIL ") << c.name
                  << " -> " << (got ? "true" : "false")
                  << " (want " << (c.want ? "true" : "false") << ")\n";
    }
    return failures ? 1 : 0;
}
