class Solution {

    public int getSum(int num) {
        int res = 0;
        while (num > 0) {
            res += (num % 10) * (num % 10);
            num = num / 10;
        }
        return res;
    }

    public boolean isHappy(int n) {
        if (n == 1) {
            return true;
        }
        Set<Integer> s = new HashSet<>();
        while (true) {
            int x = getSum(n);
            if (x == 1) {
                break;
            }
            if (s.contains(x)) {
                return false;
            }
            n = x;
            s.add(x);
        }
        return true;
    }
}