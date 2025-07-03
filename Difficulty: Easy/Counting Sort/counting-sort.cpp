class Solution {
  public:
    // Function to arrange all letters of a string in lexicographical
    // order using Counting Sort.
    string countSort(string arr) {
        // code here
        sort(arr.begin(),arr.end());
        return arr;
    }
};