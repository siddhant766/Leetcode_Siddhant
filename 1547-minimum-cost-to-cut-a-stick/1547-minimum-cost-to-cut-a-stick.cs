public class Solution {
    public int MinCost(int n, int[] cuts) {
        int m = cuts.Length;
        int[] arr = new int[m+2];
        arr[0] = 0;
        arr[m+1] = n;
        for(int i=0;i<m;i++){
            arr[i+1] = cuts[i];
        }
        Array.Sort(arr);
        int[,] dp = new int[m+2,m+2];
        for(int length = 2; length <m+2; length++){
            for(int i=0;i+length<m+2;i++){
                int j = i+length;
                dp[i,j] = int.MaxValue;
                for(int k=i+1;k<j;k++){
                    int cost = arr[j] - arr[i] + dp[i,k]+dp[k,j];
                    dp[i,j] = Math.Min(dp[i,j],cost);
                }
                if(dp[i,j] == int.MaxValue){
                    dp[i,j] = 0;
                }
            }
        }
        return dp[0,m+1];
    }
}