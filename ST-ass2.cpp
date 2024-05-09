#include<iostream>
#include<cmath>
#include<limits.h>

using namespace std;

int g = 0;


void print(int state[]){
    for(int i = 0;i<9;i++){
        if(i%3 == 0){
            cout<<endl;
        }
        if(state[i] == -1) cout<<"_ ";
        else cout<<state[i]<<" ";
    }
    cout<<endl;
}

void moveleft(int start[],int position){
    swap(start[position],start[position-1]);
}

void moveright(int start[],int position){
    swap(start[position],start[position+1]);
}

void moveup(int start[],int position){
    swap(start[position],start[position-3]);
}

void movedown(int start[],int position){
    swap(start[position],start[position+3]);
}

void copy(int temp[],int real[]){
    for(int i = 0;i<9;i++){
        temp[i] = real[i];
    }
}
int heuri(int start[],int end[]){
    int h = 0;
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(start[i] == end[j] && start[i] != -1){
                h += abs((j-i)/3) + abs((j-i)%3);
            }
        }
    }

    return h + g;
}
void movetile(int start[],int goal[]){
    int emptykaha = 0;
    for(int i = 0;i<9;i++){
        if(start[i] == -1){
            emptykaha = i;
            break;
        }
    }

    int row = emptykaha/3;
    int col = emptykaha%3;

    int s1[9],s2[9],s3[9],s4[9],f1 = INT_MAX,f2 = INT_MAX,f3 = INT_MAX,f4 = INT_MAX;

    copy(s1,start);
    copy(s2,start);
    copy(s3,start);
    copy(s4,start);

    if(col - 1 >= 0){
        moveleft(s1,emptykaha);
        f1 = heuri(s1,goal);
    }
    if(col +1  <3){
        moveright(s2,emptykaha);
        f2 = heuri(s2,goal);
    }
    if(row - 1 >= 0){
        moveup(s3,emptykaha);
        f3 = heuri(s3,goal);
    }
    if(row + 1 < 3){
        movedown(s4,emptykaha);
        f4 = heuri(s4,goal);
    }

    if(f1 <= f2 && f1 <= f3 && f1<= f4){
        moveleft(start,emptykaha);
    }
    else if(f2 <= f1 && f2 <= f3 && f2<= f4){
        moveright(start,emptykaha);
    }
    else if(f3 <= f1 && f3 <= f2 && f3<= f4){
        moveup(start,emptykaha);
    }
    else if(f4 <= f1 && f4 <= f2 && f4<= f3){
        movedown(start,emptykaha);
    }

}

void solve8(int start[],int end[]){
    g++;

    movetile(start,end);
    print(start);

    int f = heuri(start,end);

    if(f == g) {
        cout<<"solved in "<<f<<" moves"<<endl;
        return;
    }
    solve8(start,end);
}
bool solvable(int state[]){
    int inv  = 0;
    for(int i = 0;i<9;i++){
        if(state[i] <= 1) continue;

        for(int j = i+1;j<9;j++){
            if(state[j] <= 1) continue;
            if(state[j]<state[i]) inv++;
        }
    }

    return (inv%2 == 0);
}
int main(){
    int start[9];
    int end[9];

    cout<<"Enter start state(-1 for empty)"<<endl;

    for(int i = 0;i<9;i++){
        cin>>start[i];
    }

cout<<"Enter end state(-1 for empty)"<<endl;

    for(int i = 0;i<9;i++){
        cin>>end[i];
    }

    print(start);

    if(solvable(start)) solve8(start,end);
    else cout<<"Not solvable"<<endl;

    return 0;


}