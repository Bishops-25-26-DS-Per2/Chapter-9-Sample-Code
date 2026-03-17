#include<iostream>
#include<string>

using namespace std;

class Project;

class Student {
    // Attributes & methods are private by default
    public:
        // Attributes
        string first_name;
        string last_name;
        Project* proj_1;
        Project* proj_2;
        // Methods
        // default constructor
        Student();
        Student(string first_name, string last_name);
        void add_project();
// Don't forget the semicolon
};

class Project{
    public:
        // Attributes
        string name;
        int score;
        // Methods
        Project();
        Project(string name, int score);
};

// class_name::method_name(args) {}
Student::Student() {
    // Initialize all attributes.  Inside the method, you can 
    //  access names of attributes as variables.
    first_name = "";
    last_name = "";
    proj_1 = NULL; // or nullptr
    proj_2 = NULL;
}

// This is an overloaded function: It is a second definition of
//  the constructor with different arguments.  Both def'ns are valid.
// C++ is less ok with the same name for the arg and the attribute.
Student::Student(string new_first_name, string new_last_name) {
    first_name = new_first_name;
    last_name = new_last_name;
    proj_1 = NULL; 
    proj_2 = NULL;
}

// If you do this, the proj_1 variable goes out of scope when the 
//  method finishes.
void Student::add_project() {
    Project* proj_1 = new Project;
    this -> proj_1 = proj_1;
    cout << "Add project: " << this -> proj_1 << endl;
    proj_1 -> name = "This Project.";
    proj_1 -> score = 100;
    cout << "Name: " << this -> proj_1 -> name << " Score: " << this -> proj_1 -> score << endl;
}

Project::Project() {
    name = "";
    score = 0;
}

// Other solution to the problem of matching attr name & arg name
Project::Project(string name, int score) {
    // this keyword is automatically a pointer to the instance
    this -> name = name;
    this -> score = score;
}

int main() {
    Student jackson("Jackson", "Weisser");
    // Project proj_1("Binary Numbers", 100);
    // jackson.proj_1 = &proj_1;
    cout << jackson.first_name << " " << jackson.last_name << endl;
    // Use -> notation because proj_1 is a pointer to the instance
    // cout << jackson.proj_1 -> name << " " << jackson.proj_1 -> score << endl;
    // But now the proj_1 object has gone out of scope
    jackson.add_project();
    cout << jackson.proj_1 << endl;
    cout << "Name: " << jackson.proj_1 -> name << " Score: " << jackson.proj_1 -> score << endl;
    // Free up the memory allocated to proj_1
    delete jackson.proj_1;
    cout << jackson.proj_1 << endl;
    // Since proj_1 object was de-allocated, these will give bad info
    //  or segmentation faults.
    cout << "Name: " << jackson.proj_1 -> name << " Score: " << jackson.proj_1 -> score << endl;

}