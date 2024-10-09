#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set> 
using namespace std;

// 이동 명령어 
vector<int> dy = { -1,0,1,0 };
vector<int> dx = { 0,1,0,-1 };
int L,N;

bool check_index(int i, int j, const vector<vector<int>>& chess) {
    if (chess[i][j] == 2) { return false; }
    if (i <= 0 or i > L) { return false; }
    if (j <= 0 or j > L) { return false; }
    return true;
}

int push(vector<vector<int>>& chess, vector<vector<pair<int, int>>>& worriers, int i, int d, vector<vector<int>>& worrier) {
    int ans=0;
    set<int> s;
    // Worrier 맵에서 기사 찾기(없으면 return)(있으면 위치 반환)
    if (worriers[i][0].first == 0) { return 0; }
    // 모든 rc pair를 q에 넣기
    queue<pair<int, int>> q;
    vector<pair<int, int>>::iterator it = worriers[i].begin(); 
    s.insert(it->second); it++;
    for (it; it != worriers[i].end(); it++) {
        q.push({*it });
    }
    
    // 밀 수 있는지 확인하기 
     // 모든 rc에 대해서, 밀려고 하는 방향에 존재하는 새로운 rc(하나의 병사는 함께 넣어야 함) 를 계속해서 q에 넣음 (벽이 2이거나 index를 벗어나면, FAIL)
     // 밀려고 하는 방향에 대해서 (벽이나 INDEX 벗어나지 않고)(worrier 없고) 그냥 팝
     // 밀려고 하는 방향에 대해서 (벽이나 INDEX 벗어나지 않고)(worrier 있으면) WORRIER 넣고 팝
     // 밀려고 하는 방향에 대해서 벽이나 INDEX 벗어나면, 밀 수 없음. return 0; 
    int y, x;
    while (q.empty() == false) {
        y = q.front().first + dy[d]; // 밀려고 하는 방향에 대해서
        x = q.front().second + dx[d];
        if (check_index(y, x, chess) == false) { return 0; } // 벽이나 index 벗어나면 바로 fail
        // s안에 worrier[y][x]가 없어야함.
        
        if (worrier[y][x] != 0 && s.find(worrier[y][x]) == s.end()) { // WORRIER 있으면 Push
            int w = worrier[y][x];
            for (it = worriers[w].begin(); it != worriers[w].end(); it++) {
                if (it == worriers[w].begin()) { s.insert(it->second);}
                else { q.push({ *it }); }
            }
            q.pop();
        }
        else { // worrier 없거나 그 worrier가 나 이면, 
            q.pop();
        }

    }
    // cout << "it can!" << endl;
    // 밀고 전사들의 체력 UPDATE하기(worrier 랑 worriers 둘 다) 동시에 ANSWER RETURN 해야함
    // set에서 꺼내서 worriers update 
    int w;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        w = *iter;
        for (it = worriers[w].begin() + 1; it != worriers[w].end(); it++) {
            it->first += dy[d];
            it->second += dx[d];
        }
    }
    //worriers로 worrier update 하기
    //worrier 0으로 초기화하기 
    for (int q = 1; q < L + 1; q++) {
        for (int z = 1; z < L + 1; z++) {
            worrier[q][z] = 0;
        }
    }
    // update하기
    for (int p = 1; p <= N; p++) {
        for (it = worriers[w].begin() + 1; it != worriers[w].end(); it++) {
            y = it->first;
            x = it->second;
            worrier[y][x] = p;
            if (chess[y][x] == 1 && p!=i) {
                worriers[p][0].first--;//체력깎기
                ans++;//answer count
            }
        }
    }
    return ans;
}



int main() {
    int answer=0;
    // LNQ 입력받기
    int Q; cin >> L >> N >> Q;

    // chess판 완성하기
    vector<vector<int>> chess (L+1,vector<int>(L+1) );
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> chess[i][j];}}

    // worrier
    vector<vector<int>> worrier (L+1, vector<int>(L+1, 0));
    //int r, c, h, w, k;
    //for (int i = 1; i <= N; i++) {
    //    cin >> r >> c >> h >> w >> k;
    //    for (int j=0; j < h; j++) {
    //        for (int l=0; l < w; l++) {
    //            worrier[r + j][c + l] = { i,k };
    //        }
    //    }
    //}
    // vector<pair<int, int>> worriers(N + 1);
    vector<vector<pair<int, int>>> worriers(N + 1);
    int r, c, h, w, k;
    for (int i = 1; i <= N; i++) {
        cin >> r >> c >> h >> w >> k;
        worriers[i].push_back({ k,i });
        for (int j = 0; j < h; j++) {
            for (int l = 0; l < w; l++) {
                worriers[i].push_back({ r + j,c + l });
                worrier[r + j][c + l] = i;
            }
        }
    }
    vector<vector<pair<int, int>>> worriers_copy(worriers);

    // 왕의 명령 
    //for (int l = 0; l < Q; l++) {
    //    int i, d;
    //    cin >> i >> d;
    //    answer += push(chess, worriers, i, d, worrier);
    //    cout << l << " " << answer << endl;
    //}
    int q, a, e, t, b, x;
    cin >> q >> a >> e >> t >> b >> x;
    answer += push(chess, worriers, q, a, worrier);
    answer += push(chess, worriers, e, t, worrier);
    answer += push(chess, worriers, b, x, worrier);

    int real_answer = 0;
    // worrier의 체력이 0이 아니면, 첫 체력과 비교 
    for (int i = 1; i <= N; i++) {
        if (worriers[i][0].first == 0) { continue; }
        real_answer += (worriers_copy[i][0].first) - (worriers[i][0].first);
    }


    //for (int i = 1; i <= L; i++) {
    //    for (int j = 1; j <= L; j++) {
    //        cout << worrier[i][j].second;
    //        //printf("%d",worrier[i][j].first);
    //    }
    //    cout << endl;
    //}
    cout << real_answer;


    return 0;
}