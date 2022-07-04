#include<stdio.h>
#include<stdlib.h>
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
struct Node
{
    int data;
    struct Node *next;
};
///////////////////////////////////
typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;
///////////////////////////////////
void Display(PNODE Head)
{
    while(Head != NULL)
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}
///////////////////////////////////
int Count(PNODE Head)
{
    int iCount = 0;
    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}
///////////////////////////////////
void InsertFirst(PPNODE Head,int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if((*Head) == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = (*Head);
        (*Head) = newn;
    }
}
///////////////////////////////////
void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE Temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        printf("Unable to allocate memory");
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if((*Head) == NULL)
    {
        *Head = newn;
    }
    else
    {
        Temp = *Head;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next=newn;
    }
}
///////////////////////////////////
void DeleteFirst(PPNODE Head)
{
    if(Head == NULL)
    {
        return;
    }
    if((*Head)->next == NULL)
    {
        free (*Head);
        *Head = NULL;
    }
    else
    {
        PNODE Temp = NULL;
        Temp = *Head;
        *Head = Temp->next;
        free (Temp);
    }
}
///////////////////////////////////
void DeleteLast(PPNODE Head)
{
    PNODE Temp = NULL;
    if(Head == NULL)
    {
        return;
    }
    if((*Head)->next == NULL)
    {
        free (*Head);
        *Head = NULL;
    }
    else
    {
        Temp = *Head;
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free (Temp->next);
        Temp->next = NULL;
    }
}
///////////////////////////////////
void InsertAtPos(PPNODE Head, int No, int pos)
{
    PNODE newn = NULL;
    PNODE Temp = NULL;
    int iSize = Count(*Head);
    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if(pos < 1 || pos > (iSize+1))
    {
        return;
    }
    if(pos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(pos == (iSize + 1))
    {
        InsertLast(Head, No);
    }
    else
    {
        Temp = *Head;
        for(int i = 1; i < (pos -1); i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
}
///////////////////////////////////
void DeleteAtPos(PPNODE Head, int pos)
{
    PNODE Temp = NULL;
    PNODE TempDel = NULL;
    int iSize = Count(*Head);
    if(pos < 1 || pos > iSize)
    {
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == iSize)
    {
        DeleteLast(Head);
    }
    else
    {
        int i = 0;
        for(i = 1, Temp = *Head; i < (pos-1); i++, Temp = Temp->next)
        {}
        TempDel = Temp->next;
        Temp->next = TempDel->next;
        free (TempDel);
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes in Linked list : %d\n",iRet);

    InsertLast(&First,111);
    InsertLast(&First,151);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes in Linked list : %d\n",iRet);

    InsertAtPos(&First,1,3);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes in Linked list : %d\n",iRet);

    DeleteAtPos(&First,3);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes in Linked list : %d\n",iRet);

    DeleteFirst(&First);
    DeleteLast(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes in Linked list : %d\n",iRet);

    return 0;
}



