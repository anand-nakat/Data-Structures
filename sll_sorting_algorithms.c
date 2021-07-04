#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void printNodes(node *s)
{
    if (s == NULL)
    {
        printf("\nLinked List is Empty");
        return;
    }

    printf("\nLinked List:");
    while (s != NULL)
    {
        s->next == NULL ? printf("%d", s->data) : printf("%d->", s->data);
        s = s->next;
    }
}

node *init(node *head, int n)
{

    int data, i = 0;
    node *tail = NULL;
    while (i++ < n)
    {
        printf("\nEnter Data for Node:");
        scanf("%d", &data);
        struct node *p = (node *)malloc(sizeof(node));

        if (p == NULL)
        {
            printf("\nMemory Not available!");
            return head;
        }
        p->data = data;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

node *findMid(node *head)
{

    if (head == NULL)
        return head;
    node *p, *q;
    p = q = head;

    while (q->next != NULL && q->next->next != NULL)
    {
        q = q->next->next;
        p = p->next;
    }
    return p;
}

node *insertNodeAtEnd(node *head)
{

    int data;
    printf("\nEnter Data for Node:");
    scanf("%d", &data);
    struct node *p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        printf("\nMemory Not available!");
        return head;
    }
    p->data = data;
    p->next = NULL;

    if (head == NULL) /*Empty Linked List*/
        head = p;
    else
    {
        node *head1 = head;
        while (head1->next != NULL)
            head1 = head1->next;
        head1->next = p;
    }
    return head;
}

node *deleteAtEnd(node *head)
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty.");
        return head;
    }
    if (head->next == NULL) /*Single Element in List*/
    {
        free(head);
        head = NULL;
        return head;
    }
    node *head1 = head;
    while (head1->next->next != NULL) /* More than 1 Element */
        head1 = head1->next;
    node *p = head1->next;
    head1->next = NULL;
    free(p);
    p = NULL;
    return head;
}

node *merge(node *p, node *q)
{
    node *p1 = p;
    node *q1 = q;
    node *resultHead = NULL, *resultTail = NULL;
    node *temp;
    while (p1 != NULL && q1 != NULL)
    {
        if (p1->data <= q1->data)
        {
            temp = p1;
            p1 = p1->next;
            temp->next = NULL;
        }
        else
        {
            temp = q1;
            q1 = q1->next;
            temp->next = NULL;
        }
        if (resultHead == NULL)
            resultHead = resultTail = temp;
        else
        {
            resultTail->next = temp;
            resultTail = temp;
        }
    }
    if (p1 != NULL)
        resultTail->next = p1;
    else
        resultTail->next = q1;

    return resultHead;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    else
    {
        node *mid = findMid(head);
        node *p = mid->next;
        mid->next = NULL; /*Disconnecting Link of Mid Node*/
        node *left = mergeSort(head);
        node *right = mergeSort(p);
        node *newHead = merge(left, right);
        return newHead;
    }
}
int main()
{

    node *s = NULL;
    int n, choice;
    printf("Enter the no of nodes to insert:");
    scanf("%d", &n);
    s = init(s, n);
    while (1)
    {
        printf("\n\n*MENU*\n");
        printf("1.Insert Node at End\n2.Delete Node at End\n3.Merge Sort");
        printf("\n\nEnter your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            s = insertNodeAtEnd(s);
            printNodes(s);
            break;
        case 2:
            s = mergeSort(s);
            printNodes(s);
            break;

        default:
            printf("\nEnter valid choice!");
            break;
        }
    }
}