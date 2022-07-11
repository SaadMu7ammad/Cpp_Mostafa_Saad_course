#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Time {
private:
	//int hours, minutes, seconds; these members replaced with only tot (total seconds)
	int tot;
public:
	Time(int tot) :tot(tot) {}
	int GetTotalSeconds() {
		return tot;
	}
	int GetTotalMinutes() {
		return tot / 60;
	}
	void PrintHHMMSS() {
		cout << GetHours() << ":" << GetMinutes() << ":" << GetSeconds() << "\n";
	}
	string ToSring(string seperator = "-") {
		ostringstream oss;
		oss << GetHours() << seperator << GetMinutes() << seperator << GetSeconds();
		return oss.str();
	}
	int GetHours() {
		return tot/3600;
	}
	int GetMinutes() {
		return (tot-(GetHours()*3600))/60;
	}
	int GetSeconds() {
		//return (tot - ((GetMinutes()*60) +(GetHours()* 3600))); 
		// simple way
		return (tot %60);
	}
};
int main() {
	Time t(4000);
	t.PrintHHMMSS();
	cout << "--" << endl;
	  t= Time(4001);
	t.PrintHHMMSS();
	cout<<t.ToSring("//");
	return 0;
}
