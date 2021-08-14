# Python code for AVL Tree insertion and deletion

# Generic tree node class
class TreeNode(object):
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

# AVL tree class which supports insertion,
# deletion operations


class AVL_Tree(object):

    def insert(self, root, key):

        # Step 1 - Perform normal BST
        if not root:
            return TreeNode(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)

        # Step 2 - Update the height of the
        # ancestor node
        root.height = 1 + max(self.getHeight(root.left),
                              self.getHeight(root.right))

        # Step 3 - Get the balance factor
        balance = self.getBalance(root)

        # Step 4 - If the node is unbalanced,
        # then try out the 4 cases
        # Case 1 - Left Left
        if balance > 1 and key < root.left.key:
            return self.rightRotate(root)

        # Case 2 - Right Right
        if balance < -1 and key > root.right.key:
            return self.leftRotate(root)

        # Case 3 - Left Right
        if balance > 1 and key > root.left.key:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)

        # Case 4 - Right Left
        if balance < -1 and key < root.right.key:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root

    # Recursive function to delete a node with
    # given key from subtree with given root.
    # It returns root of the modified subtree.
    def delete(self, root, key):

        # Step 1 - Perform standard BST delete
        if not root:
            return root

        elif key < root.key:
            root.left = self.delete(root.left, key)

        elif key > root.key:
            root.right = self.delete(root.right, key)

        else:
            if root.left is None:
                temp = root.right
                root = None
                return temp

            elif root.right is None:
                temp = root.left
                root = None
                return temp

            temp = self.getMaxValueNode(root.left)
            root.key = temp.key
            root.left = self.delete(root.left, temp.key)

        # If the tree has only one node,
        # simply return it
        if root is None:
            return root

        # Step 2 - Update the height of the
        # ancestor node
        root.height = 1 + max(self.getHeight(root.left),
                              self.getHeight(root.right))

        # Step 3 - Get the balance factor
        balance = self.getBalance(root)

        # Step 4 - If the node is unbalanced,
        # then try out the 4 cases
        # Case 1 - Left Left
        if balance > 1 and self.getBalance(root.left) >= 0:
            return self.rightRotate(root)

        # Case 2 - Right Right
        if balance < -1 and self.getBalance(root.right) <= 0:
            return self.leftRotate(root)

        # Case 3 - Left Right
        if balance > 1 and self.getBalance(root.left) < 0:
            root.left = self.leftRotate(root.left)
            return self.rightRotate(root)

        # Case 4 - Right Left
        if balance < -1 and self.getBalance(root.right) > 0:
            root.right = self.rightRotate(root.right)
            return self.leftRotate(root)

        return root

    def leftRotate(self, z):

        y = z.right
        T2 = y.left

        # Perform rotation
        y.left = z
        z.right = T2

        # Update heights
        z.height = 1 + max(self.getHeight(z.left),
                           self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left),
                           self.getHeight(y.right))

        # Return the new root
        return y

    def rightRotate(self, z):

        y = z.left
        T3 = y.right

        # Perform rotation
        y.right = z
        z.left = T3

        # Update heights
        z.height = 1 + max(self.getHeight(z.left),
                           self.getHeight(z.right))
        y.height = 1 + max(self.getHeight(y.left),
                           self.getHeight(y.right))

        # Return the new root
        return y

    def getHeight(self, root):
        if not root:
            return 0

        return root.height

    def getBalance(self, root):
        if not root:
            return 0

        return self.getHeight(root.left) - self.getHeight(root.right)

    def getMaxValueNode(self, root):
        if root is None or root.right is None:
            return root

        return self.getMaxValueNode(root.right)

    def preOrder(self, root):

        if not root:
            return

        print(root.key, end=" ")
        self.preOrder(root.left)
        self.preOrder(root.right)


myTree = AVL_Tree()
root = None

# Lets create tree:
#              4
#		    /	  \
#	        2      6
#		   / \    / \
#	      0   3  5  10
#                  /  \
#                  8   12
#                /  \
#               7    9

root = myTree.insert(root, 4)
root = myTree.insert(root, 2)
root = myTree.insert(root, 6)
root = myTree.insert(root, 10)
root = myTree.insert(root, 8)
root = myTree.insert(root, 0)
root = myTree.insert(root, 3)
root = myTree.insert(root, 5)
root = myTree.insert(root, 7)
root = myTree.insert(root, 9)
root = myTree.insert(root, 12)

# It will convert to
#               4
#		    /	   \
#	       2        8
#		  / \     /    \
#	     0   3   6      10
#               / \     /  \
#              5   7   9   12
#

# Preorder Traversal
print("Preorder traversal of the constructed AVL tree is")
myTree.preOrder(root)
print()

# Delete
root = myTree.delete(root, 2)

# Preorder Traversal
print("Preorder traversal after deletion of 2")
myTree.preOrder(root)
print()

# Output:
# Preorder traversal of the constructed AVL tree is
# 4 2 0 3 8 6 5 7 10 9 12
# Preorder traversal after deletion of 2
# 4 0 3 8 6 5 7 10 9 12
