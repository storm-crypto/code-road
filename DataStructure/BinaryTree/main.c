#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

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

// 思路一：遍历计数的方式
//void TreeSize(BTNode* root, int* psize)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//    ++(*psize);
//    TreeSize(root->right, psize);
//    TreeSize(root->left, psize);
//}

// 思路二
int TreeSize(BTNode* root)
{
    return root == NULL? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

// 用分治的思想
int TreeLeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return TreeSize(root->left) + TreeSize(root->right);
}

// k > 0
//计算第k层结点的个数
int TreeKLevelSize(BTNode* root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

// 查找树里面值为x的结点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
    {
        return root;
    }

    // 光标走到这里说明root没有找到x，那么分别到左子树右子树中找
    BTNode* lret = TreeFind(root->left, x);
    if (lret)
        return lret;
    BTNode* rret = TreeFind(root->right, x);
    if (rret)
        return rret;

    // 到这里说明没找到，返回NULL
    return NULL;
}

// 二叉树的销毁
void BinaryTreeDestroy(BTNode* root)
{
    if (root == NULL)
        return;

    BinaryTreeDestroy(root->left);
    BinaryTreeDestroy(root->right);
    free(root);
}

// 层序遍历
void TreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);

    QueueDestroy(&q);
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

//    PrevOrder(A);
//    printf("\n");
//
//    InOrder(A);
//    printf("\n");
//
//    PostOrder(A);
//    printf("\n");
//    int size = 0;
//    TreeSize(A, &size);
//
//    printf("%d", size);

    printf("TreeNode：%d\n", TreeSize(A));
    printf("TreeLeafNode：%d\n", TreeLeafSize(A));
}
