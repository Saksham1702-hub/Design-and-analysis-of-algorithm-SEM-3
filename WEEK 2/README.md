# Searching and Sorting Algorithms

## What is Searching?

Searching is the process of finding a particular element, called the target, in a collection of data such as an array or list. Two common searching techniques are Linear Search and Binary Search.

---

## Linear Search

Linear Search checks each element one by one from the beginning of the list until it finds the required element or reaches the end of the list.

### Example

To find `7` in the list:

```text
[1][2][4][7][9]
```

Linear Search checks:

```text
4 → 2 → 7
```

It finds `7` at the third position.

### Features of Linear Search

- Works on both sorted and unsorted data.
- Simple to understand and implement.
- Checks elements one by one.
- Useful for small lists.
- Time complexity is `O(n)` in the worst case.

### Linear Search Example in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 2, 7, 1, 9};
    int n = 5;
    int target = 7;

    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i;
            return 0;
        }
    }

    cout << "Element not found";
    return 0;
}
```

---

## Binary Search

Binary Search is a searching technique used only on a sorted list. It compares the target with the middle element and removes half of the remaining search area after every comparison.

### Example

To find `7` in the sorted list:

```text
[1][2][4][7][9][12][15]
```

1. The middle element is `7`.
2. The target matches the middle element.
3. Therefore, the element is found.

If the target were smaller than the middle element, Binary Search would continue in the left half. If it were larger, it would continue in the right half.

### Features of Binary Search

- Works only when data is sorted.
- Checks the middle element first.
- Divides the search area into two halves at every step.
- Best for large sorted lists.
- Time complexity is `O(log n)`.

### Binary Search Example in C++

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 7, 9, 12, 15};
    int n = 7;
    int target = 9;

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid;
            return 0;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Element not found";
    return 0;
}
```

---

## Difference Between Linear Search and Binary Search

| Feature | Linear Search | Binary Search |
|---|---|---|
| Data requirement | Can work on sorted or unsorted data | Requires sorted data |
| Method | Checks every element one by one | Checks the middle element and halves the search area |
| Worst-case time complexity | `O(n)` | `O(log n)` |
| Best use case | Small or unsorted lists | Large, sorted lists |
| Implementation | Very simple | Slightly more complex |
| Speed | Usually slower for large data | Much faster for large sorted data |

---

## Why is Binary Search Better?

Binary Search is generally better than Linear Search when the data is already sorted and the list is large.

Linear Search may need to check every element. For example, in a list of 1,000 elements, it may take up to 1,000 comparisons to find an element at the end or determine that it is absent.

Binary Search removes half of the remaining elements after every comparison. For 1,000 sorted elements, it needs only about 10 comparisons in the worst case because:

```text
1000 → 500 → 250 → 125 → 62 → 31 → 15 → 7 → 3 → 1
```

Therefore, Binary Search is faster and more efficient for large sorted datasets. However, if data is unsorted, Linear Search is usually more suitable because sorting the data first can take additional time. Binary Search reduces the search range by half each step, which gives it `O(log n)` complexity, while Linear Search may inspect all `n` items and has `O(n)` complexity. [1][3][4]

---

# Sorting Algorithms

Sorting is the process of arranging data in a particular order, usually ascending or descending order.

### Example

Unsorted array:

```text
[1][2][5][7][9]
```

Sorted in ascending order:

```text
[1][2][5][7][9]
```

Sorting is important because sorted data is easier to read, organize, analyze, and search. Binary Search also requires sorted data.

---

## 1. Bubble Sort

Bubble Sort repeatedly compares two adjacent elements and swaps them if they are in the wrong order. Larger elements gradually move to the end of the array, like bubbles rising to the surface.

### Example

```text
[2][4][5]

Compare 5 and 2 → swap →[2][4][5]
Compare 5 and 4 → swap →[2][4][5]
```

### Complexity

```text
Best Case: O(n)
Average Case: O(n²)
Worst Case: O(n²)
```

### Use Case

Bubble Sort is easy to learn but inefficient for large datasets.

