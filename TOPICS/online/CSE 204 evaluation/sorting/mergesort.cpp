//youtube video -> https://www.youtube.com/watch?v=TzeBrDU-JaY&list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U&index=5
#include <bits/stdc++.h>
using namespace std;

void merge(int left[], int right[], int arr[], int n)
{
    int mid = n / 2;
    int length_l = mid;
    int length_r = n - mid;
    //i is the smallest unpicked element in left array
    //j is the smallest unpicked element in rigth array
    //k is the position that needs to be filled in A
    int i, j, k;
    i = j = k = 0;

    while (i < length_l && j < length_r)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < length_l)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < length_r)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (int i = 0; i <= mid - 1; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i <= n - 1; i++)
    {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(left, right, arr, n);
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    //for faster i/o
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // //for file input output
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int arr[] = {56, 10, 32, 6, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, size);
    printarray(arr, size);
    return 0;
}