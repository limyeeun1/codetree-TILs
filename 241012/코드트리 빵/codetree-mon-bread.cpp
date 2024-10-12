#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, m;
int current_time;

vector<vector<int> > map;
//vector<vector<int> > store_map;
//vector<vector<int> > visited_map;

vector<pair<int, int>> people;
vector<pair<int, int> > c_store;
vector<int> mission_clear;

const vector<int> dy = { -1,0,0,1 };
const vector<int> dx = { 0,-1,1,0 };

bool check_index(int y, int x){
    if (y <= 0 || y > N) { return false; }
    if (x <= 0 || x > N) { return false; }
    return true;
}

//int cal_distance(int y1, int x1, int y2, int x2) { // from x1,y1, to x2,y2 // 막힌 벽 map 에서 2를 맡고 있음
//    //맨해튼 distance로 갈 수 있는지 확인, return
//    return abs(y1 - y2) + abs(x1 - x2);
//    //맨해튼 distance로 갈 수 없는 경우에 대한 처리 
//} 

//void initialize_visitmap() {
//    for (int i = 0; i < N + 1; i++) {
//        for (int j = 0; j < N + 1; j++) {
//            visited_map[i][j] = 0;
//        }
//    }
//}

int cal_distance(int y1, int x1, int y2, int x2) { // from x1,y1, to x2,y2 // 막힌 벽 map 에서 2를 맡고 있음
    queue<pair<int,int>> q;
    queue<int> d;
    vector<vector<int>> visited_map(N+1, vector<int> (N+1));
    //visited_map.resize(N + 1, vector<int>(N + 1));
    // initialize_visitmap();
    q.push({ y1,x1 });
    d.push({ 0 });
    while (q.empty() == false) {
        int y = q.front().first, x = q.front().second; // 꺼내기
        int value= d.front();
        if (y == y2 && x == x2) { return value; } // 종료조건
        q.pop(); d.pop();

        visited_map[y][x] = 1;
        
        // 주변 노드 넣기, 값도 같이 넣기 
        for (int k = 0; k < 4; k++) {
            int i = y + dy[k], j = x + dx[k];
            if (check_index(i, j) == false) { continue; }// index 
            if (visited_map[i][j] == 1) { continue; }
            if (map[i][j] == 2) { continue; }// 벽인지 아닌지
            q.push({ i,j });
            d.push(value+1);
        }
    }


}

int where_to_go(int p) { // 현재 위치로부터 편의점 방향으로 가는 것임.
    // people[p-1] // 현재 위치 
    // c_store[p-1] // 편의점 정보  
    int index = -1;
    int distance = 2*N;
    for (int i = 0; i < 4; i++) {
        int y = people[p - 1].first + dy[i]; 
        int x = people[p - 1].second + dx[i];
        if (check_index(y, x) == false) { continue; } // index 검사
        // 거리 계산하기 // 막힌 벽 통과 불가능
        int dis = cal_distance(y, x, c_store[p - 1].first, c_store[p - 1].second);
        if (dis < distance) { distance = dis; index = i; }
    }
    return index;

}

void one() {
    // 격자에 있는 사람 중, 편의점 최단 경로로 이동 (이동 가능한 칸으로만 이동하여 도달하는 칸 수 (막혀있으면 안됨))
    for (int p = 1; p <= m; p++) {
        if (p >= current_time) { break; } // 격자에 들어오기 시작한 사람을 시간으로 계산
        if (mission_clear[p - 1] == 1) { continue; }// 이미 편의점에 도달했다면 넘어가기 
        int index = where_to_go(p);// 어디로 움직일지 탐색 (막혀있으면 안됨 주의)
        people[p - 1].first += dy[index]; // 실제로 이동
        people[p - 1].second += dx[index];
    }

}

