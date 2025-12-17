class Solution {
    public int maxProfit(int[] prices) {
        List<Integer> list=new ArrayList<>();
        for(int x:prices){
            list.add(x);
        }
        int maxi=Integer.MIN_VALUE;
        int mini=Integer.MAX_VALUE;
        for(int i=0; i<list.size(); i++){
            mini=Math.min(mini,list.get(i));
            maxi=Math.max(maxi,list.get(i)-mini);
            
        }
        return maxi;
        
    }
}