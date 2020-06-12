# BST implementation - insertion, finding, traversals, deletion
# Author - rudrajit1729

# Utility class represents individual nodes in BST
class Node:
    def __init__(self, key = 0):
        self.left = None
        self.right = None
        self.value = key 

# Utility function to insert node in BST
def insert(root, value):
    # Base Case
    if root is None:
        return Node(value)
    # Value smaller than root, goes into left subtree
    if root.value > value:
        if root.left is None:
            root.left = Node(value)
        else:
            root.left = insert(root.left, value)
    # value larger than or equal to root, goes into right subtree
    else:
        if root.right is None:
            root.right = Node(value)
        else:
            root.right = insert(root.right, value)
    return root

# Utility functions for traversals
def inorder(root):
    if root:
        inorder(root.left)
        print(root.value, end = " ")
        inorder(root.right)

def preorder(root):
    if root:
        print(root.value, end = " ")
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.value, end = " ")

# Getting the minimum value node of the tree
def minValNode(root):
    curr = root
    while curr.left:
        curr = curr.left
    return curr

# Utility function for deleting a node
def delete(root, key):
    # Base Case
    if root is None:
        return root
    # If key is smaller than root value it's in left subtree
    if key < root.value:
        root.left = delete(root.left, key)
    # If key is larger than root value it's in right subtree
    elif key > root.value:
        root.right = delete(root.right, key)
    # Key matches the root value
    else:
        # Node with one or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp
        elif root.right is None:
            temp = root.left
            root = None
            return temp
        
        # Node with two children: Replace by inorder successor(smallest in right subtree)
        temp = minValNode(root.right)
        # Value of the inorder successor stored in node
        root.value = temp.value
        # Delete the inorder successor from the right subtree
        root.right = delete(root.right, temp.value)

    return root

# Utility function for finding a key in BST
def findNode(root, key):
    if root is None:
        return False
    if key < root.value:
        return findNode(root.left, key)
    elif key > root.value:
        return findNode(root.right, key)
    else:
        return True

# Demonstration method
def main():
    r'''

                  49
               /      \
             46       79
            /  \      /  \
         43   45     64  83

    '''
    root = None
    root = insert(root, 49)
    root = insert(root, 46)
    root = insert(root, 43)
    root = insert(root, 45)
    root = insert(root, 79)
    root = insert(root, 64)
    root = insert(root, 83)
    print("In order traversal")
    inorder(root)
    root = delete(root, 43)
    print("\nIn order traversal")
    inorder(root)
    root = delete(root, 46)
    print("\nIn order traversal")
    inorder(root)
    root = delete(root, 79)
    print("\nIn order traversal")
    inorder(root)

    print("\nFinding a node demo:\n")
    print("Finding 83 : ", findNode(root, 83))
    print("\nFinding 43 : ", findNode(root, 43))


if __name__ == "__main__":
    main()