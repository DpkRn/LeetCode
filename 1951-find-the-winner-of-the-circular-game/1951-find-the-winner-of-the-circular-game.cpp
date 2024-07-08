class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle;
        for(int i=0;i<n;i++){
            circle.push_back(i+1);
        }
        while(circle.size()>1){
            int size=circle.size();
            int r=k%size;
            rotate(circle.begin(),circle.begin()+r,circle.end());
            circle.pop_back();
       }
        return circle[0];
    }
};