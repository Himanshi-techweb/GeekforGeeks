class Node{
    public:
   int data;
   Node* left;
   Node* right;
   Node(int data){
       this->data=data;
       this->left=NULL;
       this->right=NULL;
   }
};

class Solution {
  public:
    void inorder(Node* root, vector<int> &in){
        if(root == NULL) return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
    Node* buildtree(int i, vector<int> &arr){
        if(i >= arr.size()) return NULL;
        Node* newnode = new Node(arr[i]);
        newnode->left = buildtree(2*i + 1, arr);
        newnode->right = buildtree(2*i + 2, arr);
        return newnode;
    }
    
    int minSwaps(vector<int>& arr) {
        // Build tree from array
        Node* node = buildtree(0, arr);
        
        // Get inorder traversal
        vector<int> in_bt;
        inorder(node, in_bt);
        
        // Create array of pairs (value, original_index) to handle duplicates
        vector<pair<int, int>> value_index_pairs;
        for(int i = 0; i < in_bt.size(); i++){
            value_index_pairs.push_back({in_bt[i], i});
        }
        
        // Sort by value to get target positions
        sort(value_index_pairs.begin(), value_index_pairs.end());
        
        // Create position tracking arrays
        vector<int> position(in_bt.size());  // position[i] = current position of element originally at i
        vector<int> reverse_pos(in_bt.size()); // reverse_pos[i] = which original element is currently at position i
        
        for(int i = 0; i < in_bt.size(); i++){
            position[i] = i;
            reverse_pos[i] = i;
        }
        
        int swaps = 0;
        
        for(int i = 0; i < value_index_pairs.size(); i++){
            int original_pos = value_index_pairs[i].second;
            int current_pos = position[original_pos];
            
            if(current_pos == i) continue;
            
            // Find what's currently at position i - O(1) lookup now!
            int other_original_pos = reverse_pos[i];
            
            // Swap positions
            position[original_pos] = i;
            position[other_original_pos] = current_pos;
            
            // Update reverse mapping
            reverse_pos[i] = original_pos;
            reverse_pos[current_pos] = other_original_pos;
            
            swaps++;
        }
        
        return swaps;
    }
};