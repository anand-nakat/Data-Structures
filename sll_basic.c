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

node *deleteNode(node *head)
{
    if (head == NULL)
        return head;
    int key;
    printf("\nEnter Node to Delete:");
    scanf("%d", &key);
    node *head1 = head;
    if (head->data == key)
    {
        head = head->next;
        free(head1);
        head1 = NULL;
        return head;
    }
    while (head1->next->data != key)
    {
        head1 = head1->next;
    }
    node *p = head1->next;
    head1->next = p->next;
    free(p);
    p = NULL;
    return head;
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

node *insertNodeBetween(node *head)
{
    if (head == NULL)
    {
        head = insertNodeAtEnd(head);
        return head;
    }
    int data, key;
    printf("\nEnter Data for Node to Enter:");
    scanf("%d", &data);
    struct node *p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        printf("\nMemory Not available!");
        return head;
    }
    p->data = data;
    p->next = NULL;

    printf("\nDo you want to insert this Node 1)Before a Node\t 2)After a Node\nEnter choice 1 or 2:");

    int ch;
    scanf("%d", &ch);
    if (ch != 1 && ch != 2)
    {
        printf("\nInvalid Choice!");
        return head;
    }

    printf("\nEnter node before/after to insert your node:");
    scanf("%d", &key);
    node *head1 = head;

    if (head->data == key) /*single node*/
    {
        if (ch == 1) /*Insert Before a Node*/
        {
            p->next = head;
            head = p;
        }
        else /*Insert after a Node*/
        {
            p->next = head->next;
            head->next = p;
        }
        return head;
    }

    while (head1->next->data != key && head1 != NULL)
        head1 = head1->next;
    if (head1 == NULL)
    {
        printf("\nNode you entered was not found.Exiting...");
        return head;
    }
    if (ch == 1)
    {
        p->next = head1->next;
        head1->next = p;
    }
    else /*Insert after a Node*/
    {
        head1 = head1->next;
        p->next = head1->next;
        head1->next = p;
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

node *reverse(node *head)
{
    if (head == NULL || head->next == NULL) /*If Empty or Single Element*/
        return head;
    node *left, *current, *right;
    left = current = NULL;
    right = head;
    while (right != NULL)
    {
        left = current;
        current = right;
        right = right->next;
        current->next = left;
    }
    return current;
}

int main()
{
    node *s = NULL, *mid = NULL, *a = NULL;
    int key, n, choice;
    printf("Enter the no of nodes to insert:");
    scanf("%d", &n);
    s = init(s, n);
    while (1)
    {
        printf("\n\n*MENU*\n");
        printf("1.Display List\n2.Insert Node at End\n3.Search a Node\n4.Delete a Node at End\n5.Insert Node before/after any particular node\n");
        printf("6.Delete a particular Node\n7.Find Mid Node\n8.Reverse Linked List\n\nEnter your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printNodes(s);
            break;
        case 2:
            s = insertNodeAtEnd(s);
            printNodes(s);
            break;
        case 3:
            searchNode(s);
            break;
        case 4:
            s = deleteAtEnd(s);
            printNodes(s);
            break;
        case 5:
            s = insertNodeBetween(s);
            printNodes(s);
            break;
        case 6:
            s = deleteNode(s);
            printNodes(s);
            break;
        case 7:
            mid = findMid(s);
            printf("\nMid Node:%d", mid->data);
            break;
        case 8:
            s = reverse(s);
            printNodes(s);
            break;
        default:
            printf("\nInvalid Choice!");
            break;
        }
    }
}