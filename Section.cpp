#include "Section.h"
Section::Section()
{
    courseID = "XXXX";
    studentsCount = 3;
    studentsIDs = new string[studentsCount];
}
Section::Section(string ID, int count)
{
    courseID = ID;
    studentsCount = count;
    studentsIDs = new string[studentsCount];
}
Section::~Section()
{
    delete[] studentsIDs;
}
void Section::setcount(int sc) {
    studentsCount = sc;
}
int Section::getcount() {
    return studentsCount;
}
void Section::setCourseID(string ID)
{
    courseID = ID;
}
string Section::getCourseID()
{
    return courseID;
}
void Section::setStudentID(string ID, int studentIndex)
{
    *(studentsIDs + studentIndex) = ID;
}
string Section::getStudentID(int studentIndex)
{
    return *(studentsIDs + studentIndex);
}
void Section::printData()
{
    cout << courseID << " has " << studentsCount << " students enrolled, whose IDs are ( ";
    for (int i = 0; i < studentsCount; i++)
        cout << *(studentsIDs + i) << " ";
    cout << ")";
}
bool Section::operator >(const Section& bigger) {
    return (this->studentsCount > bigger.studentsCount);
}
bool Section::operator <=(const Section& smaller) {
    return (this->studentsCount <= smaller.studentsCount);
}
string Section::operator[](const int& index) {
    if (index >= studentsCount) {
        cout << "index is out of range" << endl;
    }
    else return *(studentsIDs + index);
}
bool Section::operator ==(const Section& equal) {
    return (this->studentsCount == equal.studentsCount);
}
Section Section::operator+(const Section& plus) {

    if (studentsCount == plus.studentsCount) {
        Section newsection(courseID, studentsCount+ plus.studentsCount);
        for (int i = 0; i < studentsCount; i++) {
            newsection.setStudentID(*(studentsIDs + i), i);
        }
        for (int i = studentsCount; i < newsection.studentsCount; i++) {
            newsection.setStudentID(*(plus.studentsIDs + i), i);
        }
        return newsection;
    }
    else return plus;
}
int main() {
    Section CsHowaida1("cs033", 4), CsAmr("cs044", 30), CsHowaida2("cs033", 7);
    Section CsHowaida3("cs033", 4);
    CsHowaida1.setStudentID("123", 1);
    CsHowaida1.setStudentID("456", 2);
    cout << "first student Id in cs1 is: " << CsHowaida1[1] << "\n";
    CsAmr.printData();
    cout << endl;
    if (CsHowaida1 == CsHowaida3)
        cout << "Yes, they are equal\n";
    if (CsHowaida1 <= CsAmr)
        cout << "Cs with howaida has less or equal students \n";
    if (CsHowaida2 > CsHowaida1)
        cout << "section 2 has more students than section 1 \n";
}
