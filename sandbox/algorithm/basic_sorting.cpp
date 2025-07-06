#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

void bubble_sort(int a[], int &n)
{

  for (int i = n - 1; i >= 0; --i)
  {

    for (int j = 0; j < i; ++j)
    {
      if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);
    }
  }
}

void selection_sort(int a[], int &n)
{

  for (int i = 0; i < n - 1; ++i)
  {
    int mn = a[i], index = i;

    for (int j = i + 1; j < n; ++j)
    {
      if (a[j] < mn)
      {
        index = j;
        mn = a[j];
      }
    }
    swap(a[i], a[index]);
  }
}

void insertion_sort(int a[], int &n)
{

  for (int i = 1; i < n; ++i)
  {
    int j, tmp = a[i];

    for (j = i - 1; j >= 0; --j)
    {
      if (a[j] <= tmp)
        break;
      a[j + 1] = a[j];
    }

    a[j + 1] = tmp;
  }
}

void quick_sort(int a[], int i, int j, int &n)
{
  if (j <= i)
    return;

  int pivot = a[j];
  int swap_pos = i;
  for (int k = i; k < j; ++k)
  {
    if (a[k] < pivot)
    {
      swap(a[k], a[swap_pos]);
      swap_pos++;
    }
  }
  swap(a[j], a[swap_pos]);

  quick_sort(a, i, swap_pos - 1, n);
  quick_sort(a, swap_pos + 1, j, n);
}

int main()
{
  int arr[] = {3, 1, 1, 3, 2, 8, 14, 4, 15, 20, 12, 7, 11, 18, 5, 6, 9, 16, 10, 17, 19}, n = 21;

  //    bubble_sort(arr, n);
  //    selection_sort(arr, n);
  //    insertion_sort(arr, n);
  //    quick_sort(arr, 0, n-1, n);
  for (int i = 0; i < n; ++i)
    cout << arr[i] << ' ';
  return 0;
}
