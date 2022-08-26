#include<vector>
#include<string>
#include<string>
#include<map>
#include<iomanip>
#include <iostream>
#include<fstream>
#include <sstream>
#include<set>
using namespace std;
class Date {
public:
    Date(int year1, int month1, int day1) {
        year = year1;
        month = month1;
        day = day1;
    }
    int getY() {
        return year;
    }
    int getM() {
        return month;
    }
    int getD() {
        return day;
    }
  
private:
    int year;
    int month;
    int day;
};
bool checkMonth(int month0) {
    if (month0 > 12) {
        return 0;
    }
    return 1;
}
bool checkDay(int day0) {
    if (day0 > 31) {
        return 0;
    }
    return 1;
}
Date Parse(const string& date) {
    istringstream dates(date);
    int y;
    dates >> y;
    if (dates.peek() == '-') {
        dates.ignore(1);
    }
    else {
        cout << "Wrong date format: " + date;
    }
    int m;
    dates >> m;
    if (dates.peek() == '-') {
        dates.ignore(1);
    }
    else {
        cout << "Wrong date format: " + date;
    }
    int d;
    dates >> d;
    if (dates.eof()) {
        if (checkDay(d) && checkMonth(m)) {
            Date dat(y, m, d);
            return dat;
        }
        else if (!checkDay(d) && !checkMonth(m)) {
            cout << "Month value is invalid:" << m;
        }
        else if (checkDay(d) && !checkMonth(m)) {
            cout << "Month value is invalid:" << m;
        }
        else {
            cout << "Day value is invalid:" << d;
        }
    }
}
ostream& operator<<(ostream& stream,  Date date) {
    stream << setw(4) << setfill('0') << date.getY()<<'-' << setw(2) << setfill('0') << date.getM()<<'-' << setw(2) << setfill('0') << date.getD();
    return stream;
}
bool operator <(Date lhs, Date rhs) {
    return vector<int>{lhs.getY(), lhs.getM(), lhs.getD()} > vector<int>{rhs.getY(), rhs.getM(), rhs.getD()};
}
class DB {
public:
    void AddEvent(const Date& date, const string& ev) {
        db[date].insert(ev);
    }
    void DeleteEvent(const Date& date, const string& ev) {
        if (db[date].count(ev) > 0) {
            db[date].erase(ev);
            cout << "Deleted successfully" << endl;
        }
        else {
            cout << "Event not found" << endl;
        }
    }
    void DeleteDate(const Date& date) {
        int n = db[date].size();
            db[date].clear();
            cout << "Deleted " << n << " events" << endl;
    }
    set<string> Find(const Date& date) {
        return db[date];
    }
    void Print() const {
        for (const auto& i: db) {
            for (const string& e : i.second) {
                cout << i.first << " " << e << endl;
            }
        }
    }
private:
    map<Date, set<string>> db;
};
int main()
{
    DB d;
    string com;
    while (getline(cin, com)) {
        stringstream ss(com);
        string command;
        ss >> command;
        if (command == "Add") {
            string dates, ev;
            ss >> dates >> ev;
            const Date date = Parse(dates);
            d.AddEvent(date, ev);
        }
        else  if (command == "Del") {
            string ev, dates;
            ss >> dates;
            if (!ss.eof()) {
                ss >> ev;
            }
            const Date date = Parse(dates);
            if (ev.empty()) {
            d.DeleteDate(date);
            }
            else {
            d.DeleteEvent(date, ev); 
            }
            
        }
        else  if (command == "Find") {
            string dates;
            ss >> dates;
            const Date date = Parse(dates);
            for (const string& event : d.Find(date)) {
                cout << event << endl;
            }

        }
        else if (command == "Print") {
            d.Print();
        }
        else {
            cout << "Unlnown command" << endl;
        }
    }
}

