// BST implementation - Insertion, Deletion, Searching, Traversals
// Author - rudrajit1729

#include<iostream>
using namespace std;

// Utility structure to represent Node of BST
struct Node{
    Node(int key): value(key), left(NULL), right(NULL){}
    int value;
    Node *left;
    Node *right;
};

// BST class
class BST{
    private:
        Node *root;
        Node* insert(Node *node, int val);
        Node* deleteNode(Node *node, int val);
        int findNode(Node *node, int key);
        void inorder(Node *node);
        void preorder(Node *node);
        void postorder(Node *node);
    public:
        BST(); // Constructor
        //~BST(); // Destructor
        Node* minValNode(Node *node);
        Node* insert(int val){root = insert(root, val);}
        Node* deleteNode(int val){root = deleteNode(root, val);}
        void inorder(){inorder(root);}
        void preorder(){preorder(root);}
        void postorder(){postorder(root);}
        int findNode(int key){findNode(root, key);}
};

BST::BST()
{
    root = NULL;
}

// Utility function to add nodes in BST
Node* BST::insert(Node *root, int val)
{
    // Base case
    if (root == NULL){
        root = new Node(val);
        return root;
        
    }
    // If value less than root, it goes in left subtree
    if (root->value > val)
    {
        if (root->left == NULL)
            root->left = new Node(val);
        else
            root->left = insert(root->left, val);
    }
    // Else goes in right subtree
    else
    {
        if (root->right == NULL)
            root->right = new Node(val);
        else
            root->right = insert(root->right, val);
    }
    return root;
}

// Utility functions for traversals
void BST::inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->value<<"\t";
        inorder(root->right);
    }
}

void BST::preorder(Node *root)
{
    if (root != NULL)
    {
        cout<<root->value<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void BST::postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->value<<"\t";
    }
}

// Utility function to find presence of node
int BST::findNode(Node *root, int key)
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
Node *BST:: minValNode(Node *root)
{
    Node *curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}
// Utility function to delete a node from BST
Node*BST:: deleteNode(Node *root, int key)
{
    // Base Case
    if (root == NULL) return root;

    // If key is smaller than root value look in left subtree
    if (root->value > key)
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
        return root;
    }
    
}


int main()
{
    /*

                  49
               /      \
             46       79
            /  \      /  \
         43   45     64  83

    */
    BST tree;
    // Insertion
    tree.insert(49);
    tree.insert(46);
    tree.insert(43);
    tree.insert(45);
    tree.insert(79);
    tree.insert(64);
    tree.insert(83);
    
    //Traversals
    cout<<"\nInorder\n";
    tree.inorder();
    cout<<"\nPreorder\n";
    tree.preorder();
    cout<<"\nPostorder\n";
    tree.postorder();   

    // Searching
    cout<<"\nFinding 46 : "<<tree.findNode(46)<<endl;
    cout<<"Finding 78 : "<<tree.findNode(78)<<endl;

    // Deleting node
    tree.deleteNode(43);//No child
    cout<<"Inorder:\n";
    tree.inorder();
    tree.deleteNode(46); // 1 child
    cout<<"\nInorder:\n";
    tree.inorder();
    tree.deleteNode(79); // 2 children
    cout<<"\nInorder:\n";
    tree.inorder();

}