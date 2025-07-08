class Solution {
public:
    bool check1(char a,char b){
        if(abs(a - b) == 1){
            return true;
        }
        if(a == 'a' && b == 'z'){
            return true;
        }
        if(a == 'z' && b == 'a'){
            return true;
        }

        return false;
    }
   
    bool check3(string &s,int i,int j,vector<int>&keep){
        // checks what would be the smallest string if the current move is compared with the next move
        int n = s.size();

        while(i < n && j < n){
          
            if(keep[i] != -1){
                 i = keep[i];
                 continue;
            }
            
            if(keep[j] != -1){
                j = keep[j];
                continue;
            }

            if(s[i] > s[j]){
                return true;
            }
            if(s[i] < s[j]){
                return false;
            }

            i = i + 1;
            j = j + 1;




        }

        if(j >= n){
            return true;
        }
        else{
            return false;
        }
    }
    string lexicographicallySmallestString(string s) {
        int n = s.size();

        vector<vector<int>>rem(n+1,vector<int>(n+1,0)); // stores if a substring is removable
// range dp here
        for(int i=0;i<n-1;i++){
            if(check1(s[i],s[i+1])){ // base case  l = 2
                rem[i][i+1] = 1;
            }
        }
      
        for(int l=4;l<=n;l+=2){
            for(int i=0;i<n-l+1;i++){
                int j = i+l-1;
                
                if(check1(s[i],s[j]) && rem[i+1][j-1] == 1){
                    rem[i][j] = 1;
                }
                for(int k=i;k<=j;k++){
                    if(rem[i][k] == 1 && rem[k+1][j] == 1){
                        rem[i][j] = 1;
                    }
                }
            }
        }
   
        s.push_back('a' - 1);
       
        vector<int>keep(n+1);  // stores the next best move
        // lexodp here
        keep[n] = -1;
        for(int i=n-1;i>=0;i--){
           
         
            keep[i] = -1; // take and move i+1
           
            int nx = i;
            for(int j=i;j<n;j++){
                if(rem[i][j] == true && check3(s,nx,j+1,keep)){
                      
                        keep[i] = j + 1;
                        nx = j+1;
                      
                }
            }

        }
     
        string ans;
       
        string p = "";
        int j = 0;
        while(j < n){
            if(keep[j] == -1){
                p.push_back(s[j]);
                j = j + 1;
            }
            else{
                j = keep[j];
            }
        }
        

        return p;
    }
};