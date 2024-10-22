#include "sorting.h"
#include "tdd.h"
#include <iostream>

using namespace std;

// O(n^2)
void run(int arr[], int n, std::string name, int expected[],
         void (*sort)(int arr[], int n)) {
  sort(arr, n);
  assertEquals(name, expected, arr, n);
}

// O(n log n)
void run(int arr[], int n, int l, int r, std::string name, int expected[],
         void (*sort)(int arr[], int l, int r)) {
  sort(arr, l, r);
  assertEquals(name, expected, arr, n);
}

int main() {
  cout << "Testing sorting functions.." << endl;

  int arr1[]{1, 3, 5, 2, 4, 6};
  int arr1_expected[] = {1, 2, 3, 4, 5, 6};
  int n1 = sizeof(arr1) / sizeof(int);

  int arr2[]{1, 4, 7, 2, 5};
  int arr2_expected[] = {1, 2, 4, 5, 7};
  int n2 = sizeof(arr2) / sizeof(int);

  int arr3[]{1, 3, 3, 2, 2, 4};
  int arr3_expected[] = {1, 2, 2, 3, 3, 4};
  int n3 = sizeof(arr3) / sizeof(int);

  int arr4[]{5, 8, 3, 7, 1, 9, 4};
  int arr4_expected[] = {1, 3, 4, 5, 7, 8, 9};
  int n4 = sizeof(arr4) / sizeof(int);

  int arr5[]{2, 10, 6, 8, 1, 4};
  int arr5_expected[] = {1, 2, 4, 6, 8, 10};
  int n5 = sizeof(arr5) / sizeof(int);

  int arr6[1000];
  for (int i = 0; i < 1000; i++)
    arr6[i] = 1000 - i;
  int arr6_expected[1000];
  for (int i = 0; i < 1000; i++)
    arr6_expected[i] = i + 1;
  int n6 = sizeof(arr6) / sizeof(int);

  // O(n^2) sorting algorithms
  // run every test case against every sorting algorithm
  run(arr1, n1, "Bubble Sort 1", arr1_expected, bubbleSort);
  run(arr2, n2, "Bubble Sort 2", arr2_expected, bubbleSort);
  run(arr3, n3, "Bubble Sort 3", arr3_expected, bubbleSort);
  run(arr4, n4, "Bubble Sort 4", arr4_expected, bubbleSort);
  run(arr5, n5, "Bubble Sort 5", arr5_expected, bubbleSort);
  run(arr6, n6, "Bubble Sort 6", arr6_expected, bubbleSort);

  run(arr1, n1, "Insertion Sort 1", arr1_expected, insertionSort);
  run(arr2, n2, "Insertion Sort 2", arr2_expected, insertionSort);
  run(arr3, n3, "Insertion Sort 3", arr3_expected, insertionSort);
  run(arr4, n4, "Insertion Sort 4", arr4_expected, insertionSort);
  run(arr5, n5, "Insertion Sort 5", arr5_expected, insertionSort);
  run(arr6, n6, "Insertion Sort 6", arr6_expected, insertionSort);

  run(arr1, n1, "Selection Sort 1", arr1_expected, selectionSort);
  run(arr2, n2, "Selection Sort 2", arr2_expected, selectionSort);
  run(arr3, n3, "Selection Sort 3", arr3_expected, selectionSort);
  run(arr4, n4, "Selection Sort 4", arr4_expected, selectionSort);
  run(arr5, n5, "Selection Sort 5", arr5_expected, selectionSort);
  run(arr6, n6, "Selection Sort 6", arr6_expected, selectionSort);

  // O(nlogn) sorting algorithms
  run(arr1, n1, 0, n1 - 1, "Merge Sort 1", arr1_expected, mergeSort);
  run(arr2, n2, 0, n2 - 1, "Merge Sort 2", arr2_expected, mergeSort);
  run(arr3, n3, 0, n3 - 1, "Merge Sort 3", arr3_expected, mergeSort);
  run(arr4, n4, 0, n4 - 1, "Merge Sort 4", arr4_expected, mergeSort);
  run(arr5, n5, 0, n5 - 1, "Merge Sort 5", arr5_expected, mergeSort);
  run(arr6, n6, 0, n6 - 1, "Merge Sort 6", arr6_expected, mergeSort);

  run(arr1, n1, 0, n1 - 1, "Quick Sort 1", arr1_expected, quickSort);
  run(arr2, n2, 0, n2 - 1, "Quick Sort 2", arr2_expected, quickSort);
  run(arr3, n3, 0, n3 - 1, "Quick Sort 3", arr3_expected, quickSort);
  run(arr4, n4, 0, n4 - 1, "Quick Sort 4", arr4_expected, quickSort);
  run(arr5, n5, 0, n5 - 1, "Quick Sort 5", arr5_expected, quickSort);
  run(arr6, n6, 0, n6 - 1, "Quick Sort 6", arr6_expected, quickSort);
}