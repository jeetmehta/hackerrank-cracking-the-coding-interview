/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

void traverseInOrder(Node* current, vector <int> &tree)
{
    if (current == 0)
        return;
    else
    {        
        // Left Child
        traverseInOrder(current->left, tree);
        
        // Current Node
        tree.push_back(current->data);
        
        // Right Child
        traverseInOrder(current->right, tree);
    }
}

// Go through sorted array, if any element is greater than it's previous -> not a valid BST!
bool checkIfBST(vector <int> tree)
{
    for (int i = 1; i < tree.size(); i++)
    {
        if (tree[i] <= tree[i-1])
            return false;
    }
    return true;
}

bool checkBST(Node* root) {
    
    // Empty tree
    if (root == 0)
        return true;

    // Only root in tree
    else if (root->left == 0 && root->right == 0)
        return true;

    else
    {
        vector <int> tree;
        traverseInOrder(root, tree);
        return checkIfBST(tree);
    }
    return true;
}