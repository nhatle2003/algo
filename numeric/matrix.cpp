struct Matrix{
    int n, m;

    vector<vector<int>> a;

    Matrix(int _n, int _m) : n(_n), m(_m), a(_n, vector<int> (_m, 0)) {}

    int getRow(){ return n; }
    int getCol(){ return m; }

    Matrix identity(){
        Matrix ans(n, n);
        for(int i = 0; i < n; i++){
            ans.a[i][i] = 1;
        }
        return ans;
    }
    Matrix operator * (Matrix &b){
        int _n = getRow(), _m = b.getCol(), sz = getCol();
        Matrix ans(getRow(), b.getCol());
        for(int i = 0; i < _n; i++){
            for(int j = 0; j < _m; j++){
                for(int k = 0; k < sz; k++){
                    (ans.a[i][j] += a[i][k] * b.a[k][j]) %= MOD;
                }
            }
        }
        return ans;
    }
};

Matrix bpow(Matrix &x, int y){
    Matrix res = x.identity();
    Matrix cur = x;
    for(; y; y >>= 1){
        if(y & 1) res = res * cur;
        cur = cur * cur;
    }
    return res;
}
