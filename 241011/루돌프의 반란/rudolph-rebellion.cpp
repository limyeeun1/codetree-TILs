#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Ri, Rj; // 루돌프 좌표
int RC; // 루돌프의 힘
int D; // 산타의 힘
int N; // 격자 
int P; // 산타의 명수

vector<int> dy_r = { 1,1,1,0,0,-1,-1,-1 };
vector<int> dx_r = { 1,0,-1,1,-1,1,0,-1 };

vector<int> dy_s = { -1,0,1,0 };
vector<int> dx_s = { 0,1,0,-1 };

class Santa {
	public:
		int n;
		int r;
		int c; 
		int kijul;
		int score;
		Santa(int n, int r, int c, int kijul, int score) {
			this->n = n;
			this->r = r;
			this->c = c;
			this->kijul = kijul;
			this->score = score;
		}
};

vector<Santa> San;
vector<vector<int>> map(1, vector<int>(1,0));

void make_map() {
	// map 만들기 // 비어있으면 0, 산타는 1, 루돌푸는 2
	//0으로 초기화
	for (int i = 1; i < N + 1; i++) {
		vector<int> t;
		for (int j = 0; j < N + 1; j++) {
			t.push_back(0);
		}
		map.push_back(t);
	}
	// 산타는 1, 루돌푸는 2
	map[Ri][Rj] = 2;
	vector<Santa>::iterator it;
	for (it = San.begin(); it != San.end(); it++) {
		map[it->r][it->c] = 1;
	}
}

void make_santa() {
	// 산타 번호랑 위치 입력 받기 
	//San.resize(P);
	int n, r, c;
	for (int i = 0; i < P; i++) {
		cin >> n >> r >> c;
		San.push_back(Santa(n, r, c, 0, 0));
	}
}

bool check_index(int y, int x) {
	if (y <= 0 || y > N) { return false; }
	if (x <= 0 || x > N) { return false; }
	return true;
}

bool cal_distance(Santa s1, Santa s2) { // 자..class SANTA가 대상임!!
	// r,c가 음수인걸 걸러야함
	if (s1.r <= 0 && s2.r > 0) return false;
	if (s1.r > 0 && s2.r <= 0) return true;
	//둘 다 음수가 아니라면
	if (s1.r > 0 && s2.c > 0) {
		int d1 = (s1.r - Ri) * (s1.r - Ri) + (s1.c - Rj) * (s1.c - Rj), d2 = (s2.r - Ri) * (s2.r - Ri) + (s2.c - Rj) * (s2.c - Rj);
		if (d1 == d2) {
			if (s1.r == s2.r) { return s1.c > s2.c; }
			return s1.r > s2.r;
		}
		return d1 < d2;
	}
	return false;
}

int find_index(int r, int c) {
	int distance = 5000;
	int index = -1;
	for (int i = 0; i < 8; i++) {
		int dis = (Ri + dy_r[i] - r) * (Ri + dy_r[i] - r) + (Rj + dx_r[i] - c) * (Rj + dx_r[i] - c);
		if (dis < distance) { index = i; distance = dis; }
	}
	if (index == -1) { cout << "error" << endl; }
	return index;
	
}

int ru_find() {
	int index=-1;

	// 산타를 루돌프와 가까운 순서대로 sort 하기, 이때 거리가 같으면 r,c 큰 순서대로 sort
	sort(San.begin(), San.end(), cal_distance);
	// 그 중에서 맨 앞에 있는 산타쪽으로 이동
	index = find_index(San[0].r, San[0].c);
		// 모든 8방향 중에서 해당 위치랑 가장 가까운 index 구하기

	if (index == -1) {
		cout << " problem" << endl;	}
	return index;
}

int find_santa_with_rc(int r,int c) {
	vector<Santa>::iterator it;
	for (it = San.begin(); it!=San.end(); it++) {
		if (it->r == r && it->c == c) {
			return it->n;
		}
	}
}

vector<Santa>::iterator find_santa_with_n(int n) {
	vector<Santa>::iterator it;
	for (it = San.begin(); it != San.end(); it++) {
		if (it->n == n) {
			return it;
		}
	}
}

void push_santa(int n, int r, int c, int i) {
	if (check_index(r, c) == false) { // 죽음 처리
		vector<Santa>::iterator it;
		it = find_santa_with_n(n);
		it->r = -1;
		it->c = -1;

	}
	else {
	// 산타 있으면 중복 호출 
		if (map[r][c] == 1) {
			// 해당 자리에 있는 산타 번호 찾아서
			int n = find_santa_with_rc(r, c);
			push_santa(n, r + dy_r[i], c + dx_r[i], i);
		}
	// map update 및 santa vector 업데이트
		map[r][c] = 1;
		// santa n의 주소를 찾아서 UPDATE
		vector<Santa>::iterator it;
		it = find_santa_with_n(n);
		it->r = r;
		it->c = c;

	}
}

void push_santa_4(int n, int r, int c, int i) {
	if (check_index(r, c) == false) { // 죽음 처리
		vector<Santa>::iterator it;
		it = find_santa_with_n(n); // 이거 안해도 될듯 index 앎.
		it->r = -1;
		it->c = -1;

	}
	else {
		// 산타 있으면 중복 호출 
		if (map[r][c] == 1) {
			// 해당 자리에 있는 산타 번호 찾아서
			int n = find_santa_with_rc(r, c);
			push_santa(n, r + dy_s[i], c + dx_s[i], i);
		}
		// map update 및 santa vector 업데이트
		map[r][c] = 1;
		// santa n의 주소를 찾아서 UPDATE
		vector<Santa>::iterator it;
		it = find_santa_with_n(n);
		it->r = r;
		it->c = c;

	}
}

