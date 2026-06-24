#include <vector>
#include <numeric>

using namespace std;

constexpr int MOD = 1e9 + 7;
using matrix = vector<int>;
static int m, m2;

// Standard Matrix Multiplication optimized for 1D compressed form
static inline matrix operator * (const matrix &A, const matrix &B) {
    matrix C(m2, 0);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            if (A[i * m + k] == 0) continue;
            for (int j = 0; j < m; j++) {
                C[i * m + j] = (C[i * m + j] + 1LL * A[i * m + k] * B[k * m + j]) % MOD;
            }
        }
    }
    return C;
}

// Optimized multiplication leveraging symmetric matrix properties to cut operations in half
static inline matrix symMul(const matrix &A, const matrix &B) {
    matrix C(m2, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            long long dotSum = 0;
            for (int k = 0; k < m; k++) {
                dotSum += 1LL * A[i * m + k] * B[j * m + k];
                if (dotSum >= MOD) dotSum %= MOD;
            }
            C[i * m + j] = C[j * m + i] = dotSum; 
        }
    }
    return C;
}

static matrix getIdentity() {
    matrix ans(m2, 0);
    for (int i = 0; i < m; i++) ans[i * m + i] = 1;
    return ans;
}

// Most Significant Bit First (MSBF) Modular Matrix Exponentiation
static matrix power(const matrix &M, unsigned int exp) {
    if (exp == 0) return getIdentity();
    int bMax = 31 - __builtin_clz(exp);
    matrix ans = M;
    for (int i = bMax - 1; i >= 0; i--) {
        ans = symMul(ans, ans);
        if ((exp >> i) & 1) ans = symMul(ans, M);
    }
    return ans;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        m = r - l + 1;
        m2 = m * m;
        
        matrix U(m2, 0), L(m2, 0);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) U[i * m + j] = 1;
            for (int j = 0; j < i; j++) L[i * m + j] = 1;
        }
        
        n--; // We need n-1 transitions for an array of length n
        const int n0 = n >> 1;
        const matrix UL = U * L;
        
        matrix P = power(UL, n0);
        
        // If n-1 transitions was odd, we have one remaining step using L
        if (n & 1) P = L * P;
        
        // Sum up all valid sequences and multiply by 2 for the symmetric patterns
        long long totalSum = 0;
        for (int val : P) {
            totalSum += val;
        }
        
        return (totalSum * 2) % MOD;
    }
};