#include "elevation_dataset.hpp"
#include "grayscale_image.hpp"
#include "color.hpp"
#include "path.hpp"
#include "path_image.hpp"
#include <iostream>

using namespace std;

int main() {
    ElevationDataset test = ElevationDataset("/home/vagrant/src/mp5-mountain-paths-KabillanVasanthan/example-data/ex_input_data/map-input-w51-h55.dat",51,55);
    //std::cout << test.Width() << " " << test.Height() << endl;
    //std::cout << test.MaxEle() << " " << test.MinEle() << endl;
    GrayscaleImage image = GrayscaleImage("/home/vagrant/src/mp5-mountain-paths-KabillanVasanthan/example-data/ex_input_data/map-input-w51-h55.dat",51,55);
    //std::cout << image.Width() << " " << image.Height() << endl;
    //std::cout << image.MaxColorValue() << " " <<  endl; 
    //std::cout << image.ColorAt(0,1).Blue() << " " <<  endl; 
    //Path path = Path(2,0);
    //std::cout << path.EleChange() << " " << path.Length() << " " << std::endl;
    //path.SetLoc(1,1);
    //std::cout << path.GetPath().at(1) << std::endl;

    PathImage pathIm = PathImage(image, test);
    std::cout << pathIm.Paths().at(0).EleChange() << " " << pathIm.Paths().at(1).EleChange() << endl;

    std::cout << pathIm.GetPathImage().at(1).at(2).Red() << endl;

    pathIm.ToPpm("test.ppm");
}