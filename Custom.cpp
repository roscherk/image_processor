#include <cmath>
#include "Custom.h"

void Custom::Apply(Image& image) {
    Distort(image);
    GaussianBlur blur(1);
    blur.Apply(image);
    Colorize(image);
}

void Custom::Distort(Image& image) {
    Image reference(image);
    const int32_t height = image.GetHeight() - 1;
    const int32_t width = image.GetWidth() - 1;
    // побочная диагональ картинки имеет вид y = -(height / width) * x + height
    // размытие под ней будет вниз, над ней — вверх
    auto diagonal = [height, width](int x) {
        return round(-static_cast<float>(height) / width * x + height);
    };
    for (int32_t j = 0; j < width; ++j) {
        for (int32_t i = 0; i < height; ++i) {
            // знак определяет сторону, в которую размываем
            const int sign = i <= diagonal(j) ? 1 : -1;
            // размываем либо на distortion_degree_^2, либо на расстояние от точки до побочной диагонали
            const int32_t shift =
                fmin(distortion_degree_ * distortion_degree_,
                     floor(std::abs(-static_cast<float>(height) / width * j - i + height) /
                           sqrt(pow(static_cast<float>(height) / width, 2) + 1)));
            // берем из reference текущий пиксель
            const Color current = reference.GetColor(j, i);
            // получаем «пиксель размытия»
            const Color target = reference.GetColor(std::clamp(j + sign * shift, 0, width),
                                                    std::clamp(i + sign * shift, 0, height));
            image.SetColor(
                j, i,
                Color(round(current.B() * 2 / 3 + target.B() / 3), round(current.G() * 2 / 3  + target.G() / 3),
                      round(current.R() * 2 / 3  + target.R() / 3)));
        }
    }
}

void Custom::Colorize(Image& image) {
    const unsigned char target_r = 80;
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            Color current_color = image.GetColor(j, i);
            image.SetColor(j, i,
                           Color(std::clamp(current_color.B() - target_r / 2, 10, 255),
                                 std::clamp(current_color.G() - target_r / 2, 10, 255),
                                 std::clamp(current_color.R() + target_r, 0, 255)));
        }
    }
}