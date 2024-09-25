#include <iostream>
#include <vector>
#include "RowTransform.h"
#include "matrixui.h"

typedef  std::vector<std::vector<float> > IntMatrix;
typedef  std::vector<float> intRow;

IntMatrix sum(IntMatrix a, IntMatrix b){
     IntMatrix c;
     intRow row;
     if (a.size() == b.size() && a[0].size() == b[0].size()){
        for (int i = 0; i < a.size(); i++ ){
            row.clear();
            for (int j = 0; j < a[i].size(); j++){
                float x = a[i][j] + b[i][j];
                row.push_back(x);
        }
        c.push_back(row);
     }
     return c;
    }
    else{
        std::cerr << "The Dimensions Seem to be NOT the same !"<< std::endl;
        return c;
    }    
}


IntMatrix diff(IntMatrix a, IntMatrix b){
     IntMatrix c;
     intRow row;
     if (a.size() == b.size() && a[0].size() == b[0].size()){
        for (int i = 0; i < a.size(); i++ ){
            row.clear();
            for (int j = 0; j < a[i].size(); j++){
                float x = a[i][j] - b[i][j];
                row.push_back(x);
        }
        c.push_back(row);
     }
     return c;
    }
    else{
        std::cerr << "The Dimensions Seem to be NOT the same !"<< std::endl;
        return c;
    }    
}

IntMatrix multiply(IntMatrix a, IntMatrix b){
    IntMatrix c;
    intRow row;
    int cm = a.size();
    int cn = b[0].size(); 
    float e;
    if (a[0].size() == b.size()){
        for (int i = 0; i < cm; i++ ){
            row.clear();
            for ( int j = 0; j < cn; j++){
                e = 0;
                for ( int k = 0; k < b.size(); k++){
                e += a[i][k]*b[k][j];
                }
                row.push_back(e);
            }
            c.push_back(row);
        }
        return c;
     }
    else{
        std::cerr << "The Dimensions Seem to be NOT the same !"<< std::endl;
        return c;
    }    
}

// // Incase I want to ever debug and make it better.
// IntMatrix inverse(IntMatrix a){
//     int am = a.size();
//     int an = a[0].size();
//     IntMatrix I;
//     intRow Row;
//     if (am != an){
//         std::cerr << "The Given matrix is not a Square Matrix and hence the Inverse cannot be computed!" << std::endl;
//         return a;
//     }

//     // Creating an Identity Matrix
//     for (int i = 0 ; i < am; i++){
//         Row.clear();
//         for (int j = 0 ; j < am; j++){
//             if (i ==j){
//                 Row.push_back(1);
//             } 
//             else{
//                 Row.push_back(0);
//             }
//         }
//         I.push_back(Row);
//     }
 
//     // Finding the number of zeros in each order 
//     std::vector<int> n0;
//     std::vector<float> temp;
//     for (int i = 0; i < a.size(); i++){
//         n0.push_back(0);
//         for ( int j = 0 ; j < a[0].size(); j++){
//             if (a[i][j] == 0){
//                 n0[i]++;
//             }
//         }
//     }

//     // Sorting according to number of zeros in the matrix
//     for (int i = 0; i < a.size(); i++){
//         for ( int j = i; j < a.size(); j++){
//             if (n0[i] > n0[j]){
//                 temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }

//     std::cout << "After sorting this is how the matrix looks like : " << std::endl;
//     DisplayMatrix(a);
//     std::cout << "\n\n" << std::endl;


    
//     // Finding REF
//     int colindex = 0;
//     for (int i = 0 ; i < a.size(); i++){
//         while(a[i][colindex] == 0){
//             if (colindex < a[0].size()){
//                 colindex++;
//             }
//         }
//         if (a[i][colindex]!=0){
//             // Dividing the Row by the Initial non-zero value 
//             std::cout << "--> Dividing Row" << i << " by " << a[i][colindex] << std::endl;
//             I[i] = Rowdiv(I[i], a[i][colindex]);
//             a[i]  = Rowdiv(a[i], a[i][colindex]);
//             DisplayMatrix(a);
//             std::cout << std::endl;
//             DisplayMatrix(I);

//             // Iterating over other rows to subtract and get zeroes below the pivot element
//             for ( int j = i+1; j < a.size(); j++){
//                 if (a[j][colindex]!=0){
//                 temp = Rowmultiply(I[i], a[j][colindex]);
//                 I[j] = RowsubRow(I[j], temp);
//                 temp = Rowmultiply(a[i], a[j][colindex]);
//                 std::cout << "->Multyplying Row " << i << " by " << a[j][colindex] << "and subtracting from Row " << j<< std::endl;
//                 a[j] = RowsubRow(a[j],temp);
//                 DisplayMatrix(a);
//                 std::cout << std::endl;
//                 DisplayMatrix(I);
//                 }  
//                 std::cout << std::endl;      
//             }
//         }
//         else{
//             std::cout << "\n there are no more non-zeros in this row" << std::endl;
//         }
//     }

//     std::cout << "\n REF Found !" << std::endl;
//     DisplayMatrix(a);
//     std::cout << std::endl;
//     DisplayMatrix(I);


