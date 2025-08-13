# Climbing Stairs Problem

## Problem Description

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb **1 or 2 steps**. In how many distinct ways can you climb to the top?

## Examples

### Example 1:
- **Input:** n = 2
- **Output:** 2
- **Explanation:** There are two ways to climb to the top:
  1. 1 step + 1 step
  2. 2 steps

### Example 2:
- **Input:** n = 3
- **Output:** 3
- **Explanation:** There are three ways to climb to the top:
  1. 1 step + 1 step + 1 step
  2. 1 step + 2 steps
  3. 2 steps + 1 step

## Constraints
- 1 ≤ n ≤ 45

## Solution Approach

This problem can be solved using **Dynamic Programming** with a bottom-up approach. The key insight is recognizing the pattern that emerges:

### Pattern Recognition
- For n = 1: 1 way
- For n = 2: 2 ways  
- For n = 3: 3 ways
- For n = 4: 5 ways
- For n = 5: 8 ways

**This follows the Fibonacci sequence!** Each step's number of ways equals the sum of the previous two steps.

### Mathematical Formula
```
ways(n) = ways(n-1) + ways(n-2)
```

### Algorithm Steps
1. **Base Cases:** Handle n ≤ 2 directly
2. **Iterative Calculation:** Use two variables to track previous two values
3. **Build Up:** Calculate each step by summing the previous two
4. **Return Result:** The final calculated value

## Time and Space Complexity

- **Time Complexity:** O(n) - We iterate through each step once
- **Space Complexity:** O(1) - We only use a constant amount of extra space

## Code Implementation

The solution is implemented in `code.cpp` using C++:

```cpp
class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 2) return n;
        
        // Use dynamic programming to build up the solution
        int prev2 = 1;  // ways to climb 1 stair
        int prev1 = 2;  // ways to climb 2 stairs
        
        // Calculate ways for each step from 3 to n
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};
```

## Alternative Solutions

### 1. Recursive Approach (Not Recommended for Large n)
```cpp
int climbStairs(int n) {
    if (n <= 2) return n;
    return climbStairs(n-1) + climbStairs(n-2);
}
```
- **Time Complexity:** O(2^n) - Exponential due to repeated calculations
- **Space Complexity:** O(n) - Call stack depth

### 2. Memoization (Top-down DP)
```cpp
int climbStairs(int n, vector<int>& memo) {
    if (n <= 2) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
    return memo[n];
}
```
- **Time Complexity:** O(n)
- **Space Complexity:** O(n)

## Why This Solution Works

The solution works because:
1. **Optimal Substructure:** The solution for n steps depends on solutions for n-1 and n-2 steps
2. **Overlapping Subproblems:** Many subproblems are solved multiple times
3. **Fibonacci Pattern:** The problem naturally follows the Fibonacci sequence
4. **Efficient Iteration:** We avoid recursion and use constant space

## Testing the Solution

You can test the solution with various inputs:
- n = 1 → 1 way
- n = 2 → 2 ways  
- n = 3 → 3 ways
- n = 4 → 5 ways
- n = 5 → 8 ways
- n = 6 → 13 ways

## Related Problems

This problem is a classic example of:
- Dynamic Programming
- Fibonacci Sequence
- Combinatorial Problems
- Recursion and Iteration

## Learning Resources

- [Dynamic Programming Concepts](https://en.wikipedia.org/wiki/Dynamic_programming)
- [Fibonacci Sequence](https://en.wikipedia.org/wiki/Fibonacci_number)
- [LeetCode Problem 70](https://leetcode.com/problems/climbing-stairs/)