void ru_go() {
	// 돌진 위치 탐색
	int index;
	index = ru_find();

	// 돌진 // map이랑 Ri,Rj 수정
	map[Ri][Rj] = 0;
	Ri += dy_r[index];
	Rj += dx_r[index];
	// map[Ri][Rj] = 2; // 산타 있는지 없는지 먼저 확인해야함.


	// 충돌 있으면  // 기절 !! // 여기부터 디버깅 안되어있음
	if (map[Ri][Rj] == 1) {
		// 몇 번 산타인지 찾기 이미 Sort 해 두었기 때문에 // 혹시 다른 산타랑 부딫힐 수도 있나?
		
		// 산타 점수 획득
		San[0].score += RC;
		// 산타 밀려남
		//San[0].r + RC * dy_r[index];
		//San[0].c + RC * dx_r[index];		// 밀려나는 위치 확인 	
		//원래 자리 0으로 만들고 
		map[San[0].r][ San[0].c] = 0; // 루돌프가 올 자리라서 이건 안해줘도 됨. 
		San[0].kijul = 2;
		push_santa(San[0].n , San[0].r + RC * dy_r[index], San[0].c + RC * dx_r[index], index); // 누구를, 어디로, 어느 방향으로 

		map[Ri][Rj] = 2;
	}
	else { map[Ri][Rj] = 2; } // 충돌 없는 경우

}

int san_find_index(int r, int c) {
	int distance = 5000;
	int index = -1;
	for (int i = 0; i < 4; i++) {
		// 인덱스 검사 // 산타 없는지 검사 
		int y = r + dy_s[i], x = c + dx_s[i];
		if (check_index(y,x) == false) { continue; }
		if (map[y][x] == 1) { continue; }
		int dis = (Ri -y ) * (Ri -y) + (Rj -x) * (Rj-x);
		if (dis < distance) { index = i; distance = dis; }
	}
	//if (index == -1) { cout << "error" << endl; }
	return index;

}

int reverse(int n) {
	if (n == 0) { return 2; }
	if (n == 1) { return 3; }
	if (n == 2) { return 0; }
	if (n == 3) { return 1; }
}

bool ssort(Santa s1, Santa s2) {
	return s1.n < s2.n;
}

void santa_go() {
	// 산타가 돌진
	// 1번부터 P번 산타까지 죽지 않았으며, 기절하지 않은 산타에 대해 
	vector<Santa>::iterator it;
	// santa sort 해야댐
	sort(San.begin(), San.end(), ssort);
	for (it = San.begin(); it != San.end(); it++) {
		if (it->r > 0 && it->kijul == 0) {
			// 돌진 위치 탐색 
			int prev_distance = (it->r - Ri) * (it->r - Ri) + (it->c - Rj)*(it->c - Rj);
			int prev_y = it->r, prev_x = it->c;
			int index = san_find_index(it->r, it->c);
			if (index == -1) { continue; } // 못움직일 수도 있음
			int y = it->r + dy_s[index], x = it->c + dx_s[index];
			// 만약 기존보다 더 멀어진다면 안움직임!!!!!!!!!!!
			if (prev_distance <= (y - Ri) * (y - Ri) + (x - Rj) * (x - Rj)) { continue; }
			// 
			// 충돌 없다면 map 변경 및 vector 변경
			if (map[y][x] == 0) {
				map[prev_y][prev_x] = 0;
				map[y][x] = 1;
				it->r = y;
				it->c = x;
			}
			else if (map[y][x] == 2){ // 충돌 있다면
				index = reverse(index);
				// 밀려나는 위치 계산
				// y + dy_s[index] * D
				// x + dx_s[index]*D
				// 원래 있던 자리 0으로 만들고
				map[prev_y][prev_x] = 0;
				// 기절 flag 올리고 , 산타 점수 획득
				it->score += D; it->kijul = 2;
				// push santa
				push_santa_4(it->n, y + dy_s[index] * D, x + dx_s[index] * D, index); // 누구를, 어디로, 어느 방향으로
			
			}

			else { cout << "error" << endl; } // 산타가 있다면 못 움직여야하기 때문에 
		}
	}

}

int main() {
	int M; cin >> N >> M >> P >> RC >> D;
	cin >> Ri >> Rj;
	
	make_santa();
	make_map();

	for (int turn = 0; turn < M; turn++) {
		// 루돌프 돌진
		ru_go();

		// 산타 돌진
		santa_go() ;

		int is_alive = 0;
		vector<Santa>::iterator it;
		for (it = San.begin(); it != San.end(); it++) {
			if (it->r <= 0) { continue; }// 죽었다면 
			it->score++;
			is_alive++;
			if (it->kijul == 0) { continue; }
			it->kijul--;
		}
		// 모든 산타에게 kijul -1 ;
		// 남은 산타에 점수 부여, 만약 없다면 break;
		if (is_alive == 0) { break; }


	}
	// 산타의 점수 출력
	// sort
	sort(San.begin(), San.end(), ssort);
	vector<Santa>::iterator it;
	for (it = San.begin(); it != San.end(); it++) {
		cout << it->score << " ";
	}
	// 순서대로 출력

	return 0;
}