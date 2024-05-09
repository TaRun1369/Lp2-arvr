#include<bits/stdc++.h>
using namespace std;

int g = 0;
void print(vector<int> &start){
    for(int i = 0;i<9;i++){
        if(i%3 ==0)cout<<endl;
        if(start[i]==-1)cout<<"_ ";
        else cout<<start[i]<<" ";
    }
    cout<<" ======================================"<<endl;
}
// void copy(vector<int> &jo, vector<int> &jisko){
//     for(int i = 0;i<9;i++){
//         jisko[i]
//     }
// }

 void moveleft(vector<int> &st,int empty){
    swap(st[empty],st[empty-1]);    
 }
  void moveright(vector<int> &st,int empty){
        swap(st[empty],st[empty+1]);    
 }  
  void moveup(vector<int> &st,int empty){
            swap(st[empty],st[empty-3]);
 }
  void movedown(vector<int> &st,int empty){
            swap(st[empty],st[empty+3]);    
 }

int heuristic (vector<int> &st,vector<int> &en){
    int ans = 0;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(st[i] == en[j] && st[j] != -1){
                ans+=abs((j-i)/3) + abs((j-i)%3);
            }
        }
    }
    cout<<"curr - "<<ans<<g<<endl;
    return ans+ g;
}

void movetile(vector<int> &st,vector<int> en){
    int empty = 0;
    for(int i = 0;i<9;i++){
        if(st[i] == -1){
            empty= i;
            break;
        }
    }

    int row = empty/3;
    int col = empty%3;

    // vector<int> m1,m2,m3,m4;
        vector<int> m1 = st, m2 = st, m3 = st, m4 = st;    // Creates copies of current state
        
    int f1 = INT_MAX,f2 = INT_MAX,f3 = INT_MAX,f4 = INT_MAX;
    // for(auto it : m1) cout<<it<<endl;
    
    if(row - 1>= 0 ){
        moveup(m1,empty);
        f1 = heuristic(m1,en);
    }
    if(row + 1 < 3){
        movedown(m2,empty);
        f2 = heuristic(m2,en);
    }
    if(col - 1 >= 0){
        moveleft(m3,empty);
        f3 = heuristic(m3,en);
    }
    if(col + 1 < 3){
        moveright(m4,empty);
        f4 = heuristic(m4,en);
    }
    cout<<"fs"<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<endl;
    if(f1 <= f2 && f1<=f3 && f1<= f4){
        moveup(st,empty);

    }
    else if(f2 <= f1 && f2<=f3 && f2<= f4){
        movedown(st,empty);
    }
    else if(f3<= f2 && f3<=f1 && f3<= f4){
        moveleft(st,empty);
    }
    else{
        moveright(st,empty);
    }
}

void solve8(vector<int> &start,vector<int> &end){
    g++;

    movetile(start,end);
    print(start);
    int h = heuristic(start,end);
    cout<<"curr - h and g = "<<h<<g<<endl;
    if(h == g){
        cout<<"solved in "<<h<<endl;
        return;
    }

    solve8(start,end);
}
bool solvable(vector<int> &st){
    int inversion = 0;

    for(int i = 0;i<9;i++){
        if(st[i] <= 1) continue;
        for(int j = i+1;j < 9;j++){
            if(st[j] == -1 ) continue;
            if( st[i] > st[j]) inversion++;
        }
    }
    // cout<<"Inversions"<<inversion<<endl;
    return inversion%2==0;
}
int main(){
    vector<int> start(9),end(9);
    cout<<"ENter start matrix"<<endl;
    for(int i = 0;i<9;i++){
        cin>>start[i];
    }

    cout<<"Enter end matrix"<<endl;
    for(int i = 0;i<9;i++){
        cin>>end[i];
    }
    print(start);
    if(solvable(start)) solve8(start,end);
    else cout<<"sorry  not solvable"<<endl;
}