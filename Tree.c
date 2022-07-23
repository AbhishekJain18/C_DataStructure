#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//////////////////////////////////////////
//              STRUCTURE               //
//////////////////////////////////////////
typedef struct Node
{
    int data;
    struct Node *Rchild;
    struct Node *Lchild;
}NODE, *PNODE, **PPNODE;
///////////////////////////////////////////
void Insert(PPNODE Head, int iNo)
{
    PNODE Temp = *Head;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->Rchild = NULL;
    newn->Lchild = NULL;
    newn->data = iNo;

    if(*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        while(1)
        {
            if(iNo > Temp->data)
            {
                if(Temp->Rchild == NULL)
                {
                    Temp->Rchild = newn;
                    break;
                }
                Temp = Temp->Rchild;
            }
            else if(iNo < Temp->data)
            {
                if(Temp->Lchild == NULL)
                {
                    Temp->Lchild = newn;
                    break;
                }
                Temp = Temp->Lchild;
            }
            else if(iNo == Temp->data)
            {
                free(newn);
                printf("Data is already in BST");
                break;
            }
        }
    }
}
///////////////////////////////////////////
void Inorder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->Lchild);
        printf("%d ",Head->data);
        Inorder(Head->Rchild);
    }
}
///////////////////////////////////////////
void PreOrder(PNODE Head)
{
    if(Head != NULL)
    {
        printf("%d ",Head->data);
        Inorder(Head->Lchild);
        Inorder(Head->Rchild);
    }
}
///////////////////////////////////////////
void PostOrder(PNODE Head)
{
    if(Head != NULL)
    {
        Inorder(Head->Lchild);
        Inorder(Head->Rchild);
        printf("%d ",Head->data);
    }
}
///////////////////////////////////////////
bool search(PNODE Head, int iNo)
{
    while(Head != NULL)
    {
        if(iNo == Head->data)
        {
            break;
        }
        else if(iNo < Head->data)
        {
            Head = Head->Lchild;
        }
        else if(iNo > Head->data)
        {
            Head = Head->Rchild;
        }
    }
    if(Head == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
///////////////////////////////////////////
//                  MAIN                 //
///////////////////////////////////////////
int main()
{
    PNODE First = NULL;
    bool bRet = false;

    Insert(&First,11);
    Insert(&First,21);
    Insert(&First,7);

    // 7 11 21      L D R       Inorder
    // 11 7 21      D L R       PreOrder
    // 7 21 11      L R D       PostOrder

    printf("\nInorder data \n");
    Inorder(First);

    printf("\nPostOrder data \n");
    PostOrder(First);

    printf("\nPreOrder data \n");
    PreOrder(First);

    bRet = search(First,17);
    if(bRet == true)
    {
        printf("\nElements is there in tree\n");
    }
    else
    {
        printf("\nElement isn't in tree\n");
    }
    return 0;
}