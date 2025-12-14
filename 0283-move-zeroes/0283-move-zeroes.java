class Solution {
    public void moveZeroes(int[] nums) {
        List<Integer> list=new ArrayList<>();
        for(int x: nums){
            list.add(x);
        }
        int count=0;
        List<Integer> v=new ArrayList<>();
        for(int i=0; i<list.size();i++){
            if(list.get(i)!=0){
                v.add(list.get(i));
            }
            else{
                count++;
            }
        }
        for(int i=0; i<count; i++){
            v.add(0);
        }
        for(int i=0; i<nums.length; i++){
            nums[i]=v.get(i);
        }
    }
}