#include <stdio.h>
#include <stdlib.h>

/* Tree struct */
typedef struct node{
    int key;
    struct node *left, *right;
} node;

/* function */
struct node *New_node(int item);
struct node *Insert_to_node(node *Node, int key);
void Inorder_tree(node *root);
struct node *Find_minNode(node *root);
struct node *Find_maxNode(node *root);

/* main function */
int main(int argc, char *argv[])
{
    node *root, *min;
    root = New_node(8);
    printf("The root->key = %d\n", root->key);

    root = Insert_to_node(root, 10);
    root = Insert_to_node(root, 5);
    root = Insert_to_node(root, 2);
    root = Insert_to_node(root, 20);
    printf("The root->key = %d\n", root->right->key);

    min = Find_minNode(root);
    printf("The root->key = %d\n", min->key);

    min = Find_maxNode(root);
    printf("The root->key = %d\n", min->key);

    Inorder_tree(root);
    return 0;
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
 * @name Insert_to_node
 * @brief Insert the key to the node.
 * @param[in][out] item: the key of node.
 * @param[in] key: the key will insert the node.
 * @retval the struct pointer of node.
*/
struct node * Insert_to_node(node *Node, int key)
{
    /* If the tree is empty return NULL */
    if (Node == NULL)
        return New_node(key);

    /* Traverse to the rigth or left depend on the key */
    if (key < Node->key)
        Node->left = Insert_to_node(Node->left, key);
    else
        Node->right = Insert_to_node(Node->right, key);

    /* return struct */
    return Node;
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
 * @name Find_minNode
 * @brief Find the minimum node.
 * @param[in][out] root: from the root printf the key value for all nodes.
 * @retval the struct pointer of minimum node.
*/
struct node *Find_minNode(node *root)
{
    node *current = root;

    /* find the leftmost left */
    while((current != NULL) && (current->left != NULL))
        current = current->left;

    /* return minimum */
    return current;
}

/**
 * @name Find_maxNode
 * @brief Find the maximum node.
 * @param[in][out] root: from the root printf the key value for all nodes.
 * @retval the struct pointer of minimum node.
*/
struct node *Find_maxNode(node *root)
{
    node *current = root;

    /* find the leftmost left */
    while((current != NULL) && (current->right != NULL))
        current = current->right;

    /* return minimum */
    return current;
}