//     // Finding RREF
//     int rindex = -1;
//     int x = 0;
//     int nosol = 0;
//     for (int i = a.size()-1; i > -1 ; i--){
//         std::cout << " \n\n Entering the Row : " << i << std::endl; 
//         x = 0;
//         for (int j = 0; j < a[0].size(); j++){

//             if (x != 0 and a[i][j] !=0){ // Case where we found our pivot value but there seems to be another value
//                 std::cout << " OK so our x and current element respectivelty are "<< x << " " << a[i][j] << std::endl;
//                 nosol = 1;
//                 break;
//             }

//             if (a[i][j] != 0){
//                 x = a[i][j];
//                 rindex = j;
//             }

//         }
    
//         if (x == 0){
//             std::cout << "\n\nThere is no solution for this matrix / No Inverse !!\n\n";
//             break;
//         }
//         else if (nosol == 0 and i > -1){
//             for ( int j = i-1; j > -1; j--){
//                 if (a[j][rindex] !=0){
//                     temp = Rowmultiply(I[i], a[j][rindex]);
//                     I[j] = RowsubRow(I[j],temp);
//                     std::cout << "Subtracting Row " << i << " from " << j << std::endl; 
//                     a[j][rindex] -= x*a[j][rindex];
//                 }

//             }
//         }

//     }
//     std::cout << "\n\n Here is the inverse of the above matrix: \n" << std::endl;
//     DisplayMatrix(I);
//     return a;
// }


IntMatrix inverse(IntMatrix a){
    int am = a.size();
    int an = a[0].size();
    IntMatrix I;
    intRow Row;
    if (am != an){
        std::cerr << "The Given matrix is not a Square Matrix and hence the Inverse cannot be computed!" << std::endl;
        return a;
    }

    // Creating an Identity Matrix
    for (int i = 0 ; i < am; i++){
        Row.clear();
        for (int j = 0 ; j < am; j++){
            if (i ==j){
                Row.push_back(1);
            } 
            else{
                Row.push_back(0);
            }
        }
        I.push_back(Row);
    }
 
    // Finding the number of zeros in each order 
    std::vector<int> n0;
    std::vector<float> temp;
    for (int i = 0; i < a.size(); i++){
        n0.push_back(0);
        for ( int j = 0 ; j < a[0].size(); j++){
            if (a[i][j] == 0){
                n0[i]++;
            }
        }
    }

    // Sorting according to number of zeros in the matrix
    for (int i = 0; i < a.size(); i++){
        for ( int j = i; j < a.size(); j++){
            if (n0[i] > n0[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Finding REF
    int colindex = 0;
    for (int i = 0 ; i < a.size(); i++){
        while(a[i][colindex] == 0){
            if (colindex < a[0].size()){
                colindex++;
            }
        }
        if (a[i][colindex]!=0){
            // Dividing the Row by the Initial non-zero value 
            I[i] = Rowdiv(I[i], a[i][colindex]);
            a[i]  = Rowdiv(a[i], a[i][colindex]);

            // Iterating over other rows to subtract and get zeroes below the pivot element
            for ( int j = i+1; j < a.size(); j++){
                if (a[j][colindex]!=0){
                temp = Rowmultiply(I[i], a[j][colindex]);
                I[j] = RowsubRow(I[j], temp);
                temp = Rowmultiply(a[i], a[j][colindex]);
                a[j] = RowsubRow(a[j],temp);
                }     
            }
        }
        else{
            std::cout << "\n there are no more non-zeros in this row" << std::endl;
        }
    }

    // Finding RREF
    int rindex = -1;
    int x = 0;
    int nosol = 0;
    for (int i = a.size()-1; i > -1 ; i--){
        x = 0;
        for (int j = 0; j < a[0].size(); j++){

            if (x != 0 and a[i][j] !=0){ // Case where we found our pivot value but there seems to be another value
                nosol = 1;
                break;
            }

            if (a[i][j] != 0){
                x = a[i][j];
                rindex = j;
            }

        }
    
        if (x == 0){
            std::cout << "\n\nThere is no solution for this matrix / No Inverse !!\n\n";
            break;
        }
        else if (nosol == 0 and i > -1){
            for ( int j = i-1; j > -1; j--){
                if (a[j][rindex] !=0){
                    temp = Rowmultiply(I[i], a[j][rindex]);
                    I[j] = RowsubRow(I[j],temp);
                    a[j][rindex] -= x*a[j][rindex];
                }

            }
        }

    }
    return I;
}

IntMatrix transpose(IntMatrix a){
    
    /* ONLY WORKS FOR SQUARE MATRICES*/
    // but faster than below function
    // for (int i = 1 ; i < a.size(); i++){
    //     for (int j = 0; j < i; j++){
    //         a[i][j] = a[i][j] + a[j][i];
    //         a[j][i] = a[i][j] - a[j][i];
    //         a[i][j] = a[i][j] - a[j][i];
    //     }
    // }

    /* GENERALIZED ALGORITHMS FOR ALL MATRICES */
    // but we're construction a new matix completely so it wont be as fast 

    int m = a[0].size();
    int n = a.size();

    intRow Row;
    IntMatrix T;
    for (int i = 0 ; i < m; i++){
        Row.clear();
        for (int j = 0; j < n; j++){
        Row.push_back(a[j][i]);
        } 
        T.push_back(Row);
    }

    return T;
}