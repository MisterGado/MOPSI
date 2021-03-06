#include <iostream>
#include <Imagine/Images.h>
#include <Imagine/LinAlg.h>
#include <Imagine/Graphics.h>
#include <math.h>
#include <time.h>

using namespace std;
using namespace Imagine;

template <typename T> class StereoImages
{
    Image<T> imLeft, imRight;
    Image<byte> dispL, dispR;
    Matrix<int> dispMatrixL,dispMatrixR;
    int width,height;
    int ecart;
    bool reusing_path, smoothing;
public:
    StereoImages(string imL, string imR, bool reusing_path0 = true, bool smoothing0 = true);
    float computeColorInput(const int & row, Matrix<float> & smooth, const int & x, const int & y) const;
    void computeDPMatrix(Matrix<float>& dpMat, int row, Matrix<float> & path, Matrix<float> & smooth, bool fast) const;
    int dif(int row, int colLeft, int colRight) const;
    void addRowDisparityMaps(int row, Matrix<float> & path, Matrix<float> & smooth, bool fast);
    void computeDisparity(bool fast = false);
    void displayAll() const;
    void computeScore(string namegtL, string namegtR) const;
};
