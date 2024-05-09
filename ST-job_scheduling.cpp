#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct job{
    string id;
    int profit;
    int deadline;
    job(string id_,int profit_,int deadline_){
        id = id_;
        profit = profit_;
        deadline = deadline_;
    }
};

bool cmp(job &a,job &b){
    return a.profit>b.profit;
}

vector<string> jobSeq(vector<job> &jobs){
    sort(jobs.begin(),jobs.end(),cmp);
    int maxidead = 0;
    for(auto it : jobs){
        maxidead = max(maxidead,it.deadline);
    }

    vector<bool> slots(maxidead,false);

    vector<string> schedule;

    for(auto it : jobs){
        for(int i = it.deadline-1;i>=0;i--){
            if(slots[i] == false){
                slots[i] = true;
                schedule.push_back(it.id);
                break;
            }
        }
    }

    return schedule;
}
int main(){
    vector<job> jobs;
    cout<<"Enter no. of jobs"<<endl;
    int n;
    cin>>n;

    for(int i = 0;i<n;i++){
        string id;
        int profit,deadline;
        cout<<"enter id"<<endl;
        cin>>id;
        cout<<"enter profit"<<endl;
        cin>>profit;
        cout<<"enter deadline"<<endl;
        cin>>deadline;
        job a(id,profit,deadline);
        jobs.push_back(a);
    }

    vector<string> op = jobSeq(jobs);

    cout<<"Scheduled jobs are :"<<endl;

    for(auto it : op){
        cout<<it<<" ";
    }
    cout<<endl;

}