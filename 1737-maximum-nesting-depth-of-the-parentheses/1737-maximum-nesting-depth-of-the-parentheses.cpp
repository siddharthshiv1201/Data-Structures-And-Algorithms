class Solution {
public:
    int maxDepth(string s) {

        int count = 0 ;
        int maxi = 0 ;
        int n = s.size()   ;
        int i = 0 ;

        while(i < n)
        {
            if(s[i] == '(' )
            {
                count++ ;
                maxi = max(count , maxi) ;
                i++ ;


            }

            else if(s[i] == ')')
            {
                count -- ;
                i++ ;

            }

            else
            i++ ;


        }

        return maxi ; 


        
    }
};