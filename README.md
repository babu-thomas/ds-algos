# Notes

## 2018-01-31
### [binary_search.cpp](https://github.com/babu-thomas/ds-algos/blob/master/binary_search.cpp)
- Binary stride version of binary search
	- "Look before you leap"
	- Successively reduce the jumping distance by half, starting with a jump size of N/2.
	- One thing I was confused about is what happens if N/2 is too far. The answer is that we only
	jump if the value at jump location is less than or equal to the value we are searching for.
	Thus, overjumping doesn't occur.
	- The version I have implemented returns the last occurence of the target value, of course it
	can be modified to return as soon as it finds the target value, thus returning the first occurence.

## 2018-02-02
### [2sum.cpp](https://github.com/babu-thomas/ds-algos/blob/master/2sum.cpp)
- 2sum problem - Find a pair with a given sum
	- Leetcode problem statement says to assume there is exactly one pair, which makes it a little
	easier.
	- In hashing solution we have to take care that we are not considering the current element twice,
	so we only insert the current element in the hash table after we have checked for its pair.
	For example, let current element is 8 and sum is 16. If we insert 8 first and then check for
	16 - 8 = 8, we will find it and erroneously make a pair of (8, 8). But if we check first and
	then insert, there will be no (8, 8) pair, which is the correct answer.

### [3sum.cpp](https://github.com/babu-thomas/ds-algos/blob/master/3sum.cpp)
- 3sum problem - Find all triplets which sum to zero
	- It seems that these type of problems have a general solution. In this one sorting the array,
	fixing one number and then using two pointer approach to find the other two is the most efficient.
	- The above approach outputs duplicate triplets, to remove duplicates see next problem.

## 2018-02-03
### [3sum_unique.cpp](https://github.com/babu-thomas/ds-algos/blob/master/3sum_unique.cpp)
- 3sum_unique - Find all UNIQUE triplets which sum to zero
	- Approach is same as 3sum, just need to skip duplicates.
	- Skip duplicates for the first number, second number and the third number.
	- Due to sorting, the triplets are also ordered triplets, so the solution gives unique ordered triplets.

## 2018-02-04
### [dutch_national_flag.cpp](https://github.com/babu-thomas/ds-algos/blob/master/dutch_national_flag.cpp)
- Dutch national flag problem - Sort an array containing 0, 1 and 2 only in linear time and constant space.
	- One approach is counting the number of 0s, 1s and 2s in the first pass. Then we just have to
	insert that many 0, 1, 2 one after the other in the second pass. This requires 2 passes of the
	array.
	- Another better approach is 3-way partitioning. Maintain 3 pointers - low, mid and high.
	- low points to one after the 0s, mid points to the first unknown element and high points to one
	before the last 2.
	- Initially low and mid are at position zero and high is at last element.
	- Increment mid upto high and perform the following operations:
		- if A[mid] is 1, mid++
		- else if A[mid] is 0, swap with A[low], low++, mid++
		- else A[mid] will be 2, then swap with A[high], high-- (don't increment mid)
	- Incrementing mid is okay in the second case because low will be always less than mid. That
	means whatever low points to will be 0 or 1, which will be in their correct places after being swapped.
	- However we don't increment mid in the third case because high may be pointing to 0, 1 or 2. We
	don't know what yet. So it is unknown and mid points to it after swapping. Then in the next iteration
	it will be in the right place.

### [max_sum_subarray.cpp](https://github.com/babu-thomas/ds-algos/blob/master/max_sum_subarray.cpp)
- Maximum sum of contiguous subarray
	- Naive approach is to consider all contiguous subarrays.
	- There are `[N * (N + 1) / 2]` contiguous subarrays. This is because there are N subarrays of size 1,
	N-1 subarrays of size 2, N-2 subarrays of size 3 and so on to 1 subarray of size N. Thus number of subarrays
	goes from N to 1. Sum of numbers from 1 to N is `[N * (N + 1) / 2]`.
	- Complexity of naive approach is therefore O(N^2).
	- In naive approach outer loop index is the starting position of the subarray and the inner loop index
	is the ending position of the subarray.
	- Another approach is the divide and conquer approach. A max sum subarray will be of the following types -
		1. Containing elements only in the left half of the original array
		2. Containing elements only in the right half of the original array
		3. Containing elements from both halves of the original array
	- Types `a` and `b` can be solved recursively.
	- For type `c`, we find max suffix sum of left half and max prefix sum of right half. Adding them gives
	max subarray sum containing elements from both halves. This can be done in O(N) time.
	- The overall solution is the max of solutions of above three types.
	- The time complexity for this solution can be expressed as -
		- `T(N) = 2 * T(N/2) + O(N)` which on solving gives O(N.LogN).
	- Kadane's Algorithm
		- If for a index `i` we have the max sum of a contiguous subarray ending at `i`, what will be the
		max sum of contiguous subarray ending at `i + 1`?
		- The max subarray for index `i + 1` will either include the elements from the index `i` subarray as
		prefix along with the element at index `i + 1` or it will only include the single element at
		index `i + 1`, whichever is greater.
		- The maximum of these values calculated for each index is the solution to the original problem.
