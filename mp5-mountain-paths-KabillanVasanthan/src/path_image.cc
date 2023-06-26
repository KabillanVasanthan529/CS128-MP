#include "path_image.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

PathImage::PathImage(const GrayscaleImage &image, const ElevationDataset &dataset) : width_(dataset.Width()), height_(dataset.Height()){
    Color temp;
    for (int i = 0; i < (int) height_; i++) {
        std::vector<Color> vec;
        for (int j = 0; j < (int) width_; j++) {
            temp = image.ColorAt(i,j);
            vec.push_back(temp);
        }
        path_image_.push_back(vec);
    }
    for (unsigned int i = 0; i < height_; i++) {
        Path temp = Path(width_, i); int current = dataset.DatumAt(i,0);
        unsigned int row = i;
        for (unsigned int j = 0; j < width_ - 1; j++) {
            int num1 = 0;
            if (row > 0) 
                num1 = dataset.DatumAt(row-1,j+1);
            int num2 = dataset.DatumAt(row, j+1);
            int num3 = 0;
            if (row + 1 < height_)
                num3 = dataset.DatumAt(row+1,j+1);
            if (std::abs(num2 - current) <= std::abs(num3 - current) && std::abs(num2 - current) <= std::abs(num1 - current)) {
                temp.SetLoc(j+1,row);
                temp.IncEleChange((unsigned int) std::abs(num2 - current));
                current = num2;
            } else if (std::abs(num3 - current) <= std::abs(num1 - current) && std::abs(num3 - current) <= std::abs(num2 - current)) {
                temp.SetLoc(j+1,row+1);
                temp.IncEleChange((unsigned int) std::abs(num3 - current));
                current = num3;
                row = row + 1;
            } else {
                temp.SetLoc(j+1,row-1);
                temp.IncEleChange((unsigned int) std::abs(num1 - current));
                current = num1; 
                row = row - 1;              
            } 
        }
        paths_.push_back(temp);
    }
    Paint();
}
size_t PathImage::Width() const {
    return width_;
}
size_t PathImage::Height() const {
    return height_;
}
unsigned int PathImage::MaxColorValue() const {
    return kMaxColorValue;
}  
const std::vector<Path>& PathImage::Paths() const {
    return paths_;
}
const std::vector<std::vector<Color> >& PathImage::GetPathImage() const {
    return path_image_;
}
void PathImage::Paint() {
    unsigned int least = Paths().at(0).EleChange();
    unsigned int green = 0;
    for (unsigned int i = 0; i < Paths().size(); i++) {
        if (Paths().at(i).EleChange() < least) {
            least = Paths().at(i).EleChange();
            green = Paths().at(i).StartingRow();
        }
    }
    static constexpr int kG1 = 31;
    static constexpr int kG2 = 253;
    static constexpr int kG3 = 13;
    static constexpr int kR1 = 252;
    static constexpr int kR2 = 25;
    static constexpr int kR3 = 63;
    for (unsigned int i = 0; i < Paths().size(); i++) {
        for(unsigned int j = 0; j < Paths().at(i).Length(); j++) {
            path_image_.at(Paths().at(i).GetPath().at(j)).at(j) = Color(kR1,kR2,kR3);
        }
    }
    for (unsigned int i = 0; i < Paths().size(); i++) {
        if(i == green) {
            for(unsigned int j = 0; j < Paths().at(i).Length(); j++) {
                path_image_.at(Paths().at(i).GetPath().at(j)).at(j) = Color(kG1,kG2,kG3);
            }
        }
    }
}
void PathImage::ToPpm(const std::string& name) const {
    std::ofstream ofs{name};
    if (!ofs.is_open()) {
        throw std::exception();
    }
    ofs << "P3" << std::endl;
    ofs << width_ << " " << height_ << std::endl;
    ofs << MaxColorValue() << std::endl;
    for(unsigned int i = 0; i < height_; i++) {
        for(unsigned int j = 0; j < width_; j++) {
            ofs << path_image_.at(i).at(j).Red() << " ";
            ofs << path_image_.at(i).at(j).Green() << " ";
            ofs << path_image_.at(i).at(j).Blue() << " ";
        }
        ofs << std::endl;
    }
    ofs << std::endl;
}
