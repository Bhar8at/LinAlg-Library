// Row Transformations
#ifndef ROW_H
#define ROW_H

#include<vector>

typedef  std::vector<float> intRow;

intRow Rowdiv (intRow Row, float x);
intRow Rowmultiply (intRow Row, float x);
intRow RowsubRow (intRow Row1, intRow Row2);
intRow RowadddRow (intRow Row1, intRow Row2);
float roundTo4Decimals(float value);
intRow Rowdot(intRow Row1, intRow Row2);

#endif