// Implementation of bst.h

#include "bst.h"

#define TRUE 1
#define FALSE 0

typedef struct _tree_rep {
    int         size;
    TreeNode    root;
} tree_rep;

typedef struct _tree_node {
    int         value;
    TreeNode    left;
    TreeNode    right;
} tree_node;

// function prototypes
TreeNode createNode(int number);

TreeRep createTree() {
    TreeRep t = malloc(sizeof(struct _tree_rep));
    if (t == NULL) {
        printf("Tree rep creation failed.");
        return NULL;
    } else {
        // creation succeeded, initialise variables
        t->size = 0;
        t->root = NULL;
        return t;
    }
}

int getSize(TreeRep treerep) {
    return treerep->size;
}

TreeNode getLeftChild(TreeNode treenode) {
    return treenode->left;
}

TreeNode getRightChild(TreeNode treenode) {
    return treenode->right;
}

int getValue(TreeNode treenode) {
    if (treenode != NULL) {
        return treenode->value;
    } else {
        return -1;
    }
}
void addNode(TreeRep treerep, int number) {
    // check if tree is null (early exit)
    if (treerep != NULL) {
        if (treerep->root != NULL) {
            TreeNode curr = treerep->root;
            int done = FALSE;
            while (!done) {
                if (number > curr->value) {
                    if (curr->right != NULL) {
                        curr = curr->right;
                    } else {
                        // at a leaf
                        TreeNode newRight = createNode(number);
                        curr->right = newRight;
                        treerep->size++;
                        done = TRUE;
                    }
                } else if (number < curr->value) {
                    if (curr->left != NULL) {
                        curr = curr->left;
                    } else {
                        // at a leaf
                        TreeNode newLeft = createNode(number);
                        curr->left = newLeft;
                        treerep->size++;
                        done = TRUE;
                    }
                } else {
                    // equals the node
                    // early exit, no duplicates allowed
                    break;
                }
            }
        } else {
            printf("Tree is empty, creating root...\n");
            TreeNode newRoot = createNode(number);
            treerep->root = newRoot;
            treerep->size++;
        }
    } else {
        printf("Tree is NULL.\n");
    }
}

void destroyNode(TreeNode treenode) {
    if (treenode->right != NULL) {
        printf("Descending right\n");
        destroyNode(treenode->right);
        treenode->right = NULL;
        printf("Ascending right\n");
    }
    if (treenode->left != NULL) {
        printf("Descending left\n");
        destroyNode(treenode->left);
        treenode->left = NULL;
        printf("Ascending left\n");
    }
    if (treenode->right == NULL && treenode->left == NULL) {
        printf("Freeing %d\n", treenode->value);
        free(treenode);
        treenode = NULL;
    }
}

void destroyTree(TreeRep treerep) {
    if (treerep != NULL) {
        if (treerep->root != NULL) {
            destroyNode(treerep->root);
            treerep->size = 0;
            treerep->root = NULL;
            free(treerep);
            treerep = NULL;
        }
    }
}

int getMax(TreeRep treerep) {
    TreeNode curr = treerep->root;
    if (curr != NULL) {
        int done = FALSE;
        while (!done) {
            if (curr->right != NULL) {
                curr = curr->right;
            } else {
                break;
            }
        }
        return curr->value;
    } else {
        return -1;
    }
}

int getMin(TreeRep treerep) {
    TreeNode curr = treerep->root;
    if (curr != NULL) {
        int done = FALSE;
        while (!done) {
            if (curr->left != NULL) {
                curr = curr->left;
            } else {
                break;
            }
        }
        return curr->value;
    } else {
        return -1;
    }
}

TreeNode getNode(TreeRep treerep, int number) {
    if (treerep == NULL) {
        return NULL;
    } else {
        TreeNode curr = treerep->root;
        if (curr != NULL) {
            int done = FALSE;
            while (!done) {
                if (number > curr->value) {
                    if (curr->right != NULL) {
                        curr = curr->right;
                    } else {
                        // can't find it as it doesn't exist
                        // or is not in the expected place for a binary tree
                        return NULL;
                    }
                } else if (number < curr->value) {
                    if (curr->left != NULL) {
                        curr = curr->left;
                    } else {
                        // can't find it as it doesn't exist
                        // or is not in the expected place for a binary tree
                        return NULL;
                    }
                } else if (number == curr->value) {
                    return curr;
                } else {
                    // unknown state, shouldn't get here
                    // exit with NULL
                    return NULL;
                }
            }
        } else {
            return NULL;
        }
    }
    return NULL;
}

TreeNode createNode(int number) {
    TreeNode tn = malloc(sizeof(struct _tree_node));
    if (tn == NULL) {
        return NULL;
    } else {
        tn->value = number;
        tn->left = NULL;
        tn->right = NULL;
        return tn;
    }
}

