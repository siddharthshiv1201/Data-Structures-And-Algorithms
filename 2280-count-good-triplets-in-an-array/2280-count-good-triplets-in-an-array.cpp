class BIT {
    vector<int> tree;
    int n;

public:
    BIT(int size) : n(size) {
        tree.resize(n + 2, 0);
    }

    void update(int i, int val) {
        for (++i; i <= n + 1; i += i & -i)
            tree[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i;
        }

        vector<int> transformed(n);
        for (int i = 0; i < n; ++i) {
            transformed[i] = pos[nums1[i]];
        }

        BIT bitLeft(n), bitRight(n);
        vector<int> leftSmaller(n, 0), rightGreater(n, 0);

        // Count rightGreater
        for (int i = n - 1; i >= 0; --i) {
            rightGreater[i] = bitRight.query(transformed[i] + 1, n);
            bitRight.update(transformed[i], 1);
        }

        long long ans = 0;

        // Count leftSmaller and compute triplets
        for (int i = 0; i < n; ++i) {
            leftSmaller[i] = bitLeft.query(transformed[i] - 1);
            ans += 1LL * leftSmaller[i] * rightGreater[i];
            bitLeft.update(transformed[i], 1);
        }

        return ans;
    }
};