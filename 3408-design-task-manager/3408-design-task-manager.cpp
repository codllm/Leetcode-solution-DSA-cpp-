class TaskManager {
public:

    unordered_map<int,int> task_priority;
    unordered_map<int,int> task_user;

    set<pair<int,int>> priority_task;


    TaskManager(vector<vector<int>>& tasks) {

        for(int i=0;i<tasks.size();i++)
        {
            int userID = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2];


            task_priority[taskId] = priority;

            task_user[taskId] = userID;


            priority_task.insert({priority,taskId});
        }  
    }
    

    void add(int userId, int taskId, int priority) {

        task_priority[taskId] = priority;

        task_user[taskId] = userId;


        priority_task.insert({priority,taskId}); 
    }
    

    void edit(int taskId, int newPriority) {


        int old_priority = task_priority[taskId];


        priority_task.erase({old_priority,taskId});


        task_priority[taskId] = newPriority;


        priority_task.insert({newPriority,taskId});
    }
    

    void rmv(int taskId) {


        int priority = task_priority[taskId];


        priority_task.erase({priority,taskId});


        task_priority.erase(taskId);

        task_user.erase(taskId);
    }
    

    int execTop() {


        if(priority_task.empty())
            return -1;


        auto it = priority_task.rbegin();


        int priority = it->first;

        int taskId = it->second;


        int userId = task_user[taskId];


        priority_task.erase({priority,taskId});


        task_priority.erase(taskId);

        task_user.erase(taskId);


        return userId;
    }
};