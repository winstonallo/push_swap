# Push_swap 42 Project

42 uni project

## Overview

The Push_swap project requires you to sort a stack of integers using two stacks (A and B) and a specific set of operations. In this tutorial, we'll be using the Radix sort algorithm, which sorts numbers by their digits.

## Step 1: Understanding Radix Sort

Radix sort is a non-comparative sorting algorithm that works on integers by processing individual digits. It sorts numbers from the least significant digit (rightmost) to the most significant digit (leftmost).

Consider the following stack:

```
16 

127 

91 

890

19
```

### 1. (Sorting by Last Digit):

```
890 (0)

091 (1)

016 (6)

127 (7)

019 (9)
```

### 2. (Sorting by Second Last Digit):

```
016 (1)

019 (1)

127 (2)

890 (9)

091 (9)
```

### 3. (Final Sorting by First Digit):

```
016 (0)

019 (0)

091 (0)

127 (1)

890 (8)
```

## Step 2: Implementation Details

### Maximum Digits

To apply Radix sort, you first need to find out the maximum number of digits in the list. This will be used as a stopping condition for the loop (you loop max_digits times).

### Using Stacks

The key challenge in this project is that you're only allowed to use two stacks. To overcome this, you'll run the Radix sort algorithm on the binary representations of the integers.

**Two bitwise operators are used:**

```'>>' (Right Shift)``` 

This shifts the bits of a number to the right. For example, 5 >> 1 shifts the bits of 5 one step to the right, resulting in 2 (in binary, 101 becomes 10).

```'&' (And)```

This compares the bits of two numbers and sets the spots where both have a 1 to 1, the rest to 0. For example, 5 & 1 compares the binary representations of 5 (101) and 1 (001). The result is 1.

These operators help in finding the maximum number of digits and comparing the bits at each spot for sorting.

Bitwise Operations Example (file: src/radix_sort.c)

``if (((top_a->simple >> i) & 1) == 1)``

This line checks the i-th bit of top_a->simple.

## Bitwise Operations Examples


## Right Shift (>>) Example:

### Problem:

Shift the bits of 5 one step to the right.

```
int num = 5;
int result = num >> 1;
printf("%d", result);
OUTPUT
2
```

### Explanation:

5 in binary is 101.

Shifting one step to the right gives 10, which is 2 in decimal.


## And (&) Example:

### Problem:

Perform a bitwise AND operation between 5 and 1.

```
int num1 = 5;
int num2 = 1;
int result = num1 & num2;
printf("%d", result);
OUTPUT
1
```

### Explanation:

5 in binary is 101.

1 in binary is 001.

Performing the AND operation:

First bit: 1 & 0 = 0

Second bit: 0 & 0 = 0

Third bit: 1 & 1 = 1

The result is 001, which is 1 in decimal.


### Additional Note:

These examples demonstrate how bitwise operations work on individual bits within binary representations of numbers. In the context of your Push_swap project, these operations are 

used to manipulate the bits to determine the maximum number of digits and to compare the bits at each position during sorting.

## Step 3: Handling Negative Numbers

Radix sort doesn't handle negative numbers well, as -100 has more bits than 100. To solve this, you can index the numbers in your stack and sort them using their indexes.

Example:

```
78

-2

100

-18

5
```

Becomes:

```
3

1

4

0

2
```

## Step 4: Special Cases

Radix sort may not perform well with small stacks, as it always runs max_bits times. To address this, you can hardcode solutions for cases with 3 and 5 values (in simple_sort.c).

## Error handling

Most tricky thing is integer overflow checking, here is a nice implementation of atoi with integrated int overflow check (approach 3)
https://www.geeksforgeeks.org/write-your-own-atoi/
Other than that it is pretty straightforward, check the subject for details:)

### grade 
84/100 - Radix sort is not fast enough for 100 points (3/5 - 1084 operations for 100 values & 4/5 - 6784 operations for 500 values)
