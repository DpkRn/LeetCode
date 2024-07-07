class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int cnt=0;
        // while(numBottles>=numExchange){
        //     numBottles=numBottles-numExchange+1;
        //     cnt+=numExchange;
        // }
        // cnt+=numBottles;
        // return cnt;
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};