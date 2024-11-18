#include "GaussianBlur.h"
#include <cmath>

void GaussianBlur::Apply(Image& image) {
    // Гаусс будет!
    MatrixFilter::ApplyMatrix(image);
}

MatrixFilter::Matrix GaussianBlur::CreateMatrix(int sigma) {
    // размер матрицы взят из википедии
    const size_t matrix_size = 6 * sigma + 1;
    double sum = 0;  // для нормализации
    Matrix result(matrix_size);
    for (size_t y = 0; y < matrix_size; ++y) {
        result[y].resize(matrix_size);
        for (size_t x = 0; x < matrix_size; ++x) {
            result[y][x] = exp(-(pow(static_cast<int>(x) - 3 * sigma, 2) + pow(static_cast<int>(y) - 3 * sigma, 2)) / (2 * sigma * sigma)) /
                           (2 * M_PI * sigma * sigma);
            sum += result[y][x];
        }
    }
    // нормализуем
    for (size_t y = 0; y < matrix_size; ++y) {
        for (size_t x = 0; x < matrix_size; ++x) {
            result[y][x] /= sum;
        }
    }
    return result;
}
