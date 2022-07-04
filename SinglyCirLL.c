#include<stdio.h>
#include<stdlib.h>
/////////////////////////////////////
//            STRUCTURE            //
/////////////////////////////////////
struct Node
{
    int data;
    struct Node *next;
};
/////////////////////////////////////
typedef struct Node NODE;
typedef struct Node *PNODE;
typedef struct Node ** PPNODE;
/////////////////////////////////////
void Display(PNODE Head, PNODE Tail)
{
    do
    {
        printf("|%d|->",Head->data);
        Head = Head->next;
    }while(Head != Tail->next);
    printf("NULL\n");
}
/////////////////////////////////////
int Count(PNODE Head, PNODE Tail)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        Head = Head->next;
    }while(Head != Tail->next);
    return iCnt;
}
/////////////////////////////////////
void InsertFirst(PPNODE Head, PPNODE Tail, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
     if(*Head == NULL && *Tail == NULL)
     {
        *Head = newn;
        *Tail = newn;
     }
     else
     {
        newn->next = *Head;
        *Head = newn;
     }
     (*Tail)->next = *Head;
}
/////////////////////////////////////
void InsertLast(PPNODE Head, PPNODE Tail, int No)
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

    if(*Head == NULL && *Tail == NULL)
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        Temp = *Head;
        while(Temp != *Tail)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}
/////////////////////////////////////
void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if(*Head == NULL && *Tail == NULL)
    {
        return ;
    }
    if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free ((*Tail)->next);
    }
    (*Tail)->next = *Head;
}
/////////////////////////////////////
void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE Temp = NULL;
    if(*Head == NULL && *Tail == NULL)
    {
        return;
    }
    if(*Head == *Tail)
    {
        free (*Head);
        *Head = NULL;
        *Tail = NULL;
    }
    else
    {
        Temp = *Head;
        while(Temp->next != *Tail)
        {
            Temp = Temp->next;
        }
        free (Temp->next);
        *Tail = Temp;
    }
    (*Tail)->next = *Head;
}
/////////////////////////////////////
void InsertAtPos(PPNODE Head, PPNODE Tail, int No, int pos)
{
    PNODE newn = NULL;
    PNODE Temp = NULL;
    int iSize = Count(*Head,*Tail);
    newn = (PNODE)malloc(sizeof(NODE));
    if(newn == NULL)
    {
        return;
    }
    newn->data = No;
    newn->next = NULL;
    if(pos < 1 || pos > (iSize + 1))
    {
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(Head,Tail,No);
    }
    else if(pos == (iSize + 1))
    {
        InsertLast(Head,Tail,No);
    }
    else
    {
        Temp = *Head;
        for(int i = 1 ; i < (pos -1); i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
    (*Tail)->next=*Head;
}
/////////////////////////////////////
void DeleteAtPos(PPNODE Head,PPNODE Tail,int pos)
{
    PNODE Temp = NULL;
    PNODE DelTemp = NULL;
    int iSize = Count(*Head,*Tail);
    if(pos < 1 || pos > iSize)
    {
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(pos == iSize)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        Temp = *Head;
        for(int i = 1; i < (pos-1); i++)
        {
            Temp = Temp->next;
        }
        DelTemp = Temp->next;
        Temp->next = Temp->next->next;
        free(DelTemp);
    }
    (*Tail)->next=*Head;
}
/////////////////////////////////////
//              MAIN               //
/////////////////////////////////////
int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    int iRet = 0;

    InsertFirst(&First, &Last, 21);
    InsertFirst(&First, &Last, 11);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of nodes in Linked List are : %d\n", iRet);

    InsertLast(&First, &Last, 51);
    InsertLast(&First, &Last, 101);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of nodes in Linked List are : %d\n", iRet);

    InsertAtPos(&First, &Last, 1, 3);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of nodes in Linked List are : %d\n", iRet);

    DeleteAtPos(&First, &Last, 3);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of nodes in Linked List are : %d\n", iRet);

    DeleteFirst(&First, &Last);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of nodes in Linked List are : %d\n", iRet);

    DeleteLast(&First, &Last);
    Display(First,Last);
    iRet = Count(First,Last);
    printf("Number of nodes in Linked List are : %d\n", iRet);
    return 0;
}