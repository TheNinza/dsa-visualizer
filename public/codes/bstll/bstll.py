# Python program to insert, delete and search in binary search tree using linked lists

# A Binary Tree Node


class Node:

    # Constructor to create a new node
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# A utility function to do inorder traversal of BST
def inorder(root):
    if root is not None:
        inorder(root.left)
        print(root.key, end=', ')
        inorder(root.right)


# A utility function to insert a
# new node with given key in BST
def insert(node, key):

    # If the tree is empty, return a new node
    if node is None:
        return Node(key)

    # Otherwise recur down the tree
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    # return the (unchanged) node pointer
    return node


# Given a non-empty binary
# search tree, return the node
# with maximun key value
# found in that tree. Note that the
# entire tree does not need to be searched

def maxValueNode(node):
    current = node

    # loop down to find the rightmost leaf
    while(current.right is not None):
        current = current.right

    return current


# Given a binary search tree and a key, this function
# delete the key and returns the new root

def deleteNode(root, key):

    # Base Case
    if root is None:
        return root

    # If the key to be deleted
    # is smaller than the root's
    # key then it lies in left subtree
    if key < root.key:
        root.left = deleteNode(root.left, key)

    # If the kye to be delete
    # is greater than the root's key
    # then it lies in right subtree
    elif(key > root.key):
        root.right = deleteNode(root.right, key)

    # If key is same as root's key, then this is the node
    # to be deleted
    else:

        # Node with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # Node with two children:
        # Get the inorder predecessor
        # (largest in the left subtree)
        temp = maxValueNode(root.left)

        # Copy the inorder predecessor's
        # content to this node
        root.key = temp.key

        # Delete the inorder predecessor
        root.left = deleteNode(root.left, temp.key)

    return root

# Given a binary search tree and a key, this function
# returns whether the key exists in the tree or not


def searchNode(root, key):
    if key == root.key:
        return True
    elif root.right == None and root.left == None:
        return False
    elif key > root.key and root.right != None:
        return searchNode(root.right, key)
    elif key < root.key and root.left != None:
        return searchNode(root.left, key)
    return False


# Driver code
# Lets create tree:
#              4
# 		    /	  \
# 	        2      6
# 		   / \    / \
# 	      0   3  5  10
#                  /  \
#                 8   12
#                /  \
#               7    9

root = None
root = insert(root, 4)
root = insert(root, 2)
root = insert(root, 6)
root = insert(root, 10)
root = insert(root, 8)
root = insert(root, 0)
root = insert(root, 3)
root = insert(root, 5)
root = insert(root, 7)
root = insert(root, 9)
root = insert(root, 12)

print("Inorder traversal of the given tree")
inorder(root)

print("\nDelete 2")
root = deleteNode(root, 2)
print("Inorder traversal of the modified tree")
inorder(root)

print("\nDelete 3")
root = deleteNode(root, 3)
print("Inorder traversal of the modified tree")
inorder(root)

print("\nDelete 10")
root = deleteNode(root, 10)
print("Inorder traversal of the modified tree")
inorder(root)
print("\n12 exists in bst? : ", searchNode(root, 12))


# Output:
# Inorder traversal of the given tree
# 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12,
# Delete 2
# Inorder traversal of the modified tree
# 0, 3, 4, 5, 6, 7, 8, 9, 10, 12,
# Delete 3
# Inorder traversal of the modified tree
# 0, 4, 5, 6, 7, 8, 9, 10, 12,
# Delete 10
# Inorder traversal of the modified tree
# 0, 4, 5, 6, 7, 8, 9, 12,
# 12 exists in bst? :  True
