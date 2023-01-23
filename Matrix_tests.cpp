// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }
  
  delete mat; // delete the Matrix
}


// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

TEST(test_1) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 2;
  const int height = 3;
  const int value = 2;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

TEST(test_matrix_print) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  std::ostream &os = std::cout;
  const int value = 2;
  Matrix_init(mat, 2, 2);
  Matrix_fill(mat, value);
    Matrix_print(mat, os);
   
    ostringstream actual;
     Matrix_print(mat, actual);
    
    ostringstream correct;
    correct <<  "2 2\n2 2 \n2 2 \n";
 
    ASSERT_EQUAL(correct.str(), actual.str());

  delete mat; // delete the Matrix
}



TEST(test_matrix_row) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memor
  const int value = 2;
  Matrix_init(mat, 500, 500);
  Matrix_fill(mat, value);
    const int* ptr = Matrix_at(mat, 300, 200);
//    int a = 6;
//    int *ptr = &a;
    ASSERT_EQUAL(Matrix_row(mat, ptr), 300);


  delete mat; // delete the Matrix
}

//TEST(test_matrix_fill_border) {
//  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
//  // std::ostream &os = std::cout;
//
//  const int width = 6;
//  const int height = 7;
//  const int value = 0;
//  Matrix_init(mat, width, height);
//  Matrix_fill(mat, 2);
//  Matrix_fill_border(mat, value);
//  ostringstream actual;
//  Matrix_print(mat, actual);
//
//    ostringstream correct;
//  
//    correct << "6 7\n";
//    correct << "0 0 0 0 0 0 \n";
//    correct << "0 2 2 2 2 0 \n";
//    correct << "0 2 2 2 2 0 \n";
//    correct << "0 2 2 2 2 0 \n";
//    correct << "0 2 2 2 2 0 \n";
//    correct << "0 2 2 2 2 0 \n";
//    correct << "0 0 0 0 0 0 ";
//
// ASSERT_EQUAL(correct.str(), actual.str());
// 
//
//  delete mat; // delete the Matrix
//}

TEST(test_matrixcolumnofminvalinrow) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  std::ostream &os = std::cout;
  const int value = 4;
  Matrix_init(mat, 3, 3);
  Matrix_fill(mat, value);
  Matrix_print(mat, os);
  int actual = Matrix_column_of_min_value_in_row(mat, 1, 1, 2);
  int correct = 1;
    
 
  assert(actual == correct);
    delete mat;
  //delete mat; // delete the Matrix
}

TEST(test_matrixminvalue_in_row) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  std::ostream &os = std::cout;
  const int value = 4;
  Matrix_init(mat, 5, 5);
    cout << "this is matrix at " << endl;
   
    Matrix_fill(mat, value);
    int *ptr = Matrix_at(mat, 1, 2);
    *ptr = 1;
    cout << *Matrix_at(mat, 1, 2) << endl;
//    mat->data[2] = 2;
//    mat->data[3] = 2;
//    mat->data[4] = 2;
//    mat->data[5] = 2;
//    mat->data[6] = 2;
   // int a = 6;
   // int *ptr = &a;
    //*Matrix_at(mat, 1, 2);


    Matrix_print(mat, os);

    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 2, 5), 1);
    
 
 //assert(actual == correct);

  delete mat; // delete the Matrix
}


TEST(matrix_columnofminval2){
    Matrix *mat = new Matrix; // create a Matrix in dynamic memory
    std::ostream &os = std::cout;
    const int value = 4;
    Matrix_init(mat, 2, 2);
      cout << "this is matrix at " << endl;
     
      Matrix_fill(mat, value);
      int *ptr = Matrix_at(mat, 1, 3);
      *ptr = 1;
      cout << *Matrix_at(mat, 1, 3) << endl;
    
    Matrix_print(mat, os);

    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 1, 3), 2);
}





// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here

