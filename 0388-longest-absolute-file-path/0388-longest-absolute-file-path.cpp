class Solution {
public:
    int lengthLongestPath(string input) {

        unordered_map<int,int>mpp;
        //map isliye use hua hai ki just to store the depth of its parent

        stringstream ss(input);
        string chunk;

        int res = 0;
        while(getline(ss,chunk,'\n'))
        {
            int depthFromDir = 0;

            for(auto ch:chunk)
            {
                if(ch=='\t') depthFromDir++;
            }
            if(depthFromDir==0)//zero depth hai means directories hai
            mpp[depthFromDir] = chunk.size();

            else
            {
                //depthFromDir != means child hua directories == subdirectories
                //iska depth kaise cal hoga
                //depth iska = iska-1 + iska
                mpp[depthFromDir] =
    mpp[depthFromDir-1] + 1 + (chunk.size() - depthFromDir);
            }

            if(chunk.find('.') != string :: npos)
                 res = max(res, mpp[depthFromDir]);
        }
        return res;
        
    }
};