class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;
        for(auto g:gas) totalGas+=g;
        int totalCost = 0;
        for(auto c:cost) totalCost+=c;

        if(totalGas<totalCost) return -1;

        int curntgas = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++)
        {
            curntgas = curntgas+gas[i]-cost[i];
            if(curntgas<0)
            {
                start=i+1;
                curntgas=0;
            }
        }
        return start;       
    }
};