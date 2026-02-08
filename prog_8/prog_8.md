# Sorting Algorithm Comparison Tool

## What I Made
Program that lets you pick a sorting algorithm and see how many comparisons and swaps it does.

## Sorting Methods Included

**Bubble Sort** - Compares neighbors repeatedly, largest bubbles to end

**Selection Sort** - Finds minimum in unsorted part, places it correctly

**Insertion Sort** - Builds sorted array one element at a time

**Merge Sort** - Divides array in half recursively, merges sorted halves

## Global Counters
`comp` and `swaps` track operations during sorting

## How Each Sort Works

Bubble: nested loops, swap if left > right

Selection: find min index, swap once per pass

Insertion: shift elements right to make space, insert element

Merge: split until size 1, merge while comparing

## Main Program Flow
1. Ask user for array size
2. Fill with random numbers 1-1000
3. Show unsorted array
4. Display menu of sorting options
5. Run chosen algorithm
6. Print sorted array
7. Show comparison and swap counts

## Example Run
```
Enter N: 5
Before Sorting:
734 125 892 456 213

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

After Sorting:
125 213 456 734 892

Comparisons: 10, Swaps: 6
```