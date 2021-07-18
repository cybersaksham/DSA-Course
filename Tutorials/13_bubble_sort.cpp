/*
Analysis:
--> Time Complexity O(n^2)
--> Space Complexity O(1)
--> Stable Algorithm
--> Internal Algorithm
--> Not adaptive by default but we made it adaptive (by adapt_checker variable)
--> Not Recursive
*/

/*
Process:
1. Make bubble of first two elements.
2. If bubble is sorted then continue otherwise swap the numbers in bubble.
3. Proceed the bubble to next 2 numbers.
4. Repeat 2nd step.
5. Repeat 3rd & 4th step until last of array.
6. Now last one element will be at its correct position.
7. Repeat all steps & last two elements will be positioned correctly.
8. Do this until array is sorted.
9. You need not to make bubbles for previously sorted elements.
*/

/*
Dry Run:

arr = 12 45 36 0 45 -1
No of passes = 5

1st pass: (12 45 36 0 45 -1)
    1. [12 45] 36 0 45 -1 <-- adapt_checker = 0
    2. 12 [45 36] 0 45 -1 <-- adapt_checker = 1
    3. 12 36 [45 0] 45 -1 <-- adapt_checker = 2
    4. 12 36 0 [45 45] -1 <-- adapt_checker = 2
    5. 12 36 0 45 [45 -1] <-- adapt_checker = 3
    6. 12 36 0 45 -1 45

2nd pass: (12 36 0 45 -1 45)
    1. [12 36] 0 45 -1 45 <-- adapt_checker = 0
    2. 12 [36 0] 45 -1 45 <-- adapt_checker = 1
    3. 12 0 [36 45] -1 45 <-- adapt_checker = 2
    4. 12 0 36 [45 -1] 45 <-- adapt_checker = 3
    5. 12 0 36 -1 45 45

3rd pass: (12 0 36 -1 45 45)
    1. [12 0] 36 -1 45 45 <-- adapt_checker = 1
    2. 0 [12 36] -1 45 45 <-- adapt_checker = 1
    3. 0 12 [36 -1] 45 45 <-- adapt_checker = 2
    4. 0 12 -1 36 45 45

4th pass: (0 12 -1 36 45 45)
    1. [0 12] -1 36 45 45 <-- adapt_checker = 0
    2. 0 [12 -1] 36 45 45 <-- adapt_checker = 1
    3. 0 -1 12 36 45 45

5th pass: (0 -1 12 36 45 45)
    1. [0 -1] 12 36 45 45 <-- adapt_checker = 1
    2. -1 0 12 36 45 45

Passes completed
Finally sorted: -1 0 12 36 45 45
*/

#include <iostream>
using namespace std;

void bswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int size)
{
    int pass = size, adapt_checker;

    while (--pass)
    {
        adapt_checker = 0;
        for (int i = 0; i < pass; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                bswap(&arr[i], &arr[i + 1]);
                adapt_checker++;
            }
        }
        if (adapt_checker == 0)
            return;
    }
}

int main()
{
    int size = 6;
    int arr[] = {12, 45, 36, 0, 45, -1};

    cout << "Before Sorting :" << endl;
    show(arr, size);
    bubbleSort(arr, size);
    cout << "After Sorting :" << endl;
    show(arr, size);

    return 0;
}