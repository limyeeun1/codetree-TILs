#include <iostream>
#include <vector>

using namespace std;
int R,C;
bool check_south(const vector<vector<int>>& f, const int &c, const int &d){
    //유효 범위 확인 : c가 0보다 같거나 크고 R이랑 같거나 작은지
    //                d가 1보다 같거나 크고 C-1이랑 같거나 작은지
    //cout<< "here" << c << d << R << C<< "/"<< endl;
    //cout << "south";
    if ((c+2)<=(R+1) and d-1 >=0 and d+1<=C){
    //if (c<= R and d>=1 and d<=C-1){
        //cout << f[c+1][d-1] <<  f[c+1][d+1] << f[c+2][d] << endl;
        return f[c+1][d-1]==0 and f[c+1][d+1]==0 and f[c+2][d]==0;}
    else {return false;}
}

bool check_west(const vector<vector<int>>& f, const int &c, const int &d){
    //유효 범위 확인 : c가 0보다 같거나 크고 R-1랑 같거나 작은지
    //              d가 2보다 같거나 크고 C-1 이랑 같거나 작은지
    //cout << "west";
    //if (c<= R-1 and d>=2 and d<=C-1){
    if ((c+2)<=(R+1) and d-2>=0){
        return f[c-1][d-1]==0 and f[c][d-2]==0 and f[c+1][d-1]==0 and f[c+1][d-2]==0 and f[c+2][d-1]==0;}
    else {return false;}}

bool check_east(const vector<vector<int>> &f,const int &c, const int &d){
    // c가 0보다 같거나 크고 R-1랑 같거나 작은지
    // d가 1보다 같거나 크고 C-2랑 같거나 작은지
    //cout << "east" ;
    //if (c<= R-1 and d>=1 and d<=C-2){
    if ((c+2)<=(R+1) and (d+2)<=C){
        return f[c-1][d+1]==0 and f[c][d+2]==0 and f[c+1][d+1]==0 and f[c+1][d+2]==0 and f[c+2][d+1]==0;}
    else {return false;}
}

int rotate(int d, int direction){
    //west(0) 일때는 반시계 회전
    if (direction ==0){
        if (d==0){return 3;}
        if (d==2){return 1;}
        if (d==3){return 2;}
        if (d==1){return 0;}
    }
    //east 일때는 시계 회전
    else{
        if (d==0){return 1;}
        if (d==1){return 2;}
        if (d==3){return 0;}
        if (d==2){return 3;}
    }
}

void update(vector<vector<int>> &f, const int& a,const int& b){
    f[a][b] = a;
    f[a-1][b] = a;
    f[a+1][b] = a;
    f[a][b-1] = a;
    f[a][b+1] = a;
    return;
}

void update2(vector<vector<int>> &f, const int& a,const int& b, int c){
    f[a][b] = c;
    f[a-1][b] = c;
    f[a+1][b] = c;
    f[a][b-1] = c;
    f[a][b+1] = c;
    return;
}

int find_max(int a,int b, int c, int d){
    int t1,t2;
    if (a!=0 and b!=0){t1 = max(a,b);}
    else if (a==0){t1= b;}
    else if (b==0){t1= a;}

    if (c!=0 and d!=0){t2 = max(c,d);}
    else if (c==0){t2= d;}
    else if (d==0){t2= c;}
    return max(t1,t2);
}

int main() {
    int K; cin>>R>>C>>K;
    // 숲을 나타낼 자료구조 필요 0으로 가득 찬 이중배열
    vector<vector<int>> forest(R+2,vector<int>(C,0));
    C = C-1;
    int answer = 0;
    for (int i=0; i<K ; i++){
        int b,d; cin >> b >> d;
        b = b-1;

        int a=0, temp=0;
        //내려오는 알고리즘 
        bool flag=true;
        while(flag){
            //cout << flag << " : "<< endl;
            if (check_south(forest,a,b)){
                //cout <<"s ";
                a++;}
            else if (check_west(forest,a,b)){
                //cout << "w ";
                a++;b--;d=rotate(d,0);}
            else if (check_east(forest,a,b)){
                //cout << "e";
                a++;b++;d=rotate(d,1);}
            else {flag=false;}
            //cout << a << b << endl;
        }
        //cout << "out : " << a << b <<  endl;
        // 다 내려온 뒤, 가장 남쪽으로 이동했을 때의 행 번호 찾기
        // 골렘이 완전히 숲 안에 존재하는지 확인 해야함. 
        if (a<3){
            for(int k = 0; k < forest.size(); k++) {
                for(int l = 0; l < forest[k].size(); l++) {
                    forest[k][l] = 0;
                }
            }
            // cout << "clear" << endl;
        }
        else{
            // 숲 업데이트
            update(forest,a,b);
            // cout << "updated" << endl;
            // cout << "a:" <<a << " :b " << b << "d: " << d << endl;

            int ae,be; 
            if (d==0){ae=a-1;be=b;}
            else if (d==1){ae=a;be=b+1;}
            else if (d==2){ae=a;be=b-1;}
            else if (d==3){ae=a+1;be=b;}
            //cout << "d : "<< d << " " << ae << be << endl;
            int j1,j2,j3,j4;
            j1 = forest[ae-1][be];
            if (ae+1<=R+1){j2 = forest[ae+1][be];}
            else {j2=0;}
            j3 = forest[ae][be-1];
            j4 = forest[ae][be+1];
            // cout << j1 << j2 << j3 << j4 << "->" << find_max(j1,j2,j3,j4)<< endl;
            answer += find_max(j1,j2,j3,j4);
            update2(forest,a,b,find_max(j1,j2,j3,j4));
            //cout << answer << endl;
        }    
    }
    cout << answer ;
    return 0;
}