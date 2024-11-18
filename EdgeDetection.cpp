#include "EdgeDetection.h"

void EdgeDetection::Apply(Image& image) {
    Grayscale::Apply(image);
    MatrixFilter::ApplyMatrix(image);
    const Color black(0, 0, 0);
    const Color white(255, 255, 255);
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            if (image.GetColor(j, i).R() > threshold_) {
                image.SetColor(j, i, white);
            } else {
                image.SetColor(j, i, black);
            }
        }
    }
}
