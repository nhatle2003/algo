const int SYSTEM = 2;
int MOD[SYSTEM] = {(int) 1e9 + 7, (int) 998244353};
int BASE[SYSTEM] = {(int) 31, (int) 83};

int powb[SYSTEM][N];
int hsh[SYSTEM][N];
int rhsh[SYSTEM][N];

void hsh_precomp(){
    for(int i = 0; i < SYSTEM; i++){
        powb[i][0] = 1;
        for(int j = 1; j < N; j++){
            powb[i][j] = (powb[i][j - 1] * BASE[i]) % MOD[i];
        }
    }
}

void hsh_proc(){
    for(int i = 0; i < SYSTEM; i++){
        for(int j = 1; j <= 2 * n; j++){
            hsh[i][j] = (hsh[i][j - 1] * BASE[i] + a[j] + 1) % MOD[i];
        }
    }
    for(int i = 0; i < SYSTEM; i++){
        for(int j = 2 * n; j >= 1; j--){
            rhsh[i][j] = (rhsh[i][j + 1] * BASE[i] + a[j] + 1) % MOD[i];
        }
    }
}

int hsh_get(int l, int r, int sys){
    int sz = r - l + 1;
    return ((hsh[sys][r] - hsh[sys][l - 1] * powb[sys][sz] % MOD[sys]) % MOD[sys] + MOD[sys]) % MOD[sys];
}

int hsh_rget(int l, int r, int sys){
    int sz = r - l + 1;
    return ((rhsh[sys][l] - rhsh[sys][r + 1] * powb[sys][sz] % MOD[sys]) % MOD[sys] + MOD[sys]) % MOD[sys];
}
