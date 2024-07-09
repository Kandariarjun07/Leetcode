class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime = customers[0][0];
        long long finalTime = 0;
        for(auto customer : customers){
            int arrivalTime = customer[0];
            int timeReq = customer[1];
            if(currTime < arrivalTime) currTime = arrivalTime;
            currTime += timeReq;
            finalTime += (currTime - arrivalTime);
        }
        return (double)finalTime / (double)customers.size();
    }
};