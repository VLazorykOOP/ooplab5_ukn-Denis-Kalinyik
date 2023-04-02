#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class String {
public:
    String() {}
    String(const char* s) : str(s) {}
    String(const String& other) : str(other.str) {}

    virtual ~String() {}

    virtual void print() const { cout << str; }

    friend ostream& operator<<(ostream& out, const String& s) {
        s.print();
        return out;
    }

    friend istream& operator>>(istream& in, String& s) {
        getline(in, s.str);
        return in;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

protected:
    string str;
};

class NumberString : public String {
public:
    NumberString() {}
    NumberString(const char* s) : String(s) {}

    void print() const {
        for (char c : str) {
            if (isdigit(c)) {
                cout << c;
            }
        }
    }

    friend ostream& operator<<(ostream& out, const NumberString& ns) {
        ns.print();
        return out;
    }

    friend istream& operator>>(istream& in, NumberString& ns) {
        getline(in, ns.str);
        return in;
    }

    NumberString& operator=(const NumberString& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }
};

int main() {
    srand(time(nullptr));

    NumberString ns1;
    cout << "Enter a string: ";
    cin >> ns1;
    cout << "Input: " << ns1 << endl;

    NumberString ns2(to_string(rand() % 10000).c_str());
    cout << "Random: " << ns2 << endl;

    return 0;
}
