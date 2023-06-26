#include "seam_carver.hpp"
#include <iostream>

// implement the rest of SeamCarver's functions here

// given functions below, DO NOT MODIFY

SeamCarver::SeamCarver(const ImagePPM& image): image_(image) {
  height_ = image.GetHeight();
  width_ = image.GetWidth();
}

void SeamCarver::SetImage(const ImagePPM& image) {
  image_ = image;
  width_ = image.GetWidth();
  height_ = image.GetHeight();
}
const ImagePPM& SeamCarver::GetImage() const {
  return image_;
}
int SeamCarver::GetHeight() const	{
  return height_;
}
int SeamCarver::GetWidth() const	{
  return width_;
}
int SeamCarver::GetEnergy(int row, int col) const	{
  int rc = 0;
  int gc = 0;;
  int bc = 0;
  if (col < width_ - 1 && col > 0) {
    rc = image_.GetPixel(row, col - 1).GetRed() - image_.GetPixel(row, col + 1).GetRed();
    gc = image_.GetPixel(row, col - 1).GetGreen() - image_.GetPixel(row, col + 1).GetGreen();
    bc = image_.GetPixel(row, col - 1).GetBlue() - image_.GetPixel(row, col + 1).GetBlue();
  } else if (col == 0) {
    rc = image_.GetPixel(row, width_ - 1).GetRed() - image_.GetPixel(row, col + 1).GetRed();
    gc = image_.GetPixel(row, width_ - 1).GetGreen() - image_.GetPixel(row, col + 1).GetGreen();
    bc = image_.GetPixel(row, width_ - 1).GetBlue() - image_.GetPixel(row, col + 1).GetBlue();
  } else {
    rc = image_.GetPixel(row, col - 1).GetRed() - image_.GetPixel(row, 0).GetRed();
    gc = image_.GetPixel(row, col - 1).GetGreen() - image_.GetPixel(row, 0).GetGreen();
    bc = image_.GetPixel(row, col - 1).GetBlue() - image_.GetPixel(row, 0).GetBlue();
  }
  int rr = 0;
  int gr= 0;
  int br = 0;;
  if (row < height_ - 1 && row > 0) {
    rr = image_.GetPixel(row - 1, col).GetRed() - image_.GetPixel(row + 1, col).GetRed();
    gr = image_.GetPixel(row - 1, col).GetGreen() - image_.GetPixel(row + 1, col).GetGreen();
    br = image_.GetPixel(row - 1, col).GetBlue() - image_.GetPixel(row + 1, col).GetBlue();
  } else if (row == 0) {
    rr = image_.GetPixel(height_ - 1, col).GetRed() - image_.GetPixel(row + 1, col).GetRed();
    gr = image_.GetPixel(height_ - 1, col).GetGreen() - image_.GetPixel(row + 1, col).GetGreen();
    br = image_.GetPixel(height_ - 1, col).GetBlue() - image_.GetPixel(row + 1, col).GetBlue();
  } else {
    rr = image_.GetPixel(row - 1, col).GetRed() - image_.GetPixel(0, col).GetRed();
    gr = image_.GetPixel(row - 1, col).GetGreen() - image_.GetPixel(0, col).GetGreen();
    br = image_.GetPixel(row - 1, col).GetBlue() - image_.GetPixel(0, col).GetBlue();
  }
  int delta_col_2 = (rc*rc) + (gc*gc) + (bc*bc);
  int delta_row_2 = (rr*rr) + (gr*gr) + (br*br);
  return delta_col_2 + delta_row_2;
}
//Helpers
int** SeamCarver::VertEnergyArray() const{
  int** arr = new int*[height_];
  for (int row = 0; row < height_; row++) {
    arr[row] = new int[width_];
  }
  for (int row = 0; row < height_; row++) {
    for (int col = 0; col < width_; col++) {
      arr[row][col] = 0;
    }
  }
  for (int col = 0; col < width_; col++) {
    arr[height_ - 1][col] = GetEnergy(height_ - 1, col);
  }
  for (int row = height_ - 2; row >= 0; row--) {
    for (int col = 0; col < width_; col++) {
      if (col > 0 && col < width_ - 1) {
        if (arr[row + 1][col] <= arr[row + 1][col - 1] && arr[row + 1][col] <= arr[row + 1][col + 1]) {
          arr[row][col] = arr[row + 1][col] + GetEnergy(row, col);
        } else if (arr[row + 1][col - 1] <= arr[row + 1][col] && arr[row + 1][col - 1] <= arr[row + 1][col + 1]) {
          arr[row][col] = arr[row + 1][col - 1] + GetEnergy(row, col);
        } else {
          arr[row][col] = arr[row + 1][col + 1] + GetEnergy(row, col);
        }
      } else if (col == 0) {
        if (arr[row + 1][col] <= arr[row + 1][col + 1]) {
          arr[row][col] = arr[row + 1][col] + GetEnergy(row, col);
        } else {
          arr[row][col] = arr[row + 1][col + 1] + GetEnergy(row, col);
        }
      } else {
        if (arr[row + 1][col] <= arr[row + 1][col - 1]) {
          arr[row][col] = arr[row + 1][col] + GetEnergy(row, col);
        } else {
          arr[row][col] = arr[row + 1][col - 1] + GetEnergy(row, col);
        }
      }
    }
  }
  return arr;
}

