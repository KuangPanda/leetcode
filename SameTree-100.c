/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool left = true;
    bool right = true;
    
    if (!p && !q) {
        return true;
    } else if (!p && q) {
        return false;
    } else if (p && !q) {
        return false;
    } else if (p -> val != q -> val) {
        return false;
    } else {
        left = isSameTree(p -> left, q -> left);
        right = isSameTree(p -> right, q -> right);
        return (left && right);
    }
    return (left&&right);
}