---

## 2. Selection Sort

Selection Sort repeatedly finds the smallest element from the unsorted part of the array and places it at the correct position.

### Example

```text
[1][2][4][5]

Smallest element is 1 → swap with 5
[1][2][4][5]
```

### Complexity

```text
Best Case: O(n²)
Average Case: O(n²)
Worst Case: O(n²)
```

### Use Case

Selection Sort is simple and makes fewer swaps than Bubble Sort, but it is still slow for large lists.

---

## 3. Insertion Sort

Insertion Sort builds a sorted section of the array one element at a time. It takes the next element and inserts it into its correct position among the already sorted elements.

### Example

```text
[2][4][5]

Start with 5
Insert 2 before 5 →[2][5]
Insert 4 between 2 and 5 →[4][5][2]
```

### Complexity

```text
Best Case: O(n)
Average Case: O(n²)
Worst Case: O(n²)
```

### Use Case

Insertion Sort works well for small datasets or data that is already nearly sorted.

---

## 4. Merge Sort

Merge Sort uses the divide-and-conquer approach. It divides the array into smaller parts, sorts each part, and then merges the sorted parts together.

### Example

```text
[2][3][8][9]

Divide:
 and[2][3][8][9]

Sort:
 and[3][8][9][2]

Merge:
[2][3][8][9]
```

### Complexity

```text
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)
```

### Use Case

Merge Sort is efficient for large datasets and gives reliable performance, but it requires extra memory for merging.

---

## 5. Quick Sort

Quick Sort selects an element called a pivot and divides the array into two parts:

- Elements smaller than the pivot.
- Elements greater than the pivot.

It then sorts both parts recursively.

### Complexity

```text
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n²)
```

### Use Case

Quick Sort is often very fast in practice and is commonly used for large arrays. Its performance depends on selecting a good pivot.

---

## 6. Heap Sort

Heap Sort uses a special tree-based structure called a heap. It repeatedly selects the largest or smallest element from the heap and places it in the correct position.

### Complexity

```text
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)
```

### Use Case

Heap Sort is useful when guaranteed `O(n log n)` performance is required and extra memory should be limited.

---

## 7. Counting Sort

Counting Sort is used when the range of values is small. It counts how many times each value appears and then reconstructs the sorted array.

### Example

```text
[1][2][3][4][8]

Sorted array:
[1][2][3][4][8]
```

### Complexity

```text
Time Complexity: O(n + k)
```

Here, `k` is the range of input values.

### Use Case

Counting Sort is efficient for integers within a limited range, but it is not suitable when the range of values is extremely large.

---

## Comparison of Sorting Algorithms

| Sorting Algorithm | Best Case | Average Case | Worst Case | Suitable For |
|---|---:|---:|---:|---|
| Bubble Sort | `O(n)` | `O(n²)` | `O(n²)` | Learning and very small datasets |
| Selection Sort | `O(n²)` | `O(n²)` | `O(n²)` | Small datasets with fewer swaps |
| Insertion Sort | `O(n)` | `O(n²)` | `O(n²)` | Small or nearly sorted data |
| Merge Sort | `O(n log n)` | `O(n log n)` | `O(n log n)` | Large datasets and stable sorting |
| Quick Sort | `O(n log n)` | `O(n log n)` | `O(n²)` | Fast general-purpose sorting |
| Heap Sort | `O(n log n)` | `O(n log n)` | `O(n log n)` | Guaranteed performance with low extra memory |
| Counting Sort | `O(n + k)` | `O(n + k)` | `O(n + k)` | Integers with a small value range |

---

## Conclusion

Linear Search checks elements one by one and works even when data is unsorted. Binary Search is faster because it repeatedly divides a sorted list into halves. For sorting, Bubble Sort, Selection Sort, and Insertion Sort are simple but slower for large data. Merge Sort, Quick Sort, and Heap Sort are more efficient for large datasets. The right algorithm depends on the size of the data, whether it is already sorted, memory limits, and the required speed. [10][12][13]
