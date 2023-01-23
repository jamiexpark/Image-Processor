// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "Image.h"
#include "Matrix.h"
#include "processing.h"

using namespace std;

int main(int argc, char **argv){
    Image* img = new Image;
    if(argc == 4){
        string filename = argv[1];
        string fileout = argv[2];
        int width = stoi(argv[3]);
        
     //   load_image(img, filename + ".ppm");
        ifstream fin;
        fin.open(filename.c_str());

        if (!fin.is_open()){
          cout << "Error opening file: " << filename << endl;
          exit(EXIT_FAILURE);
        }

        Image_init(img, fin);

        if (Image_width(img) < width || width < 0){
             cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                  << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        }

        cout << Image_height(img) << endl;
        seam_carve(img, width, Image_height(img));
        ofstream fout(fileout.c_str());
        Image_print(img, fout);
    }else if(argc == 5){
        string filename = argv[1];
        string fileout = argv[2];
        int width = stoi(argv[3]);
        int height = stoi(argv[4]);
     //   load_image(img, filename + ".ppm");
        ifstream fin;
        fin.open(filename.c_str());

        if (!fin.is_open()){
          cout << "Error opening file: " << filename << endl;
          exit(EXIT_FAILURE);
        }

        Image_init(img, fin);
        
        if (Image_width(img) < width || width < 0){
             cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                  << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        }
        if (Image_height(img) < height || height < 0){
             cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                  << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        }
        seam_carve(img, width, height);
        ofstream fout(fileout.c_str());
        Image_print(img, fout);
    
    }else{
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        
    }
    delete img;
}




