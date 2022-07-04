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
void Push(PPNODE Head,int No)
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
void Pop(PPNODE Head)
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
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        printf("Removed elements is : %d\n",Temp->next->data);
        free (Temp->next);
        Temp->next = NULL;
    }
}
///////////////////////////////////
//              MAIN             //
///////////////////////////////////
int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Push(&First,151);
    Push(&First,111);
    Push(&First,51);
    Push(&First,21);
    Display(First);
    iRet = Count(First);
    printf("Number of Stack Members : %d\n",iRet);

    Pop(&First);
    Pop(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of Stack Members : %d\n",iRet);

    return 0;
}



