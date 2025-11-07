#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdint>
#include "LogicFunctions.h"

using namespace std;
using namespace LogicFunctions;

enum class Operation {
    INVALID = 0,
    NOT = 1,
    AND = 2,
    OR = 3,
    XOR = 4,
    MUX = 5,
    DMUX = 6,
    NOT16 = 7,
    AND16 = 8,
    OR16 = 9,
    MUX16 = 10,
    OR8WAY = 11
};

static string toUpper(string s) {
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return static_cast<char>(toupper(c)); });
    return s;
}

static Operation stringToOp(const string &s) {
    if (s == "NOT") return Operation::NOT;
    if (s == "AND") return Operation::AND;
    if (s == "OR") return Operation::OR;
    if (s == "XOR") return Operation::XOR;
    if (s == "MUX") return Operation::MUX;
    if (s == "DMUX") return Operation::DMUX;
    if (s == "NOT16") return Operation::NOT16;
    if (s == "AND16") return Operation::AND16;
    if (s == "OR16") return Operation::OR16;
    if (s == "MUX16") return Operation::MUX16;
    if (s == "OR8WAY") return Operation::OR8WAY;
    return Operation::INVALID;
}

string startup() {
    string operation;
    bool started = false;

    while (!started) {
        cout << "       LogicComputer v1.0       " << endl;
        cout << "    Developed by Ari Cummings   " << endl;
        cout << "--------------------------------" << endl;
        cout << "           Operations:          " << endl;
        cout << "--------------NOT---------------" << endl;
        cout << "--------------AND---------------" << endl;
        cout << "--------------OR----------------" << endl;
        cout << "--------------XOR---------------" << endl;
        cout << "--------------MUX---------------" << endl;
        cout << "--------------DMUX--------------" << endl;
        cout << "--------------NOT16-------------" << endl;
        cout << "--------------AND16-------------" << endl;
        cout << "--------------OR16--------------" << endl;
        cout << "--------------MUX16-------------" << endl;
        cout << "--------------OR8WAY------------" << endl;
        cout << endl;
        cout << "Enter Operation: ";
        if (!(cin >> operation)) {
            // handle EOF / input error
            cin.clear();
            string dummy;
            getline(cin, dummy);
            continue;
        }
        cout << endl;

        operation = toUpper(operation);
        if (stringToOp(operation) != Operation::INVALID) {
            cout << "Operation " << operation << " is Valid." << endl;
            started = true;
        } else {
            cout << "Operation " << operation << " is Invalid." << endl;
        }
    }

    return operation;
}

int main() {
    cout << boolalpha;
    bool continu = true;

    while (continu) {
        string opStr = startup();
        Operation op = stringToOp(opStr);

        switch (op) {
            case Operation::NOT: {
                cout << endl << "Boolean input: ";
                bool in; cin >> in;
                bool out = NOT(in);
                cout << "Output: " << out << endl;
                break;
            }
            case Operation::AND: {
                cout << endl << "Boolean input A: ";
                bool a; cin >> a;
                cout << "Boolean input B: ";
                bool b; cin >> b;
                bool out = AND(a, b);
                cout << "Output: " << out << endl;
                break;
            }
            case Operation::OR: {
                cout << endl << "Boolean input A: ";
                bool a; cin >> a;
                cout << "Boolean input B: ";
                bool b; cin >> b;
                bool out = OR(a, b);
                cout << "Output: " << out << endl;
                break;
            }
            case Operation::XOR: {
                cout << endl << "Boolean input A: ";
                bool a; cin >> a;
                cout << "Boolean input B: ";
                bool b; cin >> b;
                bool out = XOR(a, b);
                cout << "Output: " << out << endl;
                break;
            }
            case Operation::MUX: {
                cout << endl << "Boolean input A: ";
                bool a; cin >> a;
                cout << "Boolean input B: ";
                bool b; cin >> b;
                cout << "Selector: ";
                bool sel; cin >> sel;
                bool out = MUX(a, b, sel);
                cout << "Output: " << out << endl;
                break;
            }
            case Operation::DMUX: {
                cout << endl << "Boolean input: ";
                bool in; cin >> in;
                cout << "Selector: ";
                bool sel; cin >> sel;
                ab out = DMUX(in, sel);
                cout << "Output A: " << out.a << endl;
                cout << "Output B: " << out.b << endl;
                break;
            }
            case Operation::NOT16: {
                cout << endl << "16-bit bool (as integer): ";
                unsigned int in_int; cin >> in_int;
                bool16 in; in.bits = static_cast<uint16_t>(in_int);
                bool16 out = NOT16(in);
                cout << "Output: " << out.bits << endl;
                break;
            }
            case Operation::AND16: {
                cout << endl << "16-bit bool A (as integer): ";
                unsigned int a_int; cin >> a_int;
                cout << "16-bit bool B (as integer): ";
                unsigned int b_int; cin >> b_int;
                bool16 a; a.bits = static_cast<uint16_t>(a_int);
                bool16 b; b.bits = static_cast<uint16_t>(b_int);
                bool16 out = AND16(a, b);
                cout << "Output: " << out.bits << endl;
                break;
            }
            case Operation::OR16: {
                cout << endl << "16-bit bool A (as integer): ";
                unsigned int a_int; cin >> a_int;
                cout << "16-bit bool B (as integer): ";
                unsigned int b_int; cin >> b_int;
                bool16 a; a.bits = static_cast<uint16_t>(a_int);
                bool16 b; b.bits = static_cast<uint16_t>(b_int);
                bool16 out = OR16(a, b);
                cout << "Output: " << out.bits << endl;
                break;
            }
            case Operation::MUX16: {
                cout << endl << "16-bit bool A (as integer): ";
                unsigned int a_int; cin >> a_int;
                cout << "16-bit bool B (as integer): ";
                unsigned int b_int; cin >> b_int;
                cout << "Selector : ";
                bool sel; cin >> sel;
                bool16 a; a.bits = static_cast<uint16_t>(a_int);
                bool16 b; b.bits = static_cast<uint16_t>(b_int);
                bool16 out = MUX16(a, b, sel);
                cout << "Output: " << out.bits << endl;
                break;
            }
            case Operation::OR8WAY: {
                cout << endl << "8-bit bool (as integer): ";
                unsigned int in_int; cin >> in_int;
                bool8 in; in.bits = static_cast<uint8_t>(in_int);
                bool out = OR8WAY(in);
                cout << "Output: " << out << endl;
                break;
            }
            default: {
                cout << "Invalid operation selected." << endl;
                break;
            }
        }

        cout << endl << "Would you like to perform another operation? (Y for yes, n for no): ";
        char continuchar; cin >> continuchar;
        continu = (continuchar == 'y' || continuchar == 'Y');
    }

    return 0;
}
