class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //add character in string before shifting above means if if you are moving n to n-1 then first take s[n] character 
        string str="";
        while(n>0&&m>0){
            if(str1[n-1]==str2[m-1]){ //if both are equal take any one and move diagonaly in prev row and prev col
                str=str1[n-1]+str;
                n--;m--;
            }else if(dp[n-1][m]>dp[n][m-1]){
                str=str1[n-1]+str; n--;
            }else {   //if dp[n-1][m]<dp[n][m-1]  then you have to move on prev col || both are equal then you can move any side so better to choose with it move on prev col
                str=str2[m-1]+str;
                m--;               
            }
        }
        
        while(n>0) {str=str1[n-1]+str; n--;}
        while(m>0){ str=str2[m-1]+str; m--;}
        
        return str;
    }
};