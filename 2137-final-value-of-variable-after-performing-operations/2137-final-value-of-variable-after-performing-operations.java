class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int result = 0;

        for (String x : operations) {
            if (x.charAt(1) == '-') {
                result--;
            } else {
                result++;
            }
        }

        return result;
    }
}