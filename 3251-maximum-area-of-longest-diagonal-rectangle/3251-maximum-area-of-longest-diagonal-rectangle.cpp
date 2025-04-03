class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDig=0;
        int maxA=0;
        for(int i=0; i<dimensions.size(); i++){
            int l=dimensions[i][0];
            int b=dimensions[i][1];

            double dig=sqrt(l*l + b*b);
            int area=l*b;

            if(dig>maxDig){
                maxDig=dig;
                maxA=area;
            }
            else if(dig==maxDig){
                if(area>maxA)
                maxA=area;
            }
        }
        return maxA;

        
    }
};