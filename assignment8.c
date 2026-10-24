#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node and insert it into the BST
struct Node *create(struct Node *root, int value) {
    if (root == NULL) {
        struct Node *newNode =
            (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < root->data) {
        root->left = create(root->left, value);
    } else if (value > root->data) {
        root->right = create(root->right, value);
    } else {
        printf("Duplicate values are not allowed.\n");
    }

    return root;
}

// Search for a value in the BST
struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Recursive inorder traversal: Left, Root, Right
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Recursive preorder traversal: Root, Left, Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Recursive postorder traversal: Left, Right, Root
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Free allocated memory
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    struct Node *root = NULL;
    struct Node *found;
    int choice, value, n, i;

    while (1) {
        printf("\n--- BINARY SEARCH TREE ---\n");
        printf("1. Create BST\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            freeTree(root);
            return 1;
        }

        switch (choice) {
            case 1:
                printf("How many nodes do you want to insert? ");

                if (scanf("%d", &n) != 1 || n < 0) {
                    printf("Invalid number of nodes!\n");
                    freeTree(root);
                    return 1;
                }

                for (i = 0; i < n; i++) {
                    printf("Enter value: ");

                    if (scanf("%d", &value) != 1) {
                        printf("Invalid input!\n");
                        freeTree(root);
                        return 1;
                    }

                    root = create(root, value);
                }
                printf("BST created successfully.\n");
                break;

            case 2:
                printf("Enter value to search: ");

                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    freeTree(root);
                    return 1;
                }

                found = search(root, value);

                if (found != NULL) {
                    printf("%d found in the BST.\n", value);
                } else {
                    printf("%d not found in the BST.\n", value);
                }
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                freeTree(root);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
