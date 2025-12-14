class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        List<Integer> list=new ArrayList<>();
        for(int x:nums){
            list.add(x);
        }
        int count=0;
        int maxi=0;
        for(int i=0; i<list.size(); i++){
            if(list.get(i)!=1){
                maxi=Math.max(maxi,count);
                count=0;
            }
            else{
                count++;
            }
        }
        maxi=Math.max(maxi,count);
        return maxi;

        
    }
}