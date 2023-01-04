#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int n1 = mid - s + 1;
    int n2 = e - mid;
    int *first = new int[n1];
    int *second = new int[n2];
    int k = s;
    for (int i = 0; i < n1; i++)
        first[i] = arr[k++];
    k = mid + 1;
    for (int i = 0; i < n2; i++)
        second[i] = arr[k++];
    int i = 0;
    int j = 0;
    k = s;
    while (i < n1 && j < n2)
    {
        if (first[i] < second[j])
            arr[k++] = first[i++];
        else
            arr[k++] = second[j++];
    }
    while (i < n1)
        arr[k++] = first[i++];
    while (j < n2)
        arr[k++] = second[j++];
    delete[] first; 
    delete[] second; 
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{
    int arr[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    int size = 9;
    mergeSort(arr, 0, size - 1);
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
