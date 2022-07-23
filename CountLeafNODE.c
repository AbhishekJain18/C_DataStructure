#include<stdio.h>
#include<stdlib.h>
///////////////////////////////////////////
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
int CountLeafNode(PNODE Head)
{
    static int iCnt = 0;
    if(Head != NULL)
    {
        if((Head->Lchild== NULL) && (Head->Rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNode(Head->Lchild);
        CountLeafNode(Head->Rchild);
    }

    return iCnt;
}
///////////////////////////////////////////
//                  MAIN                 //
///////////////////////////////////////////
int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Insert(&First,11);
    Insert(&First,21);
    Insert(&First,18);
    Insert(&First,7);

    iRet = CountLeafNode(First);
    printf("Leaf Node in tree are %d\n",iRet);
    return 0;
}