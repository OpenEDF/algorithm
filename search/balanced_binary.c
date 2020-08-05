#include <stdio.h>
#include <stdlib.h>

#define bool int
/* Tree struct */
typedef struct node{
    int key;
    struct node *left, *right;
} node;

/* function */
struct node *New_node(int item);
void Inorder_tree(node *root);
void Destroy_Tree(node *root);
bool Check_Banlance(node *root, int *height);

/* main function */
int main(int argc, char *argv[])
{
    int height;
    node *root = New_node(1);
    root->left = New_node(2);
    root->right = New_node(3);
    root->left->left = New_node(4);
    root->left->right = New_node(5);

    Inorder_tree(root);

    if(Check_Banlance(root, &height))
        printf("The tree is balanced.\n");
    else
        printf("The tree is not balanced.\n");
    return 0;

    Destroy_Tree(root);
}

/**
 * @name New_node
 * @brief create a node , the key of node is item.
 * @param[in] item: the key of node.
 * @retval the struct pointer of node.
*/
struct node *New_node(int item)
{
    /* CREATE */
    node *temp = (node *)malloc(sizeof(struct node));
    /* CHECK */
    if(temp == NULL)
        return NULL;

    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/**
 * @name Inorder_tree
 * @brief Traversal the all nodes key value for from tree root.
 * @param[in][out] root: from the root printf the key value for all nodes.
 * @retval None.
*/
void Inorder_tree(node *root)
{
    /* check the root */
    if(root == NULL) return;
    /* Travrse left */
    Inorder_tree(root->left);
    /* Travrse root node */
    printf("%d ->", root->key);
    /* Traverse right */
    Inorder_tree(root->right);
}

/**
 * @name Destroy_Tree
 * @brief Destory the all nodes of a tree.
 * @param[in][out] root: The Binary tree root node.
 * @retval None.
*/
void Destroy_Tree(node *root)
{
    /* The condition of recursive exit. */
    if (root == NULL) return;

    /* recursive free left child */
    Destroy_Tree(root->left);
    /* recursive free left child */
    Destroy_Tree(root->right);
    /* free memory*/
    free(root);
}
/**
 * @name Check_Banlance
 * @brief Check the Binary Tree is a balanced tree.
 * @param[in][out] root: The root of tree to check.
 * @param[in]  height: The height of the tree.
 * @retval check balance status.
 *  @arg 1: The tree is balanced. 0 is not.
*/
bool Check_Banlance(node *root, int *height)
{
    int leftheight, rightheight, l, r;
    leftheight = rightheight = 0;
    l = r = 0;

    /* check tree root */
    if (root == NULL)
    {
        *height = 0;
        return 1;
    }

    /* recusive check left and right child */
    l = Check_Banlance(root->left, &leftheight);
    r = Check_Banlance(root->right, &rightheight);
    *height = ((leftheight > rightheight ? leftheight : rightheight)) + 1;

    if ((leftheight - rightheight >= 2) || (rightheight - leftheight >= 2))
        return 0;
    else
        return (l && r);
}
