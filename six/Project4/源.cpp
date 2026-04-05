#include <iostream>
using namespace std;

class Time {
private:
    int hour, minute, second;

    void normal() {
        int totalSeconds = hour * 3600 + minute * 60 + second;
        if (totalSeconds < 0) {
            totalSeconds = 86400 + (totalSeconds % 86400);
        }
        hour = totalSeconds / 3600 % 24;
        minute = (totalSeconds % 3600) / 60;
        second = totalSeconds % 60;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) { normal(); }

    friend istream& operator>>(istream& in, Time& t) {
        in >> t.hour >> t.minute >> t.second;
        t.normal();
        return in;
    }

    friend ostream& operator<<(ostream& out, const Time& t) {
        out.width(2); out.fill('0'); out << t.hour << ":";
        out.width(2); out.fill('0'); out << t.minute << ":";
        out.width(2); out.fill('0'); out << t.second;
        return out;
    }

    Time& operator+=(const Time& t) {
        second += t.second;
        minute += t.minute;
        hour += t.hour;
        normal();
        return *this;
    }

    Time& operator-=(const Time& t) {
        second -= t.second;
        minute -= t.minute;
        hour -= t.hour;
        normal();
        return *this;
    }

 
    Time& operator++() {
        ++second;
        normal();
        return *this;
    }

    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }


    Time& operator--() {
        --second;
        normal();
        return *this;
    }


    Time operator--(int) {
        Time temp = *this;
        --(*this);

        return temp;
    }
};

int main() {
    Time time1, time2;
    cin >> time1 >> time2;

    cout << (time1 += (time2++)) << endl;
    cout << (time1 -= time2) << endl;
    cout << (++time2) << endl;
    cout << (time2 += (time1--)) << endl;
    cout << (--time1) << endl;
    cout << (time2 -= time1) << endl;

    return 0;
}

