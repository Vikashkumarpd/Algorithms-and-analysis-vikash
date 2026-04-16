#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;


void print(const Matrix& M, string label) {
    cout << label << ":\n";
    for (auto& row : M) {
        for (int v : row) cout << v << "\t";
        cout << "\n";
    }
    cout << "\n";
}


Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}


Matrix sub(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix mul2x2(const Matrix& A, const Matrix& B) {
    Matrix C(2, vector<int>(2));
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    return C;
}

// ── STRASSEN ──────────────────────────────────────────────
//
//  Key idea: replace 8 recursive multiplications with 7
//  by computing clever intermediate products (P1..P7)
//  using extra additions/subtractions (which are cheap O(n²))
//
//  Complexity: T(n) = 7·T(n/2) + O(n²)  →  O(n^2.807)
//
Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // ── BASE CASE ─────────────────────────────────────────
    if (n == 2)
        return mul2x2(A, B);

    // ── SPLIT ─────────────────────────────────────────────
    int h = n / 2;

    Matrix A11(h, vector<int>(h)),  A12(h, vector<int>(h)),
           A21(h, vector<int>(h)),  A22(h, vector<int>(h));

    Matrix B11(h, vector<int>(h)),  B12(h, vector<int>(h)),
           B21(h, vector<int>(h)),  B22(h, vector<int>(h));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            A11[i][j] = A[i][j];      A12[i][j] = A[i][j+h];
            A21[i][j] = A[i+h][j];    A22[i][j] = A[i+h][j+h];

            B11[i][j] = B[i][j];      B12[i][j] = B[i][j+h];
            B21[i][j] = B[i+h][j];    B22[i][j] = B[i+h][j+h];
        }
    }

    // ── 7 STRASSEN PRODUCTS ───────────────────────────────
    //
    //  Each P is one recursive multiplication on half-size matrices.
    //  The inputs are cheap adds/subs of quadrants — NOT multiplications.
    //
    //  P1 = (A11 + A22) * (B11 + B22)
    //  P2 = (A21 + A22) *  B11
    //  P3 =  A11        * (B12 - B22)
    //  P4 =  A22        * (B21 - B11)
    //  P5 = (A11 + A12) *  B22
    //  P6 = (A21 - A11) * (B11 + B12)
    //  P7 = (A12 - A22) * (B21 + B22)
    //
    Matrix P1 = strassen( add(A11,A22),  add(B11,B22) );
    Matrix P2 = strassen( add(A21,A22),  B11          );
    Matrix P3 = strassen( A11,           sub(B12,B22) );
    Matrix P4 = strassen( A22,           sub(B21,B11) );
    Matrix P5 = strassen( add(A11,A12),  B22          );
    Matrix P6 = strassen( sub(A21,A11),  add(B11,B12) );
    Matrix P7 = strassen( sub(A12,A22),  add(B21,B22) );

    // ── COMBINE: build C quadrants from P1..P7 ────────────
    //
    //  C11 =  P1 + P4 - P5 + P7
    //  C12 =  P3 + P5
    //  C21 =  P2 + P4
    //  C22 =  P1 - P2 + P3 + P6
    //
    Matrix C11 = add( sub( add(P1,P4), P5 ), P7 );
    Matrix C12 = add( P3, P5 );
    Matrix C21 = add( P2, P4 );
    Matrix C22 = add( sub( add(P1,P3), P2 ), P6 );

    // ── JOIN quadrants ────────────────────────────────────
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < h; j++) {
            C[i][j]     = C11[i][j];
            C[i][j+h]   = C12[i][j];
            C[i+h][j]   = C21[i][j];
            C[i+h][j+h] = C22[i][j];
        }
    }
    return C;
}

// ── MAIN ──────────────────────────────────────────────────
int main() {
    // 2x2 — hits base case directly
    Matrix A2 = {{1,2},{3,4}};
    Matrix B2 = {{5,6},{7,8}};
    cout << "=== 2x2 ===\n";
    print(strassen(A2, B2), "A x B");

    // 4x4 — one level of recursion, 7 products of 2x2s
    Matrix A4 = {
        {1,2,0,4},
        {5,5,7,8},
        {1,0,4,0},
        {4,1,0,1}
    };
    Matrix B4 = {
        {8,3,5,1},
        {0,1,1,0},
        {1,0,3,1},
        {0,7,2,0}
    };
    cout << "=== 4x4 ===\n";
    print(strassen(A4, B4), "A x B");

    // 8x8 — two levels deep
    int n = 8;
    Matrix A8(n, vector<int>(n)), B8(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A8[i][j] = (i+j) % 5 + 1;
            B8[i][j] = (i*j) % 4 + 1;
        }
    cout << "=== 8x8 ===\n";
    print(strassen(A8, B8), "A x B");

    return 0;
}