/** Name: Kendrick Chu
 UCLA ID: 004136504
 Date: 5/27/16
 @File:  This assignment was used to have us use iterators to modify an existing binary search tree that was provided in the book.  In this assignment, I modified the binary search tree to store an int data value and included functions that would get the smallest and largest value of the binary search tree.  A bidirectional iterator was also implemented containing the functions begin(), end(), and appropriate operators overloaded for the iterator.  Parent nodes were added to the TreeNodes and the erase and insert functions were modified.  I also modified the destructor to make sure that my code wouldn't create any memory leaks.  The code has been templated and modified with another Point2D class.  The code has been further updated to use move semantics for the BinarySearchTree class.  A move constructor was created and both the copy and move constructors print out statements to the console to confirm their use.
 */




#include "BinarySearchTree.h"
#include "PointOrder.h"
#include <string>

int main() {
    //Create binary search tree, give it values {2,3,5,11,13,17}
    BinarySearchTree<int> bst;
    bst.insert(3);
    bst.insert(2);
    bst.insert(11);
    bst.insert(13);
    bst.insert(5);
    bst.insert(17);
    
    //Prints to the console: 2,3,5,11,13,17,
    for (auto x : bst) std::cout << x << ",";
    std::cout << std::endl;
    
    //Prints to the console: Copy made
    BinarySearchTree<int> deep_copy(bst);
    
    //Prints to the console: Move performed
    BinarySearchTree<int> moved_copy(std::move(bst));
    
    BinarySearchTree<int> default_bst;
    
    //Prints to the console: Copy made
    default_bst = deep_copy;
    
    //Prints to the console: Move performed
    default_bst = std::move(moved_copy);
    
    BinarySearchTree<Point2D, PointOrderx> points_by_x;
    points_by_x.insert(Point2D(1, 2));
    points_by_x.insert(Point2D(7, 3));
    points_by_x.insert(Point2D(2, 1));
    
    //Prints to the console: (1,2),(2,1),(7,3),
    for (auto x : points_by_x) std::cout << x << ",";
    std::cout << std::endl;
    
    //Prints to the console: Copy made
    auto points_x_deep_copy(points_by_x);
    
    //Prints to the console: Move performed
    auto points_x_moved_copy(std::move(points_by_x));
    
    BinarySearchTree<Point2D, PointOrderx> points_x_default_bst;
    
    //Prints to the console: Copy made
    points_x_default_bst = points_x_deep_copy;
    
    //Prints to the console: Move performed
    points_x_default_bst = std::move(points_x_moved_copy);
    
    BinarySearchTree<Point2D, PointOrdery> points_by_y;
    points_by_y.insert(Point2D(1, 2));
    points_by_y.insert(Point2D(7, 3));
    points_by_y.insert(Point2D(2, 1));
    
    //Prints to the console: (2,1),(1,2),(7,3),
    for (auto x : points_by_y) std::cout << x << ",";
    std::cout << std::endl;
    
    //Prints to the console: Copy made
    auto points_y_deep_copy(points_by_y);
    
    //Prints to the console: Move performed
    auto points_y_moved_copy(std::move(points_by_y));
    
    BinarySearchTree<Point2D, PointOrdery> points_y_default_bst;
    
    //Prints to the console: Copy made
    points_y_default_bst = points_y_deep_copy;
    
    //Prints to the console: Move performed
    points_y_default_bst = std::move(points_y_moved_copy);
    
    BinarySearchTree<std::string, std::greater<std::string>> names;
    names.insert("Luke");
    names.insert("Kanye");
    names.insert("Pentatonix");
    
    //Prints to the console: Pentatonix, Luke, Kanye
    for (auto x : names) std::cout << x << ",";
    std::cout << std::endl;
    
    //Prints to the console: Copy made
    auto names_deep_copy(names);
    
    //Prints to the console: Move performed
    auto names_moved_copy(std::move(names));
    
    BinarySearchTree<std::string, std::greater<std::string>> names_default_bst;
    
    //Prints to the console: Copy made
    names_default_bst = names_deep_copy;
    
    //Prints to the console: Move performed
    names_default_bst = std::move(names_moved_copy);
    
    return 0;
}