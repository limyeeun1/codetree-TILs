#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> civil(6);
queue<int> WALL;

void rotate(vector<vector<int>>&c, int a, int b){
    queue<int> q;
    q.push(c[a-1][b]);q.push(c[a][b+1]);q.push(c[a+1][b]);q.push(c[a][b-1]);
    c[a][b+1] = q.front();q.pop(); c[a+1][b] = q.front();q.pop() ; c[a][b-1]=q.front();q.pop(); c[a-1][b]= q.front();q.pop();
    if (q.empty()==false){cout<< "error" << endl;}
    q.push(c[a-1][b-1]);q.push(c[a-1][b+1]);q.push(c[a+1][b+1]);q.push(c[a+1][b-1]);
    c[a-1][b+1] = q.front();q.pop(); c[a+1][b+1] =q.front(); q.pop() ; c[a+1][b-1]=q.front();q.pop(); c[a-1][b-1]= q.front();q.pop();
    if (q.empty()==false){cout<< "error" << endl;}
}

int bfs(vector<vector<int>>&c,vector<vector<int>>& v, int i, int j, bool e ){
    queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    int count=1;
    // 담기
    q.push({i,j});
    v[i][j]=1;

    // 빼면서 넣기 및 v update
    while(q.empty()==false){
        //v update
        i = q.front().first;
        j = q.front().second;
        q2.push(q.front());
        q.pop();
        // 주변것 넣기 i-1,j, i,j-1 i,j+1 i+1,j
        if (i-1>=1 && v[i-1][j]==0 && c[i][j]==c[i-1][j]){v[i-1][j]=1;count++;q.push({i-1,j});}
        if (j-1>=1 && v[i][j-1]==0 && c[i][j]==c[i][j-1]){v[i][j-1]=1;count++;q.push({i,j-1});}
        if (j+1<=5 && v[i][j+1]==0 && c[i][j]==c[i][j+1]){v[i][j+1]=1;count++;q.push({i,j+1});}
        if (i+1<=5 && v[i+1][j]==0 && c[i][j]==c[i+1][j]){v[i+1][j]=1;count++;q.push({i+1,j});}
    }
    if (count < 3 ){return 0;}
    if (e==true){
        while(q2.empty()==false){
            i = q2.front().first;
            j = q2.front().second;
            c[i][j]=0;
            q2.pop();
        }
    }

    return count;
}

int find(vector<vector<int>>&c, bool erase){
    vector<vector<int>> visited(6,vector<int> (6,0));
    int t=0;
    int ans=0;
    for (int i=1; i<=5; i++){
        for (int j=1; j<=5;j++){
            if (visited[i][j]==0){
                t=bfs(c,visited,i,j,erase); 
                ans += t;
            }
        }
    }
    return ans;
}

int rotate_find(vector<vector<int>>& c,int what,int how, bool erase){
    int answer=0;
    int a = what/3+2, b=what%3+2;
    // 실제로 돌리고
    if (what!=9){
        if(how==1){
            rotate(c,a,b);
            answer = find(c,erase);
        }
        else if(how==2){
            rotate(c,a,b);
            rotate(c,a,b);
            answer = find(c,erase);}
        else if (how==3){
            rotate(c,a,b);
            rotate(c,a,b);
            rotate(c,a,b);
            answer = find(c,erase);}}
    else {
        answer = find(c,erase);
    }
    
    return answer;
}

pair<int,int> rotate_simul(vector<vector<int>> civil,bool erase){
    pair<int,int> a;//무엇을 몇도
    vector<vector<int>> temp_a(9,vector<int> (3));
    // 돌리고 유물 찾고
    for(int i=0; i<9; i++){
        temp_a[i][0] = rotate_find(civil,i,1,false);
        temp_a[i][1] = rotate_find(civil,i,2,false);
        temp_a[i][2] = rotate_find(civil,i,3,false);
        //temp_a[i].push_back(rotate_find(civil,i,1,false));
        //temp_a[i].push_back(rotate_find(civil,i,2,false));
        //temp_a[i].push_back(rotate_find(civil,i,3,false));
    }
    // 가장 큰 값 찾아서, 그때의 i값이랑 how 값 return하기
    int what=0, how=0, t=-1;
    for (int i=0; i<9; i++){
        for (int j=0; j< temp_a[i].size() ; j++){
            if(t < temp_a[i][j]){
                what = i;how=j+1;
                t = temp_a[i][j];}
            else if(t==temp_a[i][j]){
                // j(회전값)이 작은것
                if (how > j+1){what = i;how=j+1;}
                else if (how == j+1){
                    // 열이 작은 것(i%3)
                    if(what%3 > i%3){what = i;how=j+1;}
                    else if(what%3 == i%3){
                        if (what>i){what = i;how=j+1;} // 행이 작은 것 (i)
                    }
                }
            }
        }
    }

    return {what,how};
}

void fill_civil(){
    for (int j=1; j<=5; j++){
        for (int i=5 ;i>=1; i-- ){
        
            if(civil[i][j]==0){
                civil[i][j] = WALL.front();
                WALL.pop();
            }
        }
    }
}

int main() {
    // 고대 유물 입력받기
    int K,M; cin >> K >> M;
    int temp;
    for (int i=1; i<6; i++){
        for (int j=0; j<6; j++){
            if (j==0){civil[i].push_back(0);}
            else {
            cin >> temp;
            civil[i].push_back(temp);}}}
    for (int i=0; i<M; i++){cin>>temp;WALL.push(temp);}
    
    // 알고리즘 시작하기 
    for (int i=0; i<K; i++){
        int answer=0;
        bool find=false;
        // int t_answer=0;
        pair<int,int> what_to_r(9,3);
        // 회전 중심 설정 및 몇 도를 돌릴 것인지, 각 경우의 가치 판단
        // 9,3 배열을 만들어서 각 열에서의 최댓 값 저장
        what_to_r = rotate_simul(civil,1);

        // 실제 회전, 유물 수거, 정답에 더하기 (유물 없는 경우도 포함)
        int t_answer = rotate_find(civil, what_to_r.first, what_to_r.second, true);
        //cout << what_to_r.first<< what_to_r.second << " " << t_answer<< endl;
        if (t_answer == 0) break;
        answer += t_answer; // 수정된 부분
        // 유물 채우기, 유물 수거하기 반복
        while (t_answer!=0){
            fill_civil();

            // for (int i=1 ;i<=5; i++ ){
            //     for (int j=1; j<=5; j++){
            //         cout << civil[i][j];
            //     }
            //     cout << endl;
            // }

            t_answer = rotate_find(civil,9,0,true);
            answer += t_answer;
        }
        //fill_civil()
        // t_answer += rotate_find(civil,9,0,true);
        //answer += t_answer;
        cout << answer << " " << endl;
    }
    return 0;
}