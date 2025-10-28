#include <iostream>

using namespace std;

int main() {
    int rows , cols, occ, a, r, c;

    cout << "Enter no of rows and columns: ";
    cin >> rows >> cols;

    int mat[rows][cols];  

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }

    cout << "enter no of occupied beds: ";
    cin >> occ;

    for (int a = 0; a < occ; a++) {
        cout << "Enter positions rows and columns: ";
        cin >> r >> c;
        r = r-1;
        c = c-1;

        if (r >= 0 && r < rows && c >= 0 && c < cols)
            mat[r][c] = 1;
        else
            cout << "Invalid Position";       
        
    }
    for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        cout<<"Row  Column  Value"<<endl;
     for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j]!=0)
                {
                   cout<<i<<"       "<<j<<"       " <<mat[i][j]<<endl;
                }   
            }
        }
    return 0;
}
