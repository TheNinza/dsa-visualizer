# Python code for Binary Search Tree using Array

bst = [None for i in range(10000)]  # Empty Array for tree

i = 1  # To store index to which data is last inserted


# function to add an element
def insert(data):
    global bst

    # if bst is empty add root node
    if bst[1] == None:
        bst[1] = data

    # Traverse if tree not empty
    else:
        global i
        i = 1
        currvalue = bst[1]
        # Loop until you reach an empty space or data already exists
        while bst[i] != None and bst[i] != data:
            if data < currvalue:  # Traverse left subtree if data is less than current node
                currvalue = bst[2*i]
                i = 2*i
            elif data > currvalue:  # Traverse right subtree if data is greater than current node
                currvalue = bst[(2*i)+1]
                i = (2*i)+1
        bst[i] = data  # insert data in the empty space


# function to delete an element
def delete(data):
    global bst
    j = 1  # start at root node
    currvalue = bst[1]
    while bst[j] != data:  # Loop until the data is reached or to find its non existence
        if data < currvalue:  # Traverse left subtree if data is less than current node
            currvalue = bst[2*j]
            j = 2*j
        elif data > currvalue:  # Traverse right subtree if data is greater than current node
            currvalue = bst[(2*j) + 1]
            j = (2*j)+1
        if j > 2*i:  # End the function if data does not exist even after reaching the last written node
            return
    # Simply delete data if its a leaf node
    if bst[2*j] == None and bst[(2*j) + 1] == None:
        bst[j] = None
    # If only right child exists, replace the node with the right child and delete right child
    elif bst[2*j] == None:
        replacement = bst[(2*j)+1]
        delete(replacement)
        bst[j] = replacement
    # If only left child exists, replace the node with the left child and delete left child
    elif bst[(2*j)+1] == None:
        replacement = bst[2*j]
        delete(replacement)
        bst[j] = replacement
    else:  # If both children exist
        leftinorder = []
        inorder(leftinorder, 2*j)
        # find the greatest node in the left subtree and delete it while replacing the data node with it
        replacement = leftinorder[-1]
        delete(replacement)
        bst[j] = replacement


# inorder traversal
def inorder(result, i):
    # step 1 - Traverse left subtree
    if bst[2*i] != None:
        inorder(result, 2*i)

    # step 2 - Visit root node
    result.append(bst[i])

    # step 3 - Traverse right subtree
    if bst[(2*i)+1] != None:
        inorder(result, (2*i)+1)

# reorder step 1, 2 and 3 for pre order and post order traversal


# driver code
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
insert(4)
insert(2)
insert(6)
insert(10)
insert(8)
insert(0)
insert(3)
insert(5)
insert(7)
insert(9)
insert(12)
print("bst array is : ", bst[1:i+1])
result = []
inorder(result, 1)
print("Inorder Traversal is : ", result)
delete(2)
result = []
inorder(result, 1)
print("Inorder Traversal is : ", result)
print("bst array is : ", bst[1:i+1])


# Output:
# bst array is :  [4, 2, 6, 0, 3, 5, 10, None, None, None, None, None, None, 8, 12]
# Inorder Traversal is :  [0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12]
# Inorder Traversal is :  [0, 3, 4, 5, 6, 7, 8, 9, 10, 12]
# bst array is :  [4, 0, 6, None, 3, 5, 10, None, None, None, None, None, None, 8, 12]
