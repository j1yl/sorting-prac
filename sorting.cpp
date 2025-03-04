#include <algorithm>

using namespace std;

void bubbleSort(int arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int elem = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > elem) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = elem;
  }
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; ++i)
    L[i] = arr[l + i];

  for (int j = 0; j < n2; ++j)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low;
  for (int j = low; j < high; ++j) {
    if (arr[j] <= pivot) {
      swap(arr[i], arr[j]);
      ++i;
    }
  }
  swap(arr[i], arr[high]);
  return i;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}