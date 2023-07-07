#include <bits/stdc++.h>
using namespace std;
class Sort
{

public:
    void print(vector<int> &arr)
    {
        for (int i : arr)
            cout << i << " ";
        cout << endl;
    }
    void shuffle(vector<int> &arr)
    {
        // Time Complexity: O(n)
        // Auxiliary Space: O(1)
        // Fisher–Yates shuffle Algorithm works in O(n) time complexity. The assumption here is, we are given a function rand() that generates random number in O(1) time.
        // The idea is to start from the last element, swap it with a randomly selected element from the whole array (including last). Now consider the array from 0 to n-2 (size reduced by 1), and repeat the process till we hit the first element.
        // Following is the detailed algorithm
        // To shuffle an array a of n elements (indices 0..n-1):
        // for i from n−1 downto 1 do
        //      j ← random integer such that 0 ≤ j ≤ i
        //      exchange a[j] and a[i]
        int n = arr.size();
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
    }
    void selection(vector<int> &arr)
    {
        // Time Complexity: O(n^2)
        // Auxiliary Space: O(1)
        // The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
        // In Place : Yes, it does not require extra space.
        // Stable : No, it does not preserve the order of occurrence of elements with equal keys.
        // Selection sort is an in-place comparison sorting algorithm. It is an in-place algorithm because it uses only additional O(1) memory space.
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min])
                    min = j;
            swap(arr[min], arr[i]);
        }
    }

    void bubble(vector<int> &arr)
    {
        // Time Complexity: O(n^2)
        // Auxiliary Space: O(1)
        // In Place : Yes, it does not require extra space.
        // Stable : Yes, it does not change the relative order of elements which are equal.
        // Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    void insertion(vector<int> &arr)
    {
        // Time Complexity: O(n^2)
        // Auxiliary Space: O(1)
        // In Place : Yes, it does not require extra space.
        // Stable : Yes, it does not change the relative order of elements which are equal.
        // Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
        // The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void merge(vector<int> &arr, int l, int m, int r)
    {
        // Time Complexity: O(nlogn)
        // Auxiliary Space: O(n)
        // In Place : No, it does not require extra space.
        // Stable : Yes, it does not change the relative order of elements which are equal.
        // Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves,
        // and then merges the two sorted halves. The merge() function is used for merging two halves.
        // The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted
        // and merges the two sorted sub-arrays into one.
        // See following C implementation for details.
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[m + 1 + i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];
        while (j < n2)
            arr[k++] = R[j++];
        }

    void mergeSort(vector<int> &arr, int l, int r)
    {
        // Time Complexity: O(nlogn)
        // Auxiliary Space: O(n)
        // In Place : No, it does not require extra space.
        // Stable : Yes, it does not change the relative order of elements which are equal.
        // Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves,
        // and then merges the two sorted halves. The merge() function is used for merging two halves.
        // The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted
        // and merges the two sorted sub-arrays into one.
        // See following C implementation for details.
        if (l < r)
        {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    void quick(vector<int> &arr, int l, int r)
    {
        // Time Complexity: O(nlogn)
        // Auxiliary Space: O(1)
        // In Place : Yes, it does not require extra space.
        // Stable : Yes, it does not change the relative order of elements which are equal.
        // QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
        // There are many different versions of quickSort that pick pivot in different ways.
        // Always pick first element as pivot.
        // Always pick last element as pivot (implemented below)
        // Pick a random element as pivot.
        // Pick median as pivot.
        // The key process in quickSort is partition().
        // Target of partitions is, given an array and an element x of array as pivot,
        // put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
        // and put all greater elements (greater than x) after x. All this should be done in linear time.
        if (l >= r)
            return;
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
                swap(arr[++i], arr[j]);
        }
        swap(arr[++i], arr[r]);
        quick(arr, l, i - 1);
        quick(arr, i + 1, r);
    }

    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heap(vector<int> &arr)
    {
        // Time Complexity: O(nlogn)
        // Auxiliary Space: O(1)
        // In Place : Yes, it does not require extra space.
        // Stable : Yes, it does not change the relative order of elements which are equal.
        // Heap sort is a comparison based sorting technique based on Binary Heap data structure.
        // It is similar to selection sort where we first find the maximum element and place the maximum element at the end.
        // We repeat the same process for remaining element.
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Sort ob;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before Sorting: ";
    ob.print(arr);
    cout << "After Sorting using selection sort: ";
    ob.selection(arr);
    ob.print(arr);
    ob.shuffle(arr);
    cout << "After shuffling: ";
    ob.print(arr);
    cout << endl;
    cout << "Before Sorting: ";
    ob.print(arr);
    cout << "After Sorting using bubble sort: ";
    ob.bubble(arr);
    ob.print(arr);
    ob.shuffle(arr);
    cout << "After shuffling: ";
    ob.print(arr);
    cout << endl;
    cout << "Before Sorting: ";
    ob.print(arr);
    cout << "After Sorting using merge sort: ";
    ob.mergeSort(arr, 0, n - 1);
    ob.print(arr);
    ob.shuffle(arr);
    cout << "After shuffling: ";
    ob.print(arr);
    cout << endl;
    cout << "Before Sorting: ";
    ob.print(arr);
    cout << "After Sorting using selection sort: ";
    ob.selection(arr);
    ob.print(arr);
    ob.shuffle(arr);
    cout << "After shuffling: ";
    ob.print(arr);
    cout << endl;
    cout << "Before Sorting: ";
    ob.print(arr);
    cout << "After Sorting using quick sort: ";
    ob.quick(arr, 0, n - 1);
    ob.print(arr);
    ob.shuffle(arr);
    cout << "After shuffling: ";
    ob.print(arr);
    return 0;
}
