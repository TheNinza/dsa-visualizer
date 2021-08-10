// C code for Binary Search Tree using Array

#include <stdio.h>

int bst[10000]; // Empty Array for tree
int i = 1;      //To store index to which data is last inserted

// inorder traversal
int inorder(int result[], int i, int in_size)
{
    // step 1 - Traverse left subtree
    if (bst[2 * i] != -1)
        in_size = inorder(result, 2 * i, in_size);
    // step 2 - Visit root node
    result[in_size++] = bst[i];

    // step 3 - Traverse right subtree
    if (bst[(2 * i) + 1] != -1)
        in_size = inorder(result, (2 * i) + 1, in_size);
    // return size of inorder array
    return in_size;
}
// reorder step 1, 2 and 3 for pre order and post order traversal

// function to add an element
void tree_insert(int data)
{
    // if bst is empty add root node
    if (bst[1] == -1)
    {
        bst[1] = data;
    }

    // Traverse if tree not empty
    else
    {
        i = 1;
        int currvalue = bst[1];
        // Loop until you reach an empty space or data already exists
        while (bst[i] != -1 && bst[i] != data)
        {
            // Traverse left subtree if data is less than current node
            if (data < currvalue)
            {
                currvalue = bst[2 * i];
                i = 2 * i;
            }
            // Traverse right subtree if data is greater than current node
            else if (data > currvalue)
            {
                currvalue = bst[(2 * i) + 1];
                i = (2 * i) + 1;
            }
        }
        bst[i] = data; // insert data in the empty space
    }
}

void tree_delete(int data)
{
    int j = 1; // start at root node
    int currvalue = bst[1];
    while (bst[j] != data)
    {
        // Loop until the data is reached or to find its non existence
        if (data < currvalue)
        {
            // Traverse left subtree if data is less than current node
            currvalue = bst[2 * j];
            j = 2 * j;
        }
        else if (data > currvalue)
        {
            // Traverse right subtree if data is greater than current node
            currvalue = bst[(2 * j) + 1];
            j = (2 * j) + 1;
        }
        if (j > 2 * i) // End the function if data does not exist even after reaching the last written node
            return;
    }
    // Simply delete data if its a leaf node
    if (bst[2 * j] == -1 && bst[(2 * j) + 1] == -1)
        bst[j] = -1;
    else if (bst[2 * j] == -1)
    {
        // If only right child exists, replace the node with the right child and delete right child
        int replacement = bst[(2 * j) + 1];
        tree_delete(replacement);
        bst[j] = replacement;
    }
    // If only left child exists, replace the node with the left child and delete left child
    else if (bst[(2 * j) + 1] == -1)
    {
        int replacement = bst[2 * j];
        tree_delete(replacement);
        bst[j] = replacement;
    }
    // If both children exist
    else
    {
        int leftinorder[10000];
        int inordersize = 0;
        inordersize = inorder(leftinorder, 2 * j, inordersize);
        // find the greatest node in the left subtree and delete it while replacing the data node with it
        int replacement = leftinorder[inordersize - 1];
        tree_delete(replacement);
        bst[j] = replacement;
    }
}

int main()
{
    // intializing bst array to -1
    for (int la = 0; la < 10000; la++)
        bst[la] = -1;

    /*
    Lets create tree:
               4
		    /	  \
	        2      6
		   / \    / \
	      0   3  5  10
                   /  \
                  8   12
                /  \
               7    9
    */
    tree_insert(4);
    tree_insert(2);
    tree_insert(6);
    tree_insert(10);
    tree_insert(8);
    tree_insert(0);
    tree_insert(3);
    tree_insert(5);
    tree_insert(7);
    tree_insert(9);
    tree_insert(12);
    printf("bst array is : [");
    for (int la = 1; la <= i; la++)
        printf("%d, ", bst[la]);
    printf("]\n\n");
    int result[10000];
    int in_size = 0;
    in_size = inorder(result, 1, in_size);
    printf("Inorder Traversal is : [");
    for (int la = 0; la < in_size; la++)
        printf("%d, ", result[la]);
    printf("]\n\n");
    tree_delete(2);
    in_size = 0;
    in_size = inorder(result, 1, in_size);
    printf("Inorder Traversal is : [");
    for (int la = 0; la < in_size; la++)
        printf("%d, ", result[la]);
    printf("]\n\n");
    printf("bst array is : [");
    for (int la = 1; la <= i; la++)
        printf("%d, ", bst[la]);
    printf("]\n\n");
    return 0;
}

// Output:
// bst array is : [4, 2, 6, 0, 3, 5, 10, -1, -1, -1, -1, -1, -1, 8, 12, ]

// Inorder Traversal is : [0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, ]

// Inorder Traversal is : [0, 3, 4, 5, 6, 7, 8, 9, 10, 12, ]

// bst array is : [4, 0, 6, -1, 3, 5, 10, -1, -1, -1, -1, -1, -1, 8, 12, ]
