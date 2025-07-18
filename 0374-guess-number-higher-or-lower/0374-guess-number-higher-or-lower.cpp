/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start=1;
        int end=n;
        while(true){
            int mid=start+((end-start)/2);
            int a=guess(mid);
            
             if(a>0) start=mid+1;
            else if(a<0)end=mid-1;
            else return mid;
        }   
    }
};