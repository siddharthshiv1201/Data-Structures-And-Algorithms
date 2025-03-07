class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> v;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                v.push_back(i);
            }
        }

        if (v.size() < 2) return {-1, -1}; // No prime pair exists.

        int mini = INT_MAX;
        vector<int> v1(2);
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] - v[i] < mini) {
                mini = v[i + 1] - v[i];
                v1[0] = v[i];
                v1[1] = v[i + 1];
            }
        }
        return v1;
    }
};
