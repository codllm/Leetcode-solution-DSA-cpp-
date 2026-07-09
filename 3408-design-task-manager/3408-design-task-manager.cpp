class TaskManager {
public:

    unordered_map<int,int> task_priority;
    unordered_map<int,int> task_User;

    set<pair<int,int>> st; // {priority, taskId}


    TaskManager(vector<vector<int>>& tasks) {

        for(int i=0;i<tasks.size();i++)
        {
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];


            task_priority[taskId] = priority;

            task_User[taskId] = userId;


            st.insert({priority, taskId});
        }
    }
    

    void add(int userId, int taskId, int priority) {

        task_priority[taskId] = priority;

        task_User[taskId] = userId;


        st.insert({priority, taskId});
    }
    

    void edit(int taskId, int newPriority) {


        // get old priority
        int oldPriority = task_priority[taskId];


        // remove old data from set
        st.erase({oldPriority, taskId});


        // update map
        task_priority[taskId] = newPriority;


        // insert new ranking
        st.insert({newPriority, taskId});
    }
    

    void rmv(int taskId) {


        int priority = task_priority[taskId];


        st.erase({priority, taskId});


        task_priority.erase(taskId);

        task_User.erase(taskId);
    }
    

    int execTop() {


        if(st.empty())
            return -1;


        // highest priority
        auto it = st.rbegin();


        int priority = it->first;

        int taskId = it->second;


        int userId = task_User[taskId];


        // remove executed task
        st.erase({priority, taskId});


        task_priority.erase(taskId);

        task_User.erase(taskId);


        return userId;
    }
};