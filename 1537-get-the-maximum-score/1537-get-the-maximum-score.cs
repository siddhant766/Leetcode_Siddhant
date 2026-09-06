public class Solution {
    public int MaxSum(int[] nums1, int[] nums2) {
        const long MOD = 1000000007;
        int i = 0; 
        int j = 0;
        long sum1 = 0;
        long sum2 = 0;
        while(i<nums1.Length && j < nums2.Length){
            if(nums1[i] < nums2[j]){
                sum1 += nums1[i];
                i++;
            }else if( nums2[j] < nums1[i]){
                sum2 += nums2[j];
                j++;
            }else{
                long best = Math.Max(sum1,sum2) + nums1[i];
                sum1 = best;
                sum2 = best;
                i++;
                j++;
            }
        }
        while(i<nums1.Length){
            sum1 += nums1[i];
            i++;
        }
        while(j<nums2.Length){
            sum2 += nums2[j];
            j++;
        }
        return (int)(Math.Max(sum1,sum2)%MOD);

    }
}