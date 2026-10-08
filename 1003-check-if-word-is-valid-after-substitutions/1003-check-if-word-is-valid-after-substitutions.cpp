class Solution {
public:
    bool isValid(string s) {

        size_t pos = s.find("abc");

        while(pos <s.size())
        {
            s.erase(pos,3);
            pos = s.find("abc");
        }
        return s=="";
    }
};