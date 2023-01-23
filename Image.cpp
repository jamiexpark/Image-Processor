// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
  assert(height <= MAX_MATRIX_HEIGHT);
  assert(width <= MAX_MATRIX_WIDTH);
  assert(height > 0);
  assert(width > 0);
  img->height = height;
  img->width = width;
  Matrix_init(&img->red_channel, width, height);
  Matrix_init(&img->green_channel, width, height);
  Matrix_init(&img->blue_channel, width, height);
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
  int r;
  int g;
  int b;
  int height;
  int width;
  string p3 = "";
  int ifintensity;

  is >> p3 >> width >> height >> ifintensity;
  
  assert(ifintensity == MAX_INTENSITY);
  assert(height <= MAX_MATRIX_HEIGHT);
  assert(width <= MAX_MATRIX_WIDTH);
  assert(height > 0);
  assert(width > 0);

  img->width = width;
  img->height = height;
  Matrix_init(&img->red_channel, width, height);
  Matrix_init(&img->green_channel, width, height);
  Matrix_init(&img->blue_channel, width, height);

  for(int row = 0; row < Image_height(img); ++row){
    for(int column = 0; column < Image_width(img); ++column){
        is >> r >> g >> b;
        int *red_ptr = Matrix_at(&img->red_channel, row, column);
        int *green_ptr = Matrix_at(&img->green_channel, row, column);
        int *blue_ptr = Matrix_at(&img->blue_channel, row, column);
        *red_ptr = r;
        *green_ptr = g;
        *blue_ptr = b;
    }
    assert(height > 0);
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  os << "P3\n";
  os << Image_width(img)<< " " << Image_height(img) << "\n";
  os << "255" << "\n";

  for(int row = 0; row < Image_height(img); ++row){
    for(int column = 0; column < Image_width(img); ++column){
        
        int const *red_ptr = Matrix_at(&img->red_channel, row, column);
        int const *green_ptr = Matrix_at(&img->green_channel, row, column);
        int const *blue_ptr = Matrix_at(&img->blue_channel, row, column);
        os << *red_ptr << " "
           << *green_ptr << " "
           << *blue_ptr << " ";
    }
    os << "\n";
  }
    
    
  
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  return img->width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  return img->height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  assert(row <= img->height);
  assert(column <= img->width);
  assert(row >= 0);
  assert(column >= 0);

  
    Pixel imgPixel = Pixel();
  imgPixel.r = *(Matrix_at(&img->red_channel, row, column));
  imgPixel.g = *(Matrix_at(&img->green_channel, row, column));
  imgPixel.b = *(Matrix_at(&img->blue_channel, row, column));
  return imgPixel;
    
  
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  assert(row < img->height);
  assert(column < img->width);
  assert(row >= 0);
  assert(column >= 0);
  // change stuff in mem to color
  int* temp;
    int *red_ptr = Matrix_at(&img->red_channel, row, column);
    int *green_ptr = Matrix_at(&img->green_channel, row, column);
    int *blue_ptr = Matrix_at(&img->blue_channel, row, column);

    
  int r = (color.r);
  temp = (Matrix_at(&img->red_channel, row, column));
  temp = &r;
  *red_ptr = *temp;

  int g = (color.g);
  temp = (Matrix_at(&img->green_channel, row, column));
  temp = &g;
  *green_ptr = *temp;

  int b = (color.b);
  temp = (Matrix_at(&img->blue_channel, row, column));
  temp = &b;
  *blue_ptr = *temp;
}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  Matrix_fill(&img->red_channel, color.r);
  Matrix_fill(&img->green_channel, color.g);
  Matrix_fill(&img->blue_channel, color.b);
    
}


