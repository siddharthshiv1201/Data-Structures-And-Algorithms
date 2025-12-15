class Solution {
    public int majorityElement(int[] nums) {
        List <Integer> list=new ArrayList<>();
        for(int x: nums){
            list.add(x);
        }
        Collections.sort(list);
        for(int i=0; i<nums.length; i++){
            nums[i]=list.get(i);
        }
        return nums[nums.length/2];
        
    }
}