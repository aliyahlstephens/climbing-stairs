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