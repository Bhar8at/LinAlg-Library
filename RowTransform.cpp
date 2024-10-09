#include <iostream>
#include <vector>
#include <cmath>
typedef  std::vector<float> intRow;


float roundTo4Decimals(float value) {
    return round(value * 10000000000) / 10000000000;
}

intRow Rowdiv (intRow Row, float x){
    for (int i = 0; i < Row.size(); i++){
        if (Row[i]!= 0){
        Row[i] = roundTo4Decimals(Row[i]/x);
        }
    }
    return Row;
}

intRow Rowmultiply (intRow Row, float x){
    for (int i = 0; i < Row.size(); i++){
        Row[i] = roundTo4Decimals(Row[i]*x);
    }
    return Row;
}


intRow RowsubRow (intRow Row1, intRow Row2){
    if (Row1.size()!= Row2.size()){
        std::cerr << "The Rows your operating on dont have the same number of elements" << std::endl;
    }
    intRow Row3;
    for (int i = 0; i < Row1.size(); i++){
        Row3.push_back(roundTo4Decimals(Row1[i] - Row2[i]));
    }
    return Row3;
}

intRow RowadddRow (intRow Row1, intRow Row2){
    if (Row1.size()!= Row2.size()){
        std::cerr << "The Rows your operating on dont have the same number of elements" << std::endl;
    }
    intRow Row3;
    for (int i = 0; i < Row1.size(); i++){
        Row3.push_back(roundTo4Decimals(Row1[i] + Row2[i]));
    }
    return Row3;
}

intRow Rowdot (intRow Row1, intRow Row2){
    intRow Row3;
    for (int i = 0; i < Row1.size(); i++){
        Row3.push_back(roundTo4Decimals(Row1[i] * Row2[i]));
    }
    return Row3;
}