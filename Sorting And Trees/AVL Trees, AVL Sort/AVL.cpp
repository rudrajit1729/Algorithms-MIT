// BST implementation - Insertion, Deletion, Searching, Traversals
// Author - rudrajit1729

#include<iostream>
#include<vector>
#define max(a, b) a>b?a:b
using namespace std;

// Utility structure to represent Node of BST
struct Node{
    Node(int key): value(key), height(1), left(NULL), right(NULL){}
    int value;
    int height;
    Node *left;
    Node *right;
};

// AVL tree Class
class AVL_Tree
{
private:
    Node *root;
    Node* insert(Node *node, int val);
    Node* deleteNode(Node *node, int val);
    int findNode(Node *node, int key);
    void inorder(Node *node);
    void preorder(Node *node);
    void postorder(Node *node);
public:
    AVL_Tree(); // Constructor
    Node* leftRotate(Node *node);
    Node* rightRotate(Node *node);
    int getHeight(Node *node);
    int getBalance(Node *node);
    Node* minValNode(Node *node);
    Node* insert(int val){root = insert(root, val);}
    Node* deleteNode(int val){root = deleteNode(root, val);}
    void inorder(){inorder(root);}
    void preorder(){preorder(root);}
    void postorder(){postorder(root);}
    int findNode(int key){findNode(root, key);}
};

AVL_Tree::AVL_Tree()
{
    root = NULL;
}

// Utility functions for traversals
void AVL_Tree::inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->value<<"\t";
        inorder(root->right);
    }
}

void AVL_Tree::preorder(Node *root)
{
    if (root != NULL)
    {
        cout<<root->value<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void AVL_Tree::postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<"\t";
    }
}

// Utility function to find a node
int AVL_Tree::findNode(Node *root, int key)
{
    // Base case
    if (root==NULL) return 0;
    // If key less than root value look in left subtree
    if (root->value < key)
        return findNode(root->left, key);
    // If key greater than root value look in right subtree
    else if(root->value > key)
        return findNode(root->right, key);
    // Else found
    else
        return 1;
}

// Getting minimum Value node w.r.t. a node
Node *AVL_Tree:: minValNode(Node *root)
{
    Node *curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Getting height of a node
int AVL_Tree::getHeight(Node *root)
{
    if (root == NULL) return 0;
    return root->height;
}

// Getting Balance Factor of a node 
// Diff in height between Left and Right sub trees
int AVL_Tree::getBalance(Node *root)
{
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

// Utility functions for rotations
Node * AVL_Tree::leftRotate(Node *root)
{
    Node *new_root = root->right;
    Node *lsubTree = new_root->left;

    // Perform Rotations
    new_root->left = root;
    root->right = lsubTree;

    // Update Heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    new_root->height = 1 + max(getHeight(new_root->left), getHeight(new_root->right));

    // Return the new root
    return new_root; 
}

Node * AVL_Tree::rightRotate(Node *root)
{
    Node *new_root = root->left;
    Node *rsubTree = new_root->right;

    // Perform Rotations
    new_root->right = root;
    root->left = rsubTree;

    // Update Heights
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    new_root->height = 1 + max(getHeight(new_root->left), getHeight(new_root->right));

    // Return the new root
    return new_root; 
}

// Utility function to insert node
Node *AVL_Tree::insert(Node *root, int key)
{
    // Step 1 - Perform normal BST insert

    // Base Case
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }
    // Key less than root value - insert in left subtree
    else if (key < root->value)
        root->left = insert(root->left, key);
    // Key greater or equal to root value - insert in right subtree
    else
        root->right = insert(root->right, key);
    
    // Step 2 - Update Heights of ancestors
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Step 3 - Get Balance Factor

    int balance = getBalance(root);

    // Step 4 - If node is unbalanced, then perform 4 cases 
    // Case 1 - Left Left
    if (balance > 1 && key < root->left->value)
        return rightRotate(root);
    
    // Case 2 - Right Right
    if (balance < -1 && key > root->right->value)
        return leftRotate(root);
    
    // Case 3 - Left Right
    if (balance > 1 && key > root->left->value)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4 - Right Left
    if (balance < -1 && key < root->right->value)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
    
}

// Utility function to delete a node
Node * AVL_Tree::deleteNode(Node *root, int key)
{
    // Step 1 - Perform Standard BST delete

    // Base Case
    if (root == NULL) return root;
    // If key smaller than root value delete from left subtree
    if (key < root->value)
        root->left = deleteNode(root->left, key);
    // Else if key is larger than root value look in right subtree
    else if (root->value < key)
        root->right = deleteNode(root->right, key);
    // Else present node is the node to be deleted
    else
    {
        // If node has one or no children
        if (root->left == NULL)
        {
            Node * temp = root->right;
            root = NULL;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node * temp = root->left;
            root = NULL;
            return temp;
        }
        // Node has two children
        // Replace root by inorder successor - Lowest key in right subtree
        else
        {
            // Get inorder successor
            Node * temp = minValNode(root->right);
            // Copy value from temp into root
            root->value = temp->value;
            // Delete temp value from right subtree
            root->right = deleteNode(root->right, temp->value);
        }
    }
    // If tree has only one node simply return it
    if (root == NULL) return root;

    // Step 2 - Update height of the ancestors
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Step 3 - Get Balance Factor

    int balance = getBalance(root);

    // Step 4 - If node is unbalanced, then perform 4 cases

    // Case 1 - Left Left
    if(balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);

    // Case 2 - Right Right
    if(balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);

    // Case 3 - Left Right
    if(balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Case 4 - Right Left
    if(balance < -1 && getBalance(root->right) > 0) 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

// Utility function
void traversal(AVL_Tree tree)
{
    cout<<"Inorder Traversal :\n";
    tree.inorder();
    cout<<endl;
}

// Demonstration 
int main()
{
    /*
    AVL tree:
                30
             /      \
            20       40
          /    \    /  \
        10     25  38   50
    */
    AVL_Tree tree;

    // Insertion
    vector<int> nums = {10, 20, 30, 40, 50, 25, 38};
    for(int x : nums)
    {
        tree.insert(x);
    }

    // Traversal
    traversal(tree);

    // Deletion
    tree.deleteNode(10); // No children
    traversal(tree);
    tree.deleteNode(20); // 1 child
    traversal(tree);
    tree.deleteNode(40); // 2 children
    traversal(tree);

    // Searching
    cout<<"Finding 30 : "<<tree.findNode(30)<<endl;
    cout<<"Finding 40 : "<<tree.findNode(40)<<endl;
}

















