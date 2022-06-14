#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class myString {

};

class ReadClass {
    public:
        ifstream in;
        string str;
        int n = 0;
        void showClass() {
            in.open("qz7.cpp");
            while(getline(in,str)) {
                int strposition = str.find("class");
                int strposition2 = str.find("{");
                if (strposition != -1 && strposition2 != -1) {
                    n = n+1;
                    for (int i = 0;; i++){
                        if(str[i] == '{'){
                            break;
                        }
                        cout << str[i];
                    }
                    cout << "\n";
                }
                
            }
            cout << n << " class in qz7" << endl;
            in.close();
        }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}