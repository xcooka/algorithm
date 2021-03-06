#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 200;
int data[MAXN][MAXN];
int states[MAXN*MAXN];
vector<int> g[MAXN*MAXN];
int sz;
class Transpose {
    public:
        void dfs(int cur){
            if(states[cur]!=0){
                return ;
            }
            states[cur] = 1;
            for(int i=0; i<g[cur].size(); i++){
                dfs(g[cur][i]);
            }
        }

        int work(){
            memset(states,0,sizeof(states));
            int circles = 0;
            for(int i=0; i<sz; i++){
                if(states[i]==0 && g[i].size()!=0){
                    dfs(i);
                    circles+=1;
                }
            }
            return circles;
        }
        int numSwaps(int M, int N) {
            sz = M*N;
            memset(data,0,sizeof(data));
            for(int i=0; i<MAXN*MAXN;i++)g[i].clear();
            for(int  i=0; i<M; i++){
                for(int j=0; j<N; j++){
                    data[j][i] = i*N+j;
                }
            }
            for(int  i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    cout<<data[i][j]<<' ';
                }
                cout<<endl;
            }
            int cur = 0;
            int wrong_pos = 0;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    if(data[i][j]!=cur){
                        wrong_pos+=1;
                        g[cur].push_back(data[i][j]);
                        g[data[i][j]].push_back(cur);
                    }
                    cur++;
                }
            }
            cout<<"wrong pos "<<wrong_pos<<endl;
            int circles = work();
            cout<<"circles = "<<circles<<endl;
            return wrong_pos - circles;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1;
    cout << "]" << endl;
    Transpose *obj;
    int answer;
    obj = new Transpose();
    clock_t startTime = clock();
    answer = obj->numSwaps(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    int p0;
    int p1;
    int p2;
    {
        // ----- test 0 -----
        p0 = 3;
        p1 = 3;
        p2 = 3;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 1 -----
        p0 = 2;
        p1 = 3;
        p2 = 3;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 2 -----
        p0 = 3;
        p1 = 5;
        p2 = 10;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 3 -----
        p0 = 50;
        p1 = 50;
        p2 = 1225;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }
    {
        // ----- test 4 -----
        p0 = 49;
        p1 = 51;
        p2 = 2492;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
