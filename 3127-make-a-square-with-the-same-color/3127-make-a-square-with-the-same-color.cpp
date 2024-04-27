class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n=grid.size();
        
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
               int cntW=0,cntB=0;
                for(int m1=0;m1<2;m1++){
                    for(int m2=0;m2<2;m2++){
                        if(grid[i+m1][j+m2]=='B') cntB++;
                        else cntW++;
                    }
                }
                cout<<cntB<<" "<<cntW<<endl;
                if(cntB>2||cntW>2) return true;
            }
        }
        return false;
    }
};
/*
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int i=1;i<3;i++){
            for(int j=1;j<3;j++){
                int x=(grid[i][j-1])+(grid[i-1][j])+(grid[i-1][j-1])+(grid[i][j]);
                cout<<x<<" "<<endl;
                if(x==285||x==327||x==264||x==348){
                    
                    return true;
                }
            }
        }
        return false;
    }
};
*/