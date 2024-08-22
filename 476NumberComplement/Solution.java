class Solution {
  public int findComplement(int num) {
    if (num == 0) return 0;
    return findComplement(num / 2) * 2 + (num % 2 == 0 ? 1 : 0);
  }
}
