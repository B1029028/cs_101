#include <iostream>

using namespace std;

class Clock {
    public:
        int Hour;
        int minute;
        int second;
        string meridian;
        Clock(int a, int b, int c, string d) {
            Hour = a;
            minute = b;
            second = c;
            meridian = d;
        }
        void display() {
            cout << Hour << ":" << minute << ":" << second << meridian << endl;
        }
};

class StandardClock : Clock {
    public:
        string n;
        StandardClock(int a, int b, int c, string d) : Clock(a, b, c, d){
            if (d[0] == 'A') {
                n = "上午";
            }else {
                n = "下午";
            }
        }

        void display(){
            cout << n << Hour << ":" << minute << ":" << second << endl;
        }
};

class MilitaryClock : Clock {
    public:
        int n;
        MilitaryClock(int a, int b, int c, string d) : Clock(a, b, c, d){
            if (d[0] == 'P') {
                Hour+=12;
            }
        }

        void display(){
            cout << Hour << ":" << minute << ":" << second << endl;
        }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;

}