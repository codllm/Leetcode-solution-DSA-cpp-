class Solution {
    private:
    int BSfindBestLight(vector<int>& lights,int arrivalTime,int period)
    {
        int left = 0;
        int right = lights.size()-1;

        int waitingTime = arrivalTime % period;
        int penality = -1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;

            if(waitingTime < lights[mid])
            {
                penality = mid;
                right = mid-1;
                // i find the best light for this acr to assign with the penality
            }
            else
            {
                //search for better option
                left = mid+1;
            }
        }
        //using the binary serach trying to find the minimum penality for each car
        // and that is what giving 

        if(penality!= -1) return 0;//maine ek light find kiya jiske liye penality 0 tha

        return period-waitingTime;
    }
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {

        sort(lights.begin(),lights.end());
        int ans = 0;
        for(int i=0;i<arrivalTime.size();i++)
        {
            //trying tp store max among all the min penality i have get
            ans = max(ans,BSfindBestLight(lights,arrivalTime[i],period));       
        }
        return ans;       
    }
};