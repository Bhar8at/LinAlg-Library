// UI Related Functions
#ifndef matrixui_h
#define matrixui_h

#include<vector>

typedef  std::vector<std::vector<float> > IntMatrix;
typedef std::vector<float> intRow;
IntMatrix FillMatrix();
void DisplayMatrix(IntMatrix a);
void DisplayRow(intRow a);
#endif