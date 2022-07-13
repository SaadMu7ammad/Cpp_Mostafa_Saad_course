#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int statistics_total_prints = 0;
class StudentGradesInfo {
private:
	string student_id;
	/*vector<double> grades;
	vector<string> courses_names;*/
	map<string, double>mp;
public:
	StudentGradesInfo() {
		assert(false);
	}
	StudentGradesInfo(string name_, string student_id_) {
		student_id = student_id_;
	}
	int AdjustGrade(double grade) {
		if (grade < 0)
			return grade;
		if (grade > 100)
			return 100;
		return grade;
	}
	bool AddGrade(double grade, string course_name) {
		grade = AdjustGrade(grade);
		mp[course_name] = grade; return true;
	}
	void PrintAllCourses() {
		++statistics_total_prints;
		cout << "Grades for student: " << student_id << "\n";
		for (auto& it : mp)
			cout << "\t" << it.first << " = " << it.second << "\n";
	}
	pair<string, double> GetCourseGradeInfo(string cors_name){
		if (mp.find(cors_name) != mp.end()) {
		return make_pair(cors_name, mp[cors_name]);
}
	else {
			return make_pair("", -1);
			}
		}
	string GetStudentId() {
		return student_id;
	}
	int GetTotalCoursesCount() {
		return mp.size();
	}
	pair<double, double> get_total_gradesSum() {
		double sum = 0, total = 0;
		for (auto& it : mp)
			sum += it.second, total += 100;
		return make_pair(sum, total);
	}
};
int main() {
	StudentGradesInfo st1("Mostafa", "S000123");
	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");
	st1.AddGrade(99, "programming 2");
	st1.PrintAllCourses();

cout << "---\n";
pair<string, double> pst1=st1.GetCourseGradeInfo("programming 2");
cout << pst1.first << " : " << pst1.second << "\n";

cout << "---\n";
pair<double, double> p = st1.get_total_gradesSum();
cout << p.first << "/" << p.second << "\n";

	cout << "Bye\n";

	return 0;
}
