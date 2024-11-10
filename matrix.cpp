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

IntMatrix multiply_by_constant(IntMatrix a, double k){
    IntMatrix c;
     intRow row;
    for (int i = 0; i < a.size(); i++ ){
        row.clear();
        for (int j = 0; j < a[i].size(); j++){
            float x = a[i][j] * k;
            row.push_back(x);
        }
        c.push_back(row);
     }
     return c;
    }


IntMatrix dot(IntMatrix a, IntMatrix b){
     IntMatrix c;
     intRow row;
     if (a.size() == b.size() && a[0].size() == b[0].size()){
        for (int i = 0; i < a.size(); i++ ){
            row.clear();
            for (int j = 0; j < a[i].size(); j++){
                float x = a[i][j] * b[i][j];
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

IntMatrix inverse(IntMatrix a){
    
    
    // Performing LU decomposition to find the Inverse
    
    IntMatrix L, U;
    intRow Lrow, Urow;

    // Initializing L and U matrices (Makes the Decomposition code look cleaner)


    for (int i = 0; i < a.size(); i++){
        
        Lrow.clear();
        Urow.clear();
        
        for (int j = 0; j < a.size(); j++){

            // Appending the diagonal elements for U and L
            if (i == j){
                Urow.push_back(a[i][i]);
                Lrow.push_back(1);
            }

            // Appending 0s for Lower triangular matrix
            else if (i < j){
                Lrow.push_back(0);
                Urow.push_back(-1);
            }

            // Appending 0s for Upper triangular matrix
            else if (i > j){
                Urow.push_back(0);
                Lrow.push_back(-1);
            }

        }
        L.push_back(Lrow);
        U.push_back(Urow);

    }

    
    // Performing LU decomposition
    printf("--> Performing LU decomposition");

    for (int k = 0; k < a.size(); k++){

        U[k][k] = a[k][k];

        for (int i = k+1; i < a.size(); i++){

            L[i][k] = a[i][k]/a[k][k];
            U[k][i] = a[k][i];

        }

        for (int i = k + 1; i < a.size(); i++){
            
            for (int j = k + 1; j < a.size(); j++){
                
                a[i][j] = a[i][j] - (L[i][k] * U[k][j]);
            
            }

        }
        
    }

    printf("\n\n");
    DisplayMatrix(L);
    printf("\n\n");
    DisplayMatrix(U);
    printf("\n\n");

    // Initializing L_inverse and U_Inverse as Identity Matrices
    intRow temprow;
    IntMatrix L_inverse, U_inverse;
    printf("--> Initializing L_inverse and U_inverse\n");
    for (int i = 0 ; i < a.size(); i++){
        
        temprow.clear();

        for (int j = 0; j < a.size(); j++){

            if (i == j){
                temprow.push_back(1);
            }
            else {
                temprow.push_back(0);
            }

        }

        U_inverse.push_back(temprow);
        L_inverse.push_back(temprow);

    }

    // Finding the inverse of L
    printf("--> Finding the Inverse of L\n");
    for (int i = 0; i < L.size(); i++){
        
        // Checking if the next few rows have zero in that particular column
        for (int j = 1; i+j <L.size(); j++){

            if (L[i+j][i] != 0){

                L_inverse[i+j] = RowsubRow(L_inverse[i+j],Rowmultiply(L_inverse[i],L[i+j][i]));

            }
        }

    }

    // Finding the inverse of U
    printf("--> Finding the Inverse of U\n");
    for (int i = U.size()-1; i >= 0; i--){
        
        // Making diagonal elements = 1
        if (U[i][i] != 1){
            U_inverse[i] = Rowdiv(U_inverse[i],U[i][i]);
        }

        // Checking if the prev rows have zero in that particular column
        for (int j = 1; i-j >= 0; j++){

            if (U[i-j][i] != 0){

                U_inverse[i-j] = RowsubRow(U_inverse[i-j],Rowmultiply(U_inverse[i],U[i-j][i]));

            }
        }

    }
    printf("--> Finding the Inverse of A");
    IntMatrix A_inverse = multiply(U_inverse, L_inverse);
    printf("\n\n The inverse is: \n");
    DisplayMatrix(A_inverse);
    return A_inverse;



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