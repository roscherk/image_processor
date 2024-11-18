#include <cmath>
#include "MatrixFilter.h"

void MatrixFilter::ApplyMatrix(Image &image) {
    Image reference(image);
    // предполагается, что 1) матрица не пуста (задается в конструкторах наследников MatrixFilter);
    // 2) ширина и высота матрицы нечетны (иначе не будет центрального пикселя) и равны;
    // 3) ширина и высота матрицы помещаются в int (мы не верим в матрицы 2 147 483 648 х 2 147 483 648)
    // проверяем, что все выполняется:
    if (matrix_.empty() || (matrix_.size() != matrix_[0].size()) || (matrix_.size() % 2 == 0) ||
        (matrix_.size() > INT_MAX)) {
        throw std::runtime_error("Wrong matrix for MatrixFilter::ApplyMatrix(Image &image)");
    }
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            double b = 0;
            double g = 0;
            double r = 0;
            for (size_t t = 0; t < matrix_.size(); ++t) {
                for (size_t k = 0; k < matrix_.size(); ++k) {
                    unsigned int x =
                        std::clamp(static_cast<int32_t>(j + k - (matrix_.size() - 1) / 2), 0, image.GetWidth() - 1);
                    unsigned int y =
                        std::clamp(static_cast<int32_t>(i + t - (matrix_.size() - 1) / 2), 0, image.GetHeight() - 1);
                    r += matrix_[t][k] * reference.GetColor(x, y).R();
                    g += matrix_[t][k] * reference.GetColor(x, y).G();
                    b += matrix_[t][k] * reference.GetColor(x, y).B();
                }
            }
            unsigned char target_r = std::clamp(static_cast<int>(round(r)), 0, 255);
            unsigned char target_g = std::clamp(static_cast<int>(round(g)), 0, 255);
            unsigned char target_b = std::clamp(static_cast<int>(round(b)), 0, 255);
            image.SetColor(j, i, Color(target_b, target_g, target_r));
        }
    }
}