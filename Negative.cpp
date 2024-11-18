#include "Negative.h"

void Negative::Apply(Image& image) {
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            Color current_color = image.GetColor(j, i);
            image.SetColor(j, i,
                           Color(UCHAR_MAX - current_color.B(), UCHAR_MAX - current_color.G(),
                                 UCHAR_MAX - current_color.R()));
        }
    }
}
