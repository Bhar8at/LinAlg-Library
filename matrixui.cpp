#include <iostream>
#include <vector>

typedef  std::vector<std::vector<float> > IntMatrix;
typedef  std::vector<float> intRow;


IntMatrix FillMatrix(){
    int m,n,x;
    intRow Rowtemp;
    IntMatrix a;
    std::cout << "Number of Rows: " << std::endl;
    std::cin >> m;
    std::cout << "Number of Columns: " << std::endl;
    std::cin >> n;
    std::cout << "Enter the Elements of the Matrix" << std::endl;

    for ( int i = 0 ; i < m ; i++){
        Rowtemp.clear();
        for ( int j = 0 ; j < n; j++){
            std::cin >> x;
            Rowtemp.push_back(x);
        }
        a.push_back(Rowtemp);
    }

    return a;
}

void DisplayMatrix(IntMatrix a ){
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DisplayRow(intRow a){
    for (int i = 0; i < a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}