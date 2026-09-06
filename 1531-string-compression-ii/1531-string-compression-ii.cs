public class Solution {
    public int GetLengthOfOptimalCompression(string s, int k) {
        int n = s.Length;
        int[,] dp = new int[n+1,k+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i,j] = 1000;
            }
        }
        dp[0,0] = 0;
        for(int i=1;i<=n;i++){
            for(int d=0;d<=k;d++){
                if(d>0)
                    dp[i,d] = dp[i-1,d-1];
                int same = 0;
                int deleted = 0;
                for(int j=i;j>=1;j--){
                    if(s[j-1] == s[i-1])
                        same++;
                    else
                        deleted++;
                    if(deleted > d)
                        break;
                    int len =1;
                    if(same >= 100)
                        len += 3;
                    else if(same >= 10)
                        len += 2;
                    else if( same >= 2)
                        len += 1;
                    
                    dp[i,d] = Math.Min(
                        dp[i,d],
                        dp[j-1,d-deleted] + len
                    );
                }
            }
        }
        return dp[n,k];
    }
}