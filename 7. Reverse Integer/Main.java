/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [?231,  231 ? 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.*/

class Solution {
    public int reverse(int x) {
        int p,result = 0;
        while(x != 0){
            p = x % 10;
            int valresult = p + result * 10;
            if ((valresult - p) / 10 != result)
                return 0;
            x /= 10;
            result = valresult;
        }
        return result;
    }
}