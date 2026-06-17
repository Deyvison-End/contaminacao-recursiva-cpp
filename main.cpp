#include <iostream>
#include <vector>

using namespace std;

void solucao_iterativa(vector<vector<char>> &mat) {
    bool changed;
    const int M = static_cast<int>(mat.size());
    const int N = static_cast<int>(mat[0].size());
    do {
        changed = false;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] != 'A') continue;

                if ((i > 0 && mat[i - 1][j] == 'T') ||
                    (j > 0 && mat[i][j - 1] == 'T') ||
                    (j < N - 1 && mat[i][j + 1] == 'T') ||
                    (i < M - 1 && mat[i + 1][j] == 'T')) {
                    mat[i][j] = 'T';
                    changed = true;
                }
            }
        }
    } while (changed);
}

void contaminar(vector<vector<char>> &mat, int i, int j) {
    const int M = static_cast<int>(mat.size());
    const int N = static_cast<int>(mat[0].size());

    if (i < 0 || i >= M || j < 0 || j >= N) return;

    
    if (mat[i][j] != 'A') return;

    
    mat[i][j] = 'T';

    
    contaminar(mat, i - 1, j); 
    contaminar(mat, i + 1, j);   
    contaminar(mat, i, j - 1); 
    contaminar(mat, i, j + 1); 
}

void solucao_recursiva(vector<vector<char>> &C) {
    const int M = static_cast<int>(C.size());
    const int N = static_cast<int>(C[0].size());
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] == 'T') {
                contaminar(C, i - 1, j);
                contaminar(C, i + 1, j); 
                contaminar(C, i, j - 1); 
                contaminar(C, i, j + 1);
            }
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<char>> matriz(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }

    // solucao_iterativa(matriz);
    solucao_recursiva(matriz);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}