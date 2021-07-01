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

node *insertMultipleNodes(node *head, int n)
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

void searchNode(node *head)
{
    int num = 1, key;
    if (head == NULL)
    {
        printf("\nLinked List is Empty.");
        return;
    }
    printf("\nEnter data to search for:");
    scanf("%d", &key);
    for (; head != NULL; head = head->next, num++)
    {
        if (head->data == key)
        {
            printf("\n%d Found at Node:%d", key, num);
            return;
        }
    }
    printf("\n%d not found in the List", key);
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

void insertNodeAtEnd(node *head)
{

    if (head == NULL) /*Empty Linked List*/
        return;

    int data;
    printf("\nEnter Data for Node:");
    scanf("%d", &data);
    struct node *p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        printf("\nMemory Not available!");
        return;
    }
    p->data = data;
    p->next = NULL;

    while (head->next != NULL)
        head = head->next;
    head->next = p;
}

int main()
{
    node *s = NULL;
    int key, n, choice;
    printf("Enter the no of nodes to insert:");
    scanf("%d", &n);
    s = insertMultipleNodes(s, n);
    while (1)
    {
        printf("\n\n*MENU*\n");
        printf("1.Display List\n2.Insert Node at End\n3.Search a Node\n4.Delete a Node at End\n5.Insert Node before any particular node\n");
        printf("6.Delete a particular Node\n\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printNodes(s);
            break;
        case 2:
            insertNodeAtEnd(s);
            printNodes(s);
            break;
        case 3:
            searchNode(s);
            break;
        case 4:
            s = deleteAtEnd(s);
            printNodes(s);
            break;

        default:
            break;
        }
    }
}