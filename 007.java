import java.lang.Math;

class Solution {
  public int reverse(int x) {
    long res = 0; // reversed integer.
    int min = (int) (0 - Math.pow(2, 31)); // minimal signed 32-bit int
    int max = (int) (Math.pow(2, 31) - 1); // maximum signed 32-bit int
    //System.out.println("max is: " + max);
    //System.out.println("min is: " + min);

    int len = 10; // length of array
    int[] arr = new int[len]; // array to store the digits

    // compute each digit, from least significant to most significant.
    for (int i = 0; i < len; i++) {
      arr[i] = (int) ((x % Math.pow(10, i + 1)) / Math.pow(10, i));
    }

    // compute number of leading 0s of x.
    int numOfLeadZero = 0;
    for (int i = 0; i < len; i++) {
      if (arr[len-1-i ] == 0) {
        numOfLeadZero++;
      }
      else {
        break;
      }
    }

    int digits = len - numOfLeadZero;
    //System.out.println("digits is: " + digits);

    // compute reversed int from arr.
    for (int i = 0; i < digits; i++) {
      res = res + arr[i] * (long) Math.pow(10, digits - 1 - i);
    }
    //System.out.println("raw res is: " + res);

    // overflow.
    if ((res > max)|| (res < min)) {
      return 0;
    }

    return (int) res;
  }

  public static void main(String[] args) {
    int res = 0 ;
    int[] arr = {123, -123, 120, 0, 483647, 2147483647, -2147483648};

    Solution s = new Solution();
    for (int i = 0 ; i < 7; i++) {
      res = s.reverse(arr[i]);
      System.out.println(res);
    }
  }
}
