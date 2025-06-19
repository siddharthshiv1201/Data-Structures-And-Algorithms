// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
//         int n = ages.size();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == j) continue; // Skip self
//                 if (ages[j] <= 0.5 * ages[i] + 7 || ages[j] > ages[i] || (ages[j] > 100 && ages[i] < 100)) {
//                     continue;
//                 }
//                 count++;
//             }
//         }
//         return count;
//     }
// };

// TLE 

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0); 
        for (int age : ages) {
            count[age]++;
        }

        int res = 0;
        for (int ageA = 15; ageA <= 120; ageA++) {
            if (count[ageA] == 0) continue;

            for (int ageB = 15; ageB <= 120; ageB++) {
                if (count[ageB] == 0) continue;


                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;


                int requests = count[ageA] * count[ageB];
                if (ageA == ageB) requests -= count[ageA]; 
                res += requests;
            }
        }
        return res;
    }
};
