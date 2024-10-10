#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int qi, qj;
int N;
// 상하좌우 순서임
vector<int> dy = { -1,1,0,0 };
vector<int> dx = { 0,0,-1,1 };

vector<int> sy = { -1,-1,1,1 };
vector<int> sx = { -1,1,-1,1 };

void get_input(vector<vector<int>>& map, int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];}}
    return;
}

void get_people(vector<pair<int, int>>& people, vector<vector<int>> &map, int M) {
    int r, c;
    for (int i = 1; i <= M; i++) {
        cin >> r >> c;
        people.push_back({ r,c });
        map[r][c] = 10;
    }
    return;
}

bool check_index(int y, int x) {
    if (y <= 0 or y > N) { return false; }
    if (x <= 0 or x > N) { return false; }
    return true;
}

int cal_distance(int y, int x) {
    int dis = abs(qi - y) + abs(qj - x);
    return dis;
}

int move(vector<vector<int>>& map, vector<pair<int, int>>& people) {
    int x,y,c=0,t;
    // 모든 사람에 대해서 반복
    for (int i = 0; i < people.size(); i++) {
        // 상 하 좌 우, 에 대해서 //벽이 없는지(0이나 10이나 100) 거리 측정, //가장 큰 값에 대해서 이동하던지 이동 못하던지!  
        int distance = -1, direction=-1;
        int original_distance = cal_distance(people[i].first, people[i].second);
        for (int j = 0; j < 4; j++) {
            y = people[i].first + dy[j];
            x = people[i].second + dx[j];
            if (check_index(y, x) == false) { continue; }// index 범위 내인지 확인 
            t = map[y][x];
            if (t == 0 or t % 10 == 0) { // 벽 없는지 확인
                // 출구와의 거리 측정 // max 값 비교하기 distance비교해서 direction 저장 
                if (cal_distance(y, x) > distance) {
                    distance = cal_distance(y, x);
                    direction = j;
                }
            }
        }
        // 현재 거리보다 가까워져야지만 이동할 수 있는 것임
        if (distance != -1 && distance < original_distance) { // 이동 완료
            c++;
            map[people[i].first][people[i].second] -= 10; // map 정보 update
            people[i].first += dy[direction]; // 사람 정보
            people[i].second += dx[direction];
            map[people[i].first][people[i].second] += 10;
        }
        // 이동 못하면 아무것도 안하면 됨.
    
    }
    
    return c;
}

bool remove(vector<vector<int>>& map, vector<pair<int, int>>& people) {
    // 출구에 있는 사람들에 한해서
    for (int i = 0; i < people.size(); i++) {
        if (qi== people[i].first && qj==people[i].second) {
            map[people[i].first][people[i].second] -= 10; //map에서 사람수만큼 빼고, 
            people.erase(people.begin() + i);//people 에서 삭제
            i--;

        }
    }
   //people에서 삭제하고
    
    // people이 비었는지 확인 
    if (people.empty() == true) { return true; }
    return false;
}

//bool is_person(const vector<vector<int>>& map, int y, int x) {
//    int big_i = max(y, qi), big_j = max(x, qj), small_i = min(y, qi), small_j = min(x, qj);
//    for (int i = small_i; i <= big_i; i++) {
//        for (int j = small_j; j <= big_j; j++) {
//            if (map[i][j] != 0 && map[i][j]!=200 && map[i][j] % 10 == 0) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

bool is_person(const vector<vector<int>>& map, int i,int j, int n) {
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (map[i+a][j+b] != 0 && map[i+a][j+b] != 200 && map[i+a][j+b] % 10 == 0) {
                return true;
            }
        }
    }
    return false;
}

pair<int,int> find_square(const vector<vector<int>>& map, int & n) {
// 정사각형의 한 변의 길이가 2부터 N일때.
    for (n; n < N; n++) {
        int small = qi - n + 1; int big = qj - n + 1;
        for (int i = small; i <= big; i++) {
            for (int j = small; j <= big; j++) {
                // index확인
                if (check_index(i, j) == false) { continue; }
                // 여기서부터 정사각형을 만들어야함 !! 
                if (is_person(map, i, j, n) == true) { return { i,j }; }
            }
        }
    }
    return { 0,0 };
}

void rotate(vector<vector<int>>& map, vector<pair<int, int>>& people) {
    // 정사각형 찾기 
    // index 검사하기 
    // 0이 아니면서 10으로 나누어 떨어지는지 확인
    int x, y;
    int find = 0;
    int n = 2;
    pair<int,int> pp = find_square(map, n);
    y = pp.first;
    x = pp.second;
    //for (int i = 1; i <= N / 2 + 1; i++) {
    //    for (int j = 0; j < 4; j++) {
    //        y = qi + i * sy[j];
    //        x = qj + i * sx[j];
    //        if (check_index(y, x) == false) { continue; }

    //        if (is_person(map, y, x)) { find = 1; break; }
    //    }
    //    if (find == 1) { break; }
    //}
    //cout << y << x << endl;

    // 회전시키기, (y,x) (qi,qj)
    // 시작 index와 끝 index 정하기 

    // 원래 matrix 복사하기, 회전 및 값 줄이기 // people vector 수정해야함. 
    vector<vector<int>> original_map(map);
    for (int i = y; i < y+n; i++) {
        for (int j = x; j <= x+n; j++) {
            map[i][j] = original_map[n + 1 - j][i];
            if (map[i][j] != 0 && map[i][j] % 10 != 0) { // 벽 허물기
                map[i][j]--;
            }
            else if (map[i][j] != 0 && map[i][j] != 200 && map[i][j] % 10 == 0) {// 사람이라면, index 바꾸기
                //person 중에서 i,j 찾아서 바꿔야대
                for (int k = 0; k < people.size(); k++) {
                    if (people[k].first == i && people[k].second == j) {
                        people[k].first = j; people[k].second = n + 1 - j;
                    }
                }
            }
        }
    }
    return;
}


int main() {
    int M, K; cin >> N >> M >> K;
    vector<vector<int>> map(N + 1, vector<int>(N + 1));
    get_input(map, N);
    
    // 사람 정보
    vector<pair<int, int>> people;
    get_people(people ,map , M);
    
    // 출구 정보

    cin >> qi >> qj;
    map[qi][qj] = 200;

    int count = 0;
    
    for (int i = 0; i < K; i++) {
    
        // 주변을 파악해서 움직일 수 있는 사람은 움직이기
        count += move(map, people);

        // 출구에 도달한 사람 빼기    // 만약 사람이 다 탈출했다면, Break!
        if (remove(map, people)) { break; }


        // 정사각형 만들기 : 기준을 어떻게 잡아야할지.. 기존에 저장해둔 거리 말고, 출구 중심으로 새로 탐색을 하는게 좋을 것 같
        rotate(map, people);

        
        // 이동거리 합, 출구 정보 
    
    
    }
    cout << count << endl;
    cout << qi << " " << qj;
    return 0;
}