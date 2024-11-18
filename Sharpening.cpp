#include "Sharpening.h"

void Sharpening::Apply(Image& image) {
    MatrixFilter::ApplyMatrix(image);
}
