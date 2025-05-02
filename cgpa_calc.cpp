//CGPA Grade Calculator
#include <bits/stdc++.h>
using namespace std;

int gradeToPoint(string grade) {
    unordered_map<string,int> gradeMap = {
        {"A+", 10}, {"A", 9}, {"B+", 8}, {"B", 7},
        {"C+", 6}, {"C", 5}, {"D", 4}, {"F", 0}
    };
    if (gradeMap.find(grade) != gradeMap.end()) {
        return gradeMap[grade];
    }
    return 0;
}

int main() {
    int numCourses;
    cout<<"Enter number of courses: ";
    cin>>numCourses;
    double totalCredits=0,totalGradePoints=0;
    for (int i=0;i<numCourses;++i) {
        string courseName,grade;
        double credit;
        cout<<"Enter course "<<i+1<<" name: ";
        cin>>ws;
        getline(cin,courseName);
        cout<<"Enter credits for "<<courseName<< ": ";
        cin>>credit;
        cout<<"Enter grade for " <<courseName << ": ";
        cin >> grade;
        int point = gradeToPoint(grade);
        totalCredits += credit;
        totalGradePoints += point * credit;
        cout<<courseName<<": Grade = " <<grade<< ", Credit = " << credit << endl;
    }

    if (totalCredits==0) {
        cout<<"Total credits cannot be zero."<<endl;
    } else {
        double cgpa = totalGradePoints / totalCredits;
        cout<<fixed<<setprecision(2);
        cout<<"Total Credits: " <<totalCredits << endl;
        cout <<"Total Grade Points: " <<totalGradePoints << endl;
        cout << "CGPA: "<<cgpa << endl;
    }
    return 0;
}
