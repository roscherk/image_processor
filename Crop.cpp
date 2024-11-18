#include "Crop.h"
void Crop::Apply(Image& image) {
    image.Resize(std::min(image.GetWidth(), new_width_), std::min(image.GetHeight(), new_height_));
}
