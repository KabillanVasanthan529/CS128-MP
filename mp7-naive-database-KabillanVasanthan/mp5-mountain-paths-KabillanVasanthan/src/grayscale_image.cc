#include "grayscale_image.hpp"
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>

GrayscaleImage::GrayscaleImage(const ElevationDataset& dataset) {
    width_ = dataset.Width();
    height_ = dataset.Height();
    for(unsigned int i = 0; i < height_; i++) {
        std::vector<Color> vec;
        for(unsigned int j = 0; j < width_; j++) {
           vec.push_back(Color(0,0,0));
        }
        image_.push_back(vec);
    }
    for(unsigned int i = 0; i < dataset.Height(); i++) {
        for (unsigned int j = 0; j < dataset.Width(); j++) {
            if(dataset.MaxEle() - dataset.MinEle() == 0) {
                image_.at(i).at(j) = Color(0,0,0);
            } else {
                int col = static_cast<int>(std::round((dataset.DatumAt(i,j)*1.0 - dataset.MinEle()*1.0) / (dataset.MaxEle()*1.0 - dataset.MinEle()*1.0) * kMaxColorValue));
                image_.at(i).at(j) = Color(col,col,col);
            }
        }
    }
}
GrayscaleImage::GrayscaleImage(const std::string& filename, size_t width, size_t height) : width_(width), height_(height) {
    std::ifstream ifs{filename};
    if(!ifs.is_open()) 
        throw std::exception();
    std::vector<vector<int>> elevs;
    int temp = 0;
    for (unsigned int i = 0; i < height_; i++) {
        std::vector<int> vec;
        for (unsigned int j = 0; j < width_; j++) {
            ifs >> temp;
            if(ifs.fail()) 
                throw std::runtime_error("ElevationDataset Fail");
            vec.push_back(temp);
        }
        elevs.push_back(vec);
    }
    int max = elevs.at(0).at(0);
    int min = elevs.at(0).at(0);
    for(unsigned int i = 0; i < height_; i++) {
        for(unsigned int j = 0; j < width_; j++) {
            if(elevs.at(i).at(j) > max) 
                max = elevs.at(i).at(j);
            if(elevs.at(i).at(j) < min) 
                min = elevs.at(i).at(j);
        }
    }
    for(unsigned int i = 0; i < height_; i++) {
        std::vector<Color> vec;
        for(unsigned int j = 0; j < width_; j++) {
           vec.push_back(Color(0,0,0));
        }
        image_.push_back(vec);
    }
    for(unsigned int i = 0; i < height_; i++) {
        for(unsigned int j = 0; j < width_; j++) {
            int col = static_cast<int>(std::round((elevs.at(i).at(j)*1.0 - min*1.0) / (max*1.0 - min*1.0) * kMaxColorValue));
            image_.at(i).at(j) = Color(col,col,col);
        }
    }
}
size_t GrayscaleImage::Width() const {
    return width_;
}
size_t GrayscaleImage::Height() const {
    return height_;
}
unsigned int GrayscaleImage::MaxColorValue() const {
    return kMaxColorValue;
}
const Color& GrayscaleImage::ColorAt(int row, int col) const {
    return image_.at(row).at(col);
}
const std::vector<std::vector<Color> >& GrayscaleImage::GetImage() const {
    return image_;
}
void GrayscaleImage::ToPpm( const std::string& name ) const {
    std::ofstream ofs{name};
    if (!ofs.is_open()) {
        throw std::exception();
    }
    ofs << "P3" << std::endl;
    ofs << width_ << " " << height_ << std::endl;
    ofs << MaxColorValue() << std::endl;
    for(unsigned int i = 0; i < height_; i++) {
        for(unsigned int j = 0; j < width_; j++) {
            ofs << image_.at(i).at(j).Red() << " ";
            ofs << image_.at(i).at(j).Green() << " ";
            ofs << image_.at(i).at(j).Blue() << " ";
        }
        ofs << std::endl;
    }
    ofs << std::endl;
 
}
