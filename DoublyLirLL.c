#include<stdio.h>
#include<stdlib.h>
///////////////////////////////////
//          STRUCTURE            //
///////////////////////////////////
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}
///////////////////////////////////
void InsertFirst(PPNODE Head , int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        (*Head)->prev = newn;
        *Head = newn;
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
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        int i = 0;
        Temp = *Head;
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        newn->prev = Temp;
        Temp->next = newn;
    }
}
///////////////////////////////////
void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
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
        *Head = (*Head)->next;
        free ((*Head)->prev);
        (*Head)->prev = NULL;
    }
}
///////////////////////////////////
void DeleteLast(PPNODE Head)
{
    PNODE Temp = NULL;
    if(*Head == NULL)
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
    int iSize = 0;
    newn = (PNODE)malloc(sizeof(NODE));
    iSize = Count(*Head);
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(pos < 1 || pos >(iSize+1))
    {
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(Head, No);
    }
    else if(pos == (iSize+1))
    {
        InsertLast(Head ,No);
    }
    else
    {
        int i = 0;
        for( Temp = *Head, i = 1; i<(pos -1); Temp = Temp->next,i++)
        { }
        newn->next = Temp->next;
        Temp->next->prev = newn;
        newn->prev = Temp;
        Temp->next = newn;
    }
}
///////////////////////////////////
void DeleteAtPos(PPNODE Head, int pos)
{
    int iSize = Count(*Head);
    PNODE Temp = NULL;
    if(pos < 1 || pos > iSize)
    {
        return;
    }
    else if(pos == 1)
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
        for( Temp = *Head,i = 1; i< (pos -1); Temp = Temp->next,i++)
        { }
        Temp->next = Temp->next->next;
        free (Temp->next->prev);
        Temp->next->prev = Temp;
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



