/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        if (!root) return {};
    
    map<int, vector<int>> diagonalMap;
    
    function<void(Node*, int)> dfs = [&](Node* node, int diagonal) {
        if (!node) return;
        
        // Add current node to its diagonal
        diagonalMap[diagonal].push_back(node->data);
        
        // Process left subtree first (next diagonal)
        dfs(node->left, diagonal + 1);
        
        // Then process right subtree (same diagonal)
        dfs(node->right, diagonal);
    };
    
    dfs(root, 0);
    
    vector<int> result;
    for (auto& pair : diagonalMap) {
        result.insert(result.end(), pair.second.begin(), pair.second.end());
    }
    
    return result;
    }
};