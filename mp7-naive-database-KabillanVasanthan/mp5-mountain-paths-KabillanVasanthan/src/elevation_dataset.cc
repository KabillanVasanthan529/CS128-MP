#include "elevation_dataset.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

ElevationDataset::ElevationDataset(const std::string& filename, size_t width, size_t height) {
    width_ = width;
    height_ = height;
    std::ifstream ifs{filename};
    if(!ifs.is_open()) {
        throw std::exception();
    }
    for(unsigned int i = 0; i < height_; i++) {
        std::vector<int> vec;
        for(unsigned int j = 0; j < width_; j++) {
           vec.push_back(0);
        }
        data_.push_back(vec);
    }
    int temp = 0;
    for(unsigned int i = 0; i < height_; i++) {
        for(unsigned int j = 0; j < width_; j++) {
            ifs >> temp;
            if(ifs.fail()) 
                throw std::runtime_error("ElevationDataset Fail");
            data_.at(i).at(j) = temp;
        }
    }
    ifs >> temp;
    if (!ifs.fail())
        throw std::runtime_error("ElevationDataset Fail");
    int max = data_.at(0).at(0);
    int min = data_.at(0).at(0);
    for(unsigned int i = 0; i < height_; i++) {
        for(unsigned int j = 0; j < width_; j++) {
            if(data_.at(i).at(j) > max) {
                max = data_.at(i).at(j);
            }
            if(data_.at(i).at(j) < min) {
                min = data_.at(i).at(j);
            }
        }
    }
    max_ele_ = max;
    min_ele_ = min;
}
size_t ElevationDataset::Width() const {
    return width_;
}
size_t ElevationDataset::Height() const {
    return height_;
}
int ElevationDataset::MaxEle() const {
    return max_ele_;
}
int ElevationDataset::MinEle() const {
    return min_ele_;
}
int ElevationDataset::DatumAt(size_t row, size_t col) const {
    return data_.at(row).at(col);
}
const std::vector<std::vector<int> >& ElevationDataset::GetData() const {
    return data_;
}
