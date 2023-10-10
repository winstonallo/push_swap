PUSH_SWAP 42 PROJECT

Solved using the Radix sort algortihm. Note that this is the laziest way
to pass this project with pretty much minimum points
(3 for 100 values and 4 for 500, equates to 84% grade).

Radix sort sorts by digits. Example:

16
127
91
890
19

The algorithm will first sort the numbers by their last digit, then the second last, etc:

Step 1   

89**0**   
9**1**      
1**6**       
12**7**   
1**9**       

Step 1    Step 2    Step 3

890       16        16
91        127       19
16        19        91
127       890       127
19        91        890

It does so by:

-Finding out the maximum number of digits in the list (in this case 3) to use it as a
stopping condition for the loop (onve you looped max_digits times, stack is sorted).

-Pushing each digit to its specific stack (0-9) and sticking them back together afterwards.

Example with above stack:

Step 1 (digit in 1s position):

0      1      2      3      4      5      6      7      8      9
890    91                                 16     127           19

Step 2 (digit in 10s position):

0      1      2      3      4      5      6      7      8      9
       16                                               890
       19                                               91
       127                                             

Step 3 (digit in 100s position):

0      1      2      3      4      5      6      7      8      9
16     127                                              890
19
91

Notice that here, we are using 10 different stacks, whereas for push_swap 
we are only allowed 2. 
The solution to that problem is running this algorithm on the binary values 
of our integers.
For this we will use two different bitwise operators:

'>>'    Right Shift: 5 >> 1 shifts the bits of 5 1 step to the right.
        5 is 101 in binary, so by performing this operation we get 10, which is 2 in binary.

'&'     And: 5 & 1 compares the bits of two numbers and sets the spots where both have 
        a 1 to 1, the rest to 0. 
        5 is 101 in binary, 1 is 001.
        First digit is 1 for 5, 0 for 1 so we get 0.
        Second digit is 0 fot both so we get 0 as well.
        Last digit is 1 for both, so we get 1, which leaves us with 001, aka 1.

We use these to find the maximum number of digits in the biggest number of the list (right shift until 
it becomes 0 and count, basically just like a strlen), and then compare the numbers bits at each spot,
keep the 1s in stack a, push 0s to stack b, and at the end of each iteration we push everything back to stack a, 
shift the numbers one more step to the right and start over.

Bitwise operations are confusing at first, I would recommend you to do some on paper for a bit and it
will make a lot more sense.

Last important thing: Radix sort does not work well with negative numbers (-100 has more bits than 100,
so it would end up being sorted wrong).
In order to solve that problem, I indexed the numbers in my stack and sorted them using their indexes.
Example:

78    -2    100   -18   5

Becomes:

3     1     4     0     2

We only get graded on the number of operations we run on the stack to sort it, so we can feel free to do some work on
it before in order to make the final process easier :)).

Radix  also does not do well with small stacks, since it will always run mac_bits times no matter what.
During the evaluation there will be tests 3 and 5 values, so I hardcoded thoses cases. (simple_sort.c)

Good luck:)


        