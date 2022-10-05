#pragma once
#include <iostream>
#include <string>
using namespace std;
class Section
{
private:
    string courseID;
    int studentsCount;
    string* studentsIDs;
public:
    void setcount(int sc);
    int getcount();
    Section();
    Section(string ID, int count);
    ~Section();
    void setCourseID(string ID);
    string getCourseID();
    void setStudentID(string ID, int studentIndex);
    string getStudentID(int studentIndex);
    void printData();

    bool operator >(const Section& bigger);
    bool operator <=(const Section& smaller);
    string operator[](const int& index);
    bool operator ==(const Section& equal);
    Section operator+ (Section const& a);
};

