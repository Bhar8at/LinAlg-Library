// Matrix Operations
#ifndef MATRIX_H
#define MATRIX_H


#include<vector>


typedef  std::vector<std::vector<float> > IntMatrix;
typedef  std::vector<float> intRow;


IntMatrix sum(IntMatrix a, IntMatrix b);
IntMatrix diff(IntMatrix a, IntMatrix b);
IntMatrix multiply(IntMatrix a, IntMatrix b);
IntMatrix inverse(IntMatrix a);
IntMatrix transpose(IntMatrix a );


#endif