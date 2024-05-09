/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
struct job{
  string id;
  int profit;
  int deadline;
  job(string i,int p,int d){
      id = i;
      profit = p;
      deadline = d;
  }
  
};

bool cmp(job& a,job &b){
    return a.profit > b.profit;
}
bool cmp1(job&a,job&b){
    return a.deadline < b.deadline;
}

vector<job> jobSeq(vector<job>&jobs){
    
    sort(jobs.begin(),jobs.end(),cmp);
    
    int maxded = 0;
    for(auto it :jobs){
        maxded = max(maxded,it.deadline);
    }
    
    vector<bool> slots(maxded,false);
    
    vector<job> ans;
    
    for(auto it : jobs){
        for(int i = it.deadline - 1;i >= 0;i--){
            if(!slots[i] ){
                slots[i] = true;
                ans.push_back(it);
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<job> jobs;
    int n;
    cout<<"enter no. of jobs"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        string id;
        int p;
        int d;
        cout<<"enter id"<<endl;
        cin>>id;
        cout<<"enter profit"<<endl;
        cin>>p;
        cout<<"enter deadline"<<endl;
        cin>>d;
        job j(id,p,d);
        jobs.push_back(j);
    }
    vector<job> output = jobSeq(jobs);
    sort(output.begin(),output.end(),cmp1);
    for(auto it : output){
        cout<<it.id<<" ";
    }
    cout<<endl;
}
