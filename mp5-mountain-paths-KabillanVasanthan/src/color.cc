#include "color.hpp"
#include <stdexcept>
#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
using namespace std;

Color::Color(int r, int g, int b): red_(r), green_(g), blue_(b) {
  int max = kColorValueMax;
  int min = kColorValueMin;
  if((red_ < min ||red_ > max) || (green_ < min ||green_ > max) || (blue_ < min ||blue_ > max)) {
    throw std::invalid_argument("invalid argument");
  }
}

// do not modify
bool operator==(const Color& rhs, const Color& lhs) {
  return (rhs.Red() == lhs.Red() && rhs.Green() == lhs.Green() &&
          rhs.Blue() == lhs.Blue());
}