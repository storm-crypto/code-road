#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    BTDataType data;
}BTNode;

void PrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    else
    {
        printf("%c ", root->data);
        PrevOrder(root->left);
        PrevOrder(root->right);
    }

}

void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}
void PostOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->data);

}

BTNode* CreateTreeNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    node->data = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    BTNode* A = CreateTreeNode('A');
    BTNode* B = CreateTreeNode('B');
    BTNode* C = CreateTreeNode('C');
    BTNode* D = CreateTreeNode('D');
    BTNode* E = CreateTreeNode('E');
    BTNode* F = CreateTreeNode('F');

    A->left = B;
    A->right = C;
    B->left = D;
    C->left = E;
    C->right = F;

    PrevOrder(A);
    printf("\n");

    InOrder(A);
    printf("\n");

    PostOrder(A);
    printf("\n");

}
