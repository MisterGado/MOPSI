#include <iostream>
#include <Imagine/Images.h>
#include <Imagine/LinAlg.h>
#include <Imagine/Graphics.h>
#include <math.h>

using namespace std;
using namespace Imagine;

class StereoImages
{
    Image<byte> imLeft, imRight;
    Image<byte> dispL, dispR; 
    int width,height;
public:
    StereoImages(string imL, string imR);
    void computeDPMatrix(Matrix<int>& dpMat, int row) const;
    int dif(int row, int colLeft, int colRight) const;
    void addRowDisparityMaps(Matrix<int>& dispMapL, Matrix<int>& dispMapR, int row) const;
    void computeDisparity();
    void displayAll() const;
};