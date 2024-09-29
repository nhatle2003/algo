#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}

double randdouble(double l, double r){
    return uniform_real_distribution<double>(l, r)(rng);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TEST_LIM = 1e3;
    for(int test = 1; test <= TEST_LIM; test++){
        #define task ""
        ofstream inp(task ".inp");
        // code here

        inp.close();

        system(task ".exe");
        system(task "_trau.exe");

        cout << "Case #" << test << " : ";

        if(system("fc " task ".out " task ".ans") == 0){
            cout << "AC" << endl;
        }
        else{
            cout << "WA" << endl;
            return 0;
        }
    }

    return 0;
}
