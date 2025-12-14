import java.util.*;

class Solution {
    public int singleNumber(int[] nums) {

        Map<Integer, Integer> map = new HashMap<>();

        // frequency count
        for (int x : nums) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        // frequency 1 wala element return
        for (int x : nums) {
            if (map.get(x) == 1) {
                return x;
            }
        }

        return -1; // safety, though question me hamesha answer hota hai
    }
}
