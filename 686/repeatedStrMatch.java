class Solution {
    public int repeatedStringMatch(String A, String B) {

      if (A.length() >= B.length()) {
        if (A.contains(B)) {
          return 1;
        }
        else if ((A + A).contains(B)) {
          return 2;
        }
        else {
          return -1;
        }
      }

      // A.length() < B.length()
      int res = 1;  // return value.
      StringBuilder As = new StringBuilder(A);  // string of repeated As.
      while (true) {
        res ++;
        if (As.append(A).indexOf(B) >= 0) {
          return res;
        }

        if (As.length() > B.length()) {
          return -1;
        }
      }
    }

    // unit tests for class Solution.
    public static void main(String[] args) {
      Solution s = new Solution();

      String str1 = "abcd";
      String subStr1 = "da";
      String subStr2 = "cdab";
      String subStr3 = "cdabcdab";

      assert s.repeatedStringMatch(str1, subStr1) == 2;
      assert s.repeatedStringMatch(str1, subStr2) == 2;
      assert s.repeatedStringMatch(str1, subStr3) == 3;

      System.out.println("All unit tests passed.");
    }
}
