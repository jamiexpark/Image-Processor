// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <ostream>


void Matrix_init(Matrix* mat, int width, int height) {
    
    mat -> width = width;
    mat -> height = height;

    return;
}
// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
    
    os << mat -> width << " " << mat -> height << std::endl;
    for(int i = 0; i < mat -> width * mat -> height; i++){
        os << mat->data[i] << " ";
        if(i % mat->width == mat->width - 1){
            os << std::endl;
        }
            
}
 //assert(false); // TODO Replace with your implementation!
}

int Matrix_width(const Matrix* mat) {
  
    return mat -> width;
}

int Matrix_height(const Matrix* mat) {
    return mat -> height;
}
// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {

    int mat_row = 0;
    for ( int row = 0; row < Matrix_height(mat); row++){
        for ( int col = 0; col < Matrix_width(mat); col++){
            
            if(ptr == Matrix_at(mat, row, col)){
                return row;
            }
    }
}
    return mat_row;
}

int Matrix_column(const Matrix* mat, const int* ptr) {

//    int col = *ptr % mat -> width;
//    return col;

    
    
    int row_num = Matrix_row(mat, ptr);
    int count = static_cast<int>(ptr - mat->data);
    int width = Matrix_width(mat);
    return count - (row_num * width);
    
  //assert(false); // TODO Replace with your implementation!
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {

    int pos = row * mat->width + column;
    return &mat -> data[pos];
    
    //assert(false);
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
    
    
    int pos = row * mat->width + column;
    return &mat -> data[pos];
    
    
    
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
    
    for(int r = 0; r < mat->width * mat->height; r++){
        mat ->data[r] = value ;
    }

  
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
    for(int i = 0; i < mat -> width * mat -> height; i++){
        if(i < mat -> width || i > mat -> width * (mat -> height - 1)){
            mat -> data[i] = value;
        }
        else if(i % mat -> width == 0 || i % mat -> width == mat -> width - 1){
            mat -> data[i] = value;
        }
    }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
    int temp = -9999;
    for(int i = 0; i < mat -> width * (mat-> height); i++){
        if(mat -> data[i] > temp){
            temp = mat -> data[i];
        }
    }
    return temp;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) {
    int temp = 999999999;
    int colIndex = 0;
    for(int i = row * mat->width + column_start;
        i < row * mat->width + column_end; i++){
        if(mat -> data[i] < temp){
            temp = mat -> data[i];
            colIndex = i - row * mat->width;
        }
    }
     if(temp > mat->data[row * mat->width + column_end]){
      temp = mat->data[row * mat->width + column_end];
      colIndex = column_end;
     }
    return colIndex;
        
}

  //assert(false); // TODO Replace with your implementation!

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
    int temp = 99999999;
    for( int i = row * mat->width + column_start;
        i < row * mat->width + column_end; i++){
        if(mat->data[i] < temp){
            temp = mat->data[i];
        }
//last one was not being checked. code below checks it
    }
    if(temp > mat->data[row * mat->width + column_end]){
      temp = mat->data[row * mat->width + column_end];
    }
    return temp;
         
}
 // assert(false); // TODO Replace with your implementation!



 
        


