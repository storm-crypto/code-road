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

// ˼·һ�����������ķ�ʽ
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

// ˼·��
int TreeSize(BTNode* root)
{
    return root == NULL? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

// �÷��ε�˼��
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
//�����k����ĸ���
int TreeKLevelSize(BTNode* root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

// ����������ֵΪx�Ľ��
BTNode* TreeFind(BTNode* root, BTDataType x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
    {
        return root;
    }

    // ����ߵ�����˵��rootû���ҵ�x����ô�ֱ�����������������
    BTNode* lret = TreeFind(root->left, x);
    if (lret)
        return lret;
    BTNode* rret = TreeFind(root->right, x);
    if (rret)
        return rret;

    // ������˵��û�ҵ�������NULL
    return NULL;
}

// ������������
void BinaryTreeDestroy(BTNode* root)
{
    if (root == NULL)
        return;

    BinaryTreeDestroy(root->left);
    BinaryTreeDestroy(root->right);
    free(root);
}

// �������
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

    printf("TreeNode��%d\n", TreeSize(A));
    printf("TreeLeafNode��%d\n", TreeLeafSize(A));
}
