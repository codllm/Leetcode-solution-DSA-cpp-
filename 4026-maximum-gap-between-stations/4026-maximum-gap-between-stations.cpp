class Solution {
public:
    int maximumGap(string workers, string station) {

        vector<int>leftsidefilling(workers.size());

        int pos = 0;
        int i=0;
        while(pos<station.size() && i<workers.size())
        {
            if(workers[i] == station[pos])
            {
                leftsidefilling[i] = pos;
                i++;               
            }
            pos++;
        }

        vector<int>rightsidefilling(workers.size());
        i = workers.size()-1;
        pos = station.size()-1;
        while(i>=0 && pos>=0)
        {
            if(workers[i] == station[pos])
            {
                rightsidefilling[i] = pos;
                i--;
            }
            pos--;
        }

        int gap = INT_MIN;

        for(int i=1;i<rightsidefilling.size();i++)
        {
            gap = max(gap,rightsidefilling[i]-leftsidefilling[i-1]);
        }
        return (gap)==INT_MIN ? 0:gap;
        
    }
};