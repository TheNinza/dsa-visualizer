// C++ program to insert, delete and search in binary search tree using linked lists
#include <iostream>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp = new (struct node);
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do
// inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << ", ";
		inorder(root->right);
	}
}

/* A utility function to
insert a new node with given key in
* BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node
with maximum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct node* maxValueNode(struct node* node)
{
    struct node* current = node;
    /* loop down to find the rightmost leaf */
    while (current && current->right != NULL)
        current = current->right;

    return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (root->left==NULL && root->right==NULL)
			return NULL;
	
		// node with only one child
		else if (root->left == NULL) {
			struct node* temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			delete(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (largest in the left subtree)
		struct node* temp = maxValueNode(root->left);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->left = deleteNode(root->left, temp->key);
	}
	return root;
}

/* Given a binary search tree and a key, this function
returns whether the key exists in the tree or not */
bool searchNode(struct node* root,int key)
{
	if(key == root->key)
		return true;
	else if(root->right == NULL && root->left == NULL)
			return false;
	else if(key>root->key && root->right != NULL)
			return searchNode(root->right, key);
	else if(key<root->key && root->left != NULL)
			return searchNode(root->left, key);
	return false;
}

// Driver Code
int main()
{
	/*Lets create tree:
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
	struct node* root = NULL;
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 10);
	root = insert(root, 8);
	root = insert(root, 0);
	root = insert(root, 3);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 9);
	root = insert(root, 12);
    

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 2\n";
	root = deleteNode(root, 2);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 3\n";
	root = deleteNode(root, 3);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 10\n";
	root = deleteNode(root, 10);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\n12 exists is the bst? : " << (searchNode(root, 12)?"true":"false");
	return 0;
}


// Output:
// Inorder traversal of the given tree 
// 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12,
// Delete 2
// Inorder traversal of the modified tree
// 0, 3, 4, 5, 6, 7, 8, 9, 10, 12,
// Delete 3
// Inorder traversal of the modified tree
// 0, 4, 5, 6, 7, 8, 9, 10, 12,
// Delete 10
// Inorder traversal of the modified tree
// 0, 4, 5, 6, 7, 8, 9, 12,
// 12 exists is the bst? : true
