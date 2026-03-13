#include<iostream>
#include<string>

using namespace std;

// Structs are just like classes, but without methods.

// You can declare some global instances at the end of the defintion

// Notice: If you organize these as string - int - string - int, the struct
//  takes up 8 more bytes.  The struct stores its attributes in 8 byte 
//  chunks, so the 4 byte int between the strings needs 8 bytes, and the int
//  after the strings also would need 8 bytes.  But, if you have string - 
//  string - int - int, C++ fits both ints into a single 8-byte chunk.
struct Student{
    string first_name;
    string last_name;
    int grade_on_lab8;
    int grade_on_lab9;
} emma, michael;

int main() {
    // Or you can declare them in the scope in the usual way.
    // With structs, you also need the keyword struct in C, but not in C++.
    struct Student serena;
    michael.first_name = "Michael";
    michael.last_name = "Sun";
    michael.grade_on_lab8 = 100;
    cout << michael.first_name << " " << michael.last_name << ", Grade on Lab 8: " << michael.grade_on_lab8 << endl;

    cout << sizeof(michael.first_name) << " " << sizeof(michael.last_name) << " " << sizeof(michael) << endl;
}