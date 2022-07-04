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
void Enqueue(PPNODE Head, int No)
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
void dequeue(PPNODE Head)
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
        PNODE Temp = NULL;
        Temp = *Head;
        printf("Removed member is %d\n",Temp->data);
        *Head = Temp->next;
        free (Temp);
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Enqueue(&First,151);
    Enqueue(&First,111);
    Enqueue(&First,51);
    Enqueue(&First,21);
    Display(First);
    iRet = Count(First);
    printf("Number of members in Queue : %d\n",iRet);

    dequeue(&First);
    dequeue(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of members in Queue : %d\n",iRet);

    return 0;
}



