class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int len = flowerbed.size();
        
        for(int i=0;i<len;i++){
           if(flowerbed[i] == 0){
                bool left_empty = (i == 0 || flowerbed[i-1] == 0 );
                bool right_empty = ( i == len-1 || flowerbed[i+1] == 0 );
                if(left_empty && right_empty){
                        flowerbed[i] = 1;
                        count++;
                }
           }
        }
        return count >= n;


    }
};