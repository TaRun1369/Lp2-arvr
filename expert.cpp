#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> questions = {
    "do you feel any stress?",
    "Are u feeling distress while concentrating?",
    "Are you having any trouble in sleeping?",
    "Are you having any trouble in concentration?",
    "Are you having any trouble in eating?",
    "Are you having any trouble in digestion?",
    "Are you having any trouble in urination?",
    "Are you having any trouble in sexual function?",
    "Are you having any trouble in headache?",
    "Are you having any trouble in vision?",
    "Are you having any trouble in hearing?"
};

void expert(map<string,int>& mp){
    int ans = 0;
    for(auto it : questions){
        cout<<it<<endl;
        char ip;
        cin>>ip;
        cout<<"enter y or n"<<endl;
        while(ip != 'y' && ip != 'n'){
            cout<<"reenter"<<endl;
            cin>>ip;
        }
        if(ip == 'y') ans++;
    }

    if(ans > mp["severe"]){
        cout<<"marr jaa"<<endl;
    }
    else if(ans > mp["moderate"]){
        cout<<"bach sakte ho aap"<<endl;
    }
    else{
        cout<<"thik ho aap ghar jao"<<endl;
    }
}

int main(){
    cout<<"I am an expert system"<<endl;
    map<string ,int> mp = {
        {"mild", 3},
        {"moderate", 6},
        {"severe", 9}
    };
    expert(mp);
    return 0;
}
