#include <iostream>
#include <math.h>
using namespace std;

void getInput(int a[], int n);
void printArray(int a[], int);
int n;

void swapElement(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int a[], int i)
{
    int child1_idx = 2 * i + 1;
    int child2_idx = 2 * i + 2;
    if (child1_idx >= n) /*No child then return*/
        return;
    if (child2_idx >= n) /* Left Child but not Right Child */
    {
        if (a[i] < a[child1_idx])
            swapElement(&a[i], &a[child1_idx]);
        return;
    }
    int idx = a[child1_idx] > a[child2_idx] ? child1_idx : child2_idx;
    if (a[i] > a[idx]) /*Child Ok*/
        return;
    swapElement(&a[i], &a[idx]);
    maxHeapify(a, idx); /*Call recursively for swapped parent*/
}

void minHeapify(int a[], int i)
{
    int child1_idx = 2 * i + 1;
    int child2_idx = 2 * i + 2;
    if (child1_idx >= n) /*No child then return*/
        return;
    if (child2_idx >= n) /* Left Child but not Right Child */
    {
        if (a[i] > a[child1_idx])
            swapElement(&a[i], &a[child1_idx]);
        return;
    }
    int idx = a[child1_idx] < a[child2_idx] ? child1_idx : child2_idx;
    if (a[i] < a[idx]) /*Child Ok*/
        return;
    swapElement(&a[i], &a[idx]);
    minHeapify(a, idx); /*Call recursively for swapped parent*/
}

void buildHeap(int a[], int n, int choice) /*Build Heap: O(n)*/
{
    if (n == 1 || n == 0)
        return;
    if (n == 2)
    {
        if (choice == 1)
        {
            if (a[0] < a[1])
                swapElement(&a[0], &a[1]);
            return;
        }
        else
        {
            if (a[0] > a[1])
                swapElement(&a[0], &a[1]);
            return;
        }
    }
    for (int i = n - ceil(n / 2) - 1; i >= 0; i--) //Start with last parent node
    {

        choice == 1 ? maxHeapify(a, i) : minHeapify(a, i);
    }
}

int main()
{
    cout << "Enter no of elements in Array:";
    cin >> n;
    int a[n], choice;
    getInput(a, n);
    cout << "\nElements you entered:";
    printArray(a, n);

    cout << "\n0.Create Min Heap \n1.Create Max Heap\nEnter choice(0 or 1):";
    cin >> choice;
    if (choice != 0 && choice != 1)
    {
        cout << "INVALID CHOICE";
        exit(1);
    }
    choice == 1 ? cout << "\nMax Heap:" : cout << "\nMin Heap:";
    buildHeap(a, n, choice);
    printArray(a, n);
}

void getInput(int a[], int n)
{
    cout << "\nEnter elements of array:\n";
    int temp, i = 0;
    while (n--)
    {
        cin >> temp;
        a[i++] = temp;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}