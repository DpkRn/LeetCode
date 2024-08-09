class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                int sum3=0; int sum4=0; int flag=0; int final=-1; vector<int> reg(10,0);
                for(int a=0;a<3;a++){
                        sum3+=grid[i+a][j+a];
                        sum4+=grid[i+a][j+2-a];
                    int sum1=0; int sum2=0;
                    for(int b=0;b<3;b++){
                        sum1+=grid[i+a][j+b];
                        sum2+=grid[i+b][j+a];
                        if(grid[i+a][j+b]<=0||grid[i+a][j+b]>9||reg[grid[i+a][j+b]]==1){
                            flag=1;
                        }else
                        reg[grid[i+a][j+b]]=1;
                    }
                    if(final==-1){
                        final=sum1;
                    }
                    if(final!=sum1||final!=sum2) flag=1;

                }
                if(final!=sum3||final!=sum4) flag=1;
                if(flag==0) cnt++;
            }
           
        }
        return cnt;
    }
};