// CGPA Calculator
// Take input for the number of courses taken by the student.
// ● For each course, input the grade and the credit hours.
// ● Calculate the total credits and total grade points (grade × credit hours).
// ● Compute the GPA for the semester and then the overall CGPA.
// ● Display individual course grades and the final CGPA to the user.

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Students{

public:

    int creditHours;
    int grades;

int inputCreditHours(int &subjectNumber){
    cout<<"Enter Credit Hours of Subject "<<subjectNumber + 1<<" : ";
    cin>>creditHours;
    return 0;
}

int inputGrades(int &subjectNumber){
    cout<<"Enter Grades of Subject "<<subjectNumber + 1<<" : ";
    cin>>grades;
    return 0;
}
};

int inputValues(vector<Students> &students,int &subjectNumber){
    for(int i=0;i<subjectNumber;i++){
        students[i].inputCreditHours(i);
        students[i].inputGrades(i);
    }
    return 0;
}

int resultCalculation(vector<Students> &students,int &subjectNumber, int &totalCredit, float &totalGradePoints){
    for(int i=0;i<subjectNumber;i++){
        totalCredit = totalCredit + students[i].creditHours;
        totalGradePoints = totalGradePoints + (students[i].grades * students[i].creditHours);
    }
    return 0;
}

int resultPerSubject(vector<Students> &students,int &subjectNumber){
    for(int i=0;i<subjectNumber;i++){
        cout<<"Subject "<<i + 1 
            << " | " << "Grade : " << students[i].grades 
            << " | "<<"Credits : " << students[i].creditHours
            << " | "<<"Grade Points : "<<students[i].grades * students[i].creditHours<<endl<<endl;
    }
    return 0;
}

int mainOutput(int &totalCredit, float &totalGradePoints){
     cout<<"Total Credits : "<<totalCredit<<endl;
     cout<<"Total Grade Points : "<<totalGradePoints<<endl;
     float total_cgpa = totalGradePoints / totalCredit;
     cout<<fixed;
     cout<<setprecision(2);
     cout<<"Total CGPA : "<<total_cgpa<< endl;
     return 0;
}

int main(){
    int subjectNumber;
    cout<<"Please Enter Number of Subjects : ";
    cin>>subjectNumber;
    int totalCredit = 0;
    float totalGradePoints = 0;

    vector<Students>students(subjectNumber);

    inputValues(students, subjectNumber);
    resultCalculation(students, subjectNumber,totalCredit,totalGradePoints);
    cout<<endl<<"---------- Subject Wise Result ----------"<<endl<<endl;
    resultPerSubject(students, subjectNumber);
    mainOutput(totalCredit,totalGradePoints);
    
    return 0;
    
}