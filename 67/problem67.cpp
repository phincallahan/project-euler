#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector< vector<int> > read_tri(string path) {
    ifstream f (path);
    string line;
    vector< vector<int> > matrix (0, vector<int>(0));

    if(f.is_open()) {
        while(getline(f, line)) {
            vector<int> row (0,0);
            for(int i = 0; 3*i + 1 < line.length(); i++) {
                row.push_back((line[3*i] - '0')*10 + line[3*i+1] - '0');
            }

            matrix.push_back(row);
        }
    }

    return matrix;
}

long max_tri_path(vector< vector<int> > tri) {
    for(int i = tri.size() - 2; i >= 0; i--) {
        for(int j = 0; j < tri[i].size(); j++) {
            tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
        }
    }

    return tri[0][0];
}

int main() {
    vector< vector<int> > matrix = read_matrix("problem67_matrix.txt");
    cout << max_tri_path(matrix) << "\n";
}