void two() {
    // 편의점에 도달한 사람들에 대한 처리 : map은 벽으로 만들고, 사람은 이동 완료로 만들기 
    for (int p = 1; p <= m; p++) {
        if (p >= current_time) { break; } // 격자에 들어오기 시작한 사람을 시간으로 계산
        if (mission_clear[p - 1] == 1) { continue; }// 이미 편의점에 도달했다면 넘어가기
        if (people[p - 1].first == c_store[p - 1].first && people[p - 1].second == c_store[p - 1].second) {
            mission_clear[p - 1] = 1;
            map[people[p - 1].first][people[p - 1].second] = 2;
        }
    }

}



//pair<int, int> which_basecamp(int p) {
//    //편의점 위치 
//    int y = c_store[p - 1].first, x = c_store[p - 1].second;
//
//    // 8개를 순서대로 탐색하면 됨 //
//        // 벽이 있으면 탈락..인데 영구탈락? .. oo..
//    // 아니면 모든 베이스 캠프에 대해서 탐색하는 방법도 있음 //이게 빠르긴 할 듯
//    // 벽으로 막힌거 고려 안함
//    int yy=0, xx=0;
//    int distance = 2 * N;
//    for (int i = 1; i <= N; i++) {
//        for (int j = 1; j <= N; j++) {
//            if (map[i][j] != 1) { continue; }
//            if (map[i][j] == 2) { continue; }
//            int dis = abs(y - i) + abs(x - j);
//            if (dis < distance) { distance = dis; yy = i; xx = j; }
//        }
//    }
//    if (yy == 0) { cout << "error"; }
//    return { yy,xx };
//}

pair<int, int> which_basecamp(int p) {
    //편의점 위치 
    int y = c_store[p - 1].first, x = c_store[p - 1].second;

    // 8개를 순서대로 탐색하면 됨 //
        // 벽이 있으면 탈락..인데 영구탈락? .. oo..
    // 아니면 모든 베이스 캠프에 대해서 탐색하는 방법도 있음 //이게 빠르긴 할 듯
    // 벽으로 막힌거 고려 안함
    int yy = 0, xx = 0;
    int distance = 2 * N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 1) { continue; }
            if (map[i][j] == 2) { continue; }
            int dis = cal_distance(y, x, i, j);
            if (dis < distance) { distance = dis; yy = i; xx = j; }
        }
    }
    if (yy == 0) { cout << "error"; }
    return { yy,xx };
}


void three(){
    // curretn time에 해당하는 사람 출발
    if (current_time > m) { return; }
    //current_time 에 해당 하는 사람이 움직이는 거임
    int tp = current_time;
    
    // basecamp 탐색 (편의점 위치로부터 탐색, )
    pair<int,int> loc = which_basecamp(tp);
    // basecamp로 이동
    people[tp - 1].first = loc.first;
    people[tp - 1].second = loc.second;
    // basecamp 벽 처리
    map[loc.first][loc.second] = 2;
}

bool check_mission_clear() {
    for (int i = 0; i < mission_clear.size(); i++) {
        if (mission_clear[i] == 0) { return false; }
    }
    return true;
}

void init() {
    // map 정보
    for (int i = 0; i < N + 1; i++) {
        vector<int> t(N + 1);
        if (i == 0) { map.push_back(t); continue; }
        for (int j = 0; j < N + 1; j++) {
            if (j == 0) { continue; }
            cin >> t[j];

        }
        map.push_back(t);
    }

    //편의점 정보
    /*for (int i = 0; i < N + 1; i++) {
        vector<int> t(N + 1);
        for (int j = 0; j < N + 1; j++) {
            t[j] = 0;}
        store_map.push_back(t);}*/

    int y, x;
    for (int i = 0; i < m; i++) {
        cin >> y >> x;
        c_store[i] = { y,x };
    }
}


int main() {
    cin >> N >> m;
    
    people.resize(m);
    mission_clear.resize(m);
    c_store.resize(m);
    //visited_map.resize(N + 1, vector<int>(N + 1));

    init(); // 격자정보, 편의점 정보 획득


    for (current_time = 1; 1>0 ; current_time++) { // 사실상 무한 루프 임.

        one();

        two();

        three();

        if (check_mission_clear() == true) { cout << current_time; break; }

    }
    return 0;
}