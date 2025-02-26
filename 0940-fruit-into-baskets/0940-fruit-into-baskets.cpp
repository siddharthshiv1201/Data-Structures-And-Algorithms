class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int count=0;
        int i=0;
        int j=0;
        int maxi=0;
        unordered_map<int,int> map1;
        while(j<fruits.size()){
            map1[fruits[j]]++;

            if(map1.size()>2){
                map1[fruits[i]]--;
                if(map1[fruits[i]]==0){
                    map1.erase(fruits[i]);
                   
                }
                i++;

            }
           maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;


        
    }
};