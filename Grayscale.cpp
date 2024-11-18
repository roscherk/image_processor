#include <cmath>
#include "Grayscale.h"
void Grayscale::Apply(Image& image) {
    for (int32_t i = 0; i < image.GetHeight(); ++i) {
        for (int32_t j = 0; j < image.GetWidth(); ++j) {
            Color current_color = image.GetColor(j, i);
            unsigned char value =
                round(0.299 * current_color.R() + 0.587 * current_color.G() + 0.114 * current_color.B());
            image.SetColor(j, i, Color(value, value, value));
        }
    }
}
