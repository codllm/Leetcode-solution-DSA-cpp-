class AuthenticationManager {
public:
    int liveTime = 0;
    unordered_map<string,int> auth;
    // {tokenId, expiryTime}

    AuthenticationManager(int timeToLive) {
        liveTime = timeToLive; 
    }
    
    void generate(string tokenId, int currentTime) {

        int expiryTime = liveTime + currentTime;

        auth[tokenId] = expiryTime;
    }
    
    void renew(string tokenId, int currentTime) {

        if(auth.find(tokenId) == auth.end())
        {
            return;
        }

        int expiryTime = auth[tokenId];

        if(expiryTime > currentTime)
        {
            int newexpiryTime = currentTime + liveTime;
            auth[tokenId] = newexpiryTime;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {

        int count = 0;

        for(auto a : auth)
        {
            int expiryTime = a.second;

            if(expiryTime > currentTime)
                count++;
        }

        return count;
    }
};