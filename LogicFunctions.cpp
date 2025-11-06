//
// Created by Ari Greene Cummings on 11/6/25.
//

#include "LogicFunctions.h"
#include <iostream>
#include <cstdint>
#include <stdexcept>
using namespace std;

namespace LogicFunctions {

    bool NOT(bool in) {
        bool out = !in;
        return out;
    }

    bool AND(bool a, bool b) {
        bool out = a && b;
        return out;
    }

    bool OR(bool a, bool b) {
        bool out = a || b;
        return out;
    }

    bool XOR(bool a, bool b) {
        bool nota = !a;
        bool notb = !b;
        bool aAndNotb = a && notb;
        bool NotaAndb = b && nota;
        bool out = aAndNotb || NotaAndb;
        return out;
    }

    bool MUX(bool a, bool b, bool sel) {
        bool notsel = !sel;
        bool bandsel = b && sel;
        bool aandnotsel = a && notsel;
        bool out = aandnotsel || bandsel;
        return out;
    }

    ab make_bools(bool a, bool b) {
        return {a, b};
    }

    ab DMUX(bool in, bool sel) {
        bool a = in && !sel;
        bool b = in && sel;
        ab out = make_bools(a, b);
        return out;
    }

    bool16 NOT16(bool16 in) {
        bool16 out;
        out[0] = !in[0];
        out[1] = !in[1];
        out[2] = !in[2];
        out[3] = !in[3];
        out[4] = !in[4];
        out[5] = !in[5];
        out[6] = !in[6];
        out[7] = !in[7];
        out[8] = !in[8];
        out[9] = !in[9];
        out[10] = !in[10];
        out[11] = !in[11];
        out[12] = !in[12];
        out[13] = !in[13];
        out[14] = !in[14];
        out[15] = !in[15];
        return out;

    }

    bool16 AND16(bool16 a, bool16 b) {
        bool16 out;
        out[0] = a[0] && b[0];
        out[1] = a[1] && b[1];
        out[2] = a[2] && b[2];
        out[3] = a[3] && b[3];
        out[4] = a[4] && b[4];
        out[5] = a[5] && b[5];
        out[6] = a[6] && b[6];
        out[7] = a[7] && b[7];
        out[8] = a[8] && b[8];
        out[9] = a[9] && b[9];
        out[10] = a[10] && b[10];
        out[11] = a[11] && b[11];
        out[12] = a[12] && b[12];
        out[13] = a[13] && b[13];
        out[14] = a[14] && b[14];
        out[15] = a[15] && b[15];
        return out;
    }

    bool16 OR16(bool16 a, bool16 b) {
        bool16 out;
        out[0] = a[0] || b[0];
        out[1] = a[1] || b[1];
        out[2] = a[2] || b[2];
        out[3] = a[3] || b[3];
        out[4] = a[4] || b[4];
        out[5] = a[5] || b[5];
        out[6] = a[6] || b[6];
        out[7] = a[7] || b[7];
        out[8] = a[8] || b[8];
        out[9] = a[9] || b[9];
        out[10] = a[10] || b[10];
        out[11] = a[11] || b[11];
        out[12] = a[12] || b[12];
        out[13] = a[13] || b[13];
        out[14] = a[14] || b[14];
        out[15] = a[15] || b[15];
        return out;
    }

    bool16 MUX16(bool16 a, bool16 b, bool sel) {
        bool16 out;
        out[0] = MUX(a[0] , b[0], sel);
        out[1] = MUX(a[1] , b[1], sel);
        out[2] = MUX(a[2] , b[2], sel);
        out[3] = MUX(a[3] , b[3], sel);
        out[4] = MUX(a[4] , b[4], sel);
        out[5] = MUX(a[5] , b[5], sel);
        out[6] = MUX(a[6] , b[6], sel);
        out[7] = MUX(a[7] , b[7], sel);
        out[8] = MUX(a[8] , b[8], sel);
        out[9] = MUX(a[9] , b[9], sel);
        out[10] = MUX(a[10] , b[10], sel);
        out[11] = MUX(a[11] , b[11], sel);
        out[12] = MUX(a[12] , b[12], sel);
        out[13] = MUX(a[13] , b[13], sel);
        out[14] = MUX(a[14] , b[14], sel);
        out[15] = MUX(a[15] , b[15], sel);
        return out;
    }

    bool OR8WAY(bool8 in) {
        bool out = in[0] || in[1] || in[2] || in[3] || in[4] || in[5] || in[6] || in[7];
        return out;
    }

}