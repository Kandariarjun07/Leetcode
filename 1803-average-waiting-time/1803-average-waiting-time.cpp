class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        double totalWaitingTime = 0;
        for (auto& customer : customers) {
            int arrivalTime = customer[0];
            int processingTime = customer[1];
            currentTime = max(currentTime, arrivalTime) + processingTime;
            totalWaitingTime += currentTime - arrivalTime;
        }
        return totalWaitingTime / customers.size();
    }
};