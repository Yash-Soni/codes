// Solution using XOR
void getNums(int&x, int&y, const vector<int>& A) {
    int n=A.size();
    int xor1=A[0];
    for(int i=1; i<n; i++) {
        xor1 = xor1 ^ A[i];
    }
    for(int i=1; i<=n; i++) {
        xor1 = xor1 ^ i;
    }
    int set_bit_no = xor1 & ~(xor1-1);
    
    for(int i=0; i<n; i++) {
        if((A[i] & set_bit_no) != 0) {
            x = x ^ A[i];
        } else {
            y = y ^ A[i];
        }
    }
    
    for(int i=1; i<=n; i++) {
        if((i & set_bit_no) != 0) {
            x = x ^ i;
        } else {
            y = y ^ i;
        }
    }
}

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> vec(0);
    int x=0, y=0;
    getNums(x, y, A);
    // cout<<"x: "<<x<<", y="<<y<<"\n";
    if(x < y) {
        vec.push_back(y);
        vec.push_back(x);
    } else {
        vec.push_back(x);
        vec.push_back(y);
    }
    return vec;
}
