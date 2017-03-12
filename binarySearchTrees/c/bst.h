#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_rep * TreeRep;
typedef struct _tree_node * TreeNode;

TreeRep     createTree();
int         getValue(TreeNode treenode);
TreeNode    getLeftChild(TreeNode treenode);
TreeNode    getRightChild(TreeNode treenode);
void        addNode(TreeRep treerep, int number);
void        destroyTree(TreeRep treerep);
int         getMax(TreeRep treerep);
int         getMin(TreeRep treerep);
TreeNode    getNode(TreeRep treerep, int number);
int         getSize(TreeRep treerep);

#endif
