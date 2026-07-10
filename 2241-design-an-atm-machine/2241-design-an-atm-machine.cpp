class ATM {
public:
    vector<long long> bank;
    vector<int> notes = {20,50,100,200,500};

    ATM() {
        bank.resize(5,0);
    }   
    void deposit(vector<int> banknotesCount) {
        
        for(int i=0;i<5;i++)
        {
            bank[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {

        vector<int> used(5,0);

        // start from biggest note
        for(int i=4;i>=0;i--)
        {
            int need = amount / notes[i];

            int take = min((long long)need, bank[i]);

            used[i] = take;

            amount = amount - (take * notes[i]);
        }
        // cannot make exact money
        if(amount != 0)
        {
            return {-1};
        }

        // now confirm withdrawal
        for(int i=0;i<5;i++)
        {
            bank[i] -= used[i];
        }
        return used;
    }
};