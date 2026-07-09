class FoodRatings {
public:

    class Compare {
    public:
        bool operator()(pair<int,string>& a, pair<int,string>& b)
        {
            // same rating -> lexicographically smaller food first
            if(a.first == b.first)
            {
                return a.second > b.second;
            }

            // higher rating first
            return a.first < b.first;
        }
    };


    unordered_map<string,int> FoodRating;

    unordered_map<string,string> FoodCuisine;

    unordered_map<string,
        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            Compare
        >
    > cuisinesRating;



    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0;i<foods.size();i++)
        {
            FoodRating[foods[i]] = ratings[i];

            FoodCuisine[foods[i]] = cuisines[i];

            cuisinesRating[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    

    void changeRating(string food, int newRating) {
        
        FoodRating[food] = newRating;

        string cuisine = FoodCuisine[food];

        cuisinesRating[cuisine].push({newRating, food});
    }
    

    string highestRated(string cuisine) {
        
        while(true)
        {
            auto topFood = cuisinesRating[cuisine].top();

            int rating = topFood.first;
            string food = topFood.second;


            // current rating == heap rating
            // means this is latest data
            if(FoodRating[food] == rating)
            {
                return food;
            }


            // outdated old rating
            cuisinesRating[cuisine].pop();
        }
    }
};