int** SeamCarver::HorEnergyArray() const{
  int** arr = new int*[height_];
  for (int row = 0; row < height_; row++) {
    arr[row] = new int[width_];
  }
  for (int row = 0; row < height_; row++) {
    for (int col = 0; col < width_; col++) {
      arr[row][col] = 0;
    }
  }
  for (int row = 0; row < height_; row++) {
    arr[row][width_ - 1] = GetEnergy(row, width_ - 1);
  }
  for (int col = width_ - 2; col >= 0; col--) {
    for (int row = 0; row < height_; row++) {
      if (row > 0 && row < height_ - 1) {
        if (arr[row][col + 1] <= arr[row - 1][col + 1] && arr[row][col + 1] <= arr[row + 1][col + 1]) {
          arr[row][col] = arr[row][col + 1] + GetEnergy(row, col);
        } else if (arr[row - 1][col + 1] <= arr[row][col + 1] && arr[row - 1][col + 1] <= arr[row + 1][col + 1]) {
          arr[row][col] = arr[row - 1][col + 1] + GetEnergy(row, col);
        } else {
          arr[row][col] = arr[row + 1][col + 1] + GetEnergy(row, col);
        }
      } else if (row == 0) {
        if (arr[row][col + 1] <= arr[row + 1][col + 1]) {
          arr[row][col] = arr[row][col + 1] + GetEnergy(row, col);
        } else {
          arr[row][col] = arr[row + 1][col + 1] + GetEnergy(row, col);
        }
      } else {
        if (arr[row][col + 1] <= arr[row - 1][col + 1]) {
          arr[row][col] = arr[row][col + 1] + GetEnergy(row, col);
        } else {
          arr[row][col] = arr[row - 1][col + 1] + GetEnergy(row, col);
        }
      }
    }
  }
  return arr;
}
//Graded
int* SeamCarver::GetHorizontalSeam() const	{
  int* seam = new int[width_];
  int** arr = HorEnergyArray();
  int min = arr[0][0]; seam[0] = 0;
  for (int row = 0; row < height_; row++) {
    if (arr[row][0] < min) {
      min = arr[row][0];
      seam[0] = row;
    }
  }
  int row = seam[0];
  for (int col = 1; col < width_; col++) {
    if (row > 0 && row < height_ - 1) {
      if (arr[row][col] <= arr[row - 1][col] && arr[row][col] <= arr[row + 1][col]) {
        seam[col] = row;
      } else if (arr[row - 1][col] <= arr[row][col] && arr[row - 1][col] <= arr[row + 1][col]) {
        seam[col] = row - 1;
        row--;
      } else {
        seam[col] = row + 1;
        row++;
      }
    } else if (row == 0) {
      if (arr[row][col] <= arr[row + 1][col]) {
        seam[col] = row;
      } else {
        seam[col] = row + 1;
        row++;
      }
    } else {
      if (arr[row][col] <= arr[row - 1][col]) {
        seam[col] = row;
      } else {
        seam[col] = row - 1;
        row--;
      } 
    }
  }
  for (int row = 0; row < height_; row++) {delete[] arr[row];}
  delete[] arr; return seam;
}
int* SeamCarver::GetVerticalSeam() const	{
  int* seam = new int[height_];
  int** arr = VertEnergyArray();
  int min = arr[0][0]; seam[0] = 0;
  for (int col = 0; col < width_; col++) {
    if (arr[0][col] < min) {
      min = arr[0][col];
      seam[0] = col;
    }
  }
  int col = seam[0];
  for (int row = 1; row < height_; row++) {
    if (col > 0 && col < width_ - 1) {
      if (arr[row][col] <= arr[row][col - 1] && arr[row][col] <= arr[row][col + 1]) {
        seam[row] = col;
      } else if (arr[row][col - 1] <= arr[row][col] && arr[row][col - 1] <= arr[row][col + 1]) {
        seam[row] = col - 1;
        col--;
      } else {
        seam[row] = col + 1;
        col++;
      }
    } else if (col == 0) {
      if (arr[row][col] <= arr[row][col + 1]) {
        seam[row] = col;
      } else {
        seam[row] = col + 1;
        col++;
      }
    } else {
      if (arr[row][col] <= arr[row][col - 1]) {
        seam[row] = col;
      } else {
        seam[row] = col - 1;
        col--;
      } 
    }
  }
  for (int row = 0; row < height_; row++) {delete[] arr[row];}
  delete[] arr; return seam;
}
void SeamCarver::RemoveHorizontalSeam()	{
  int* seam = GetHorizontalSeam();
  image_.RemoveHorizontalSeam(seam);
  SetImage(image_);
  delete[] seam;
}
void SeamCarver::RemoveVerticalSeam()	{
  int* seam = GetVerticalSeam();
  image_.RemoveVerticalSeam(seam);
  SetImage(image_);
  delete[] seam;
}
