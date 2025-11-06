//
// Created by Ari Greene Cummings on 11/6/25.
//

#ifndef LOGICCOMPUTER_LOGICFUNCTIONS_H
#define LOGICCOMPUTER_LOGICFUNCTIONS_H

#include <cstdint>
#include <stdexcept>

namespace LogicFunctions {

    struct ab {
        bool a;
        bool b;
    };

    struct bool16 {
        uint16_t bits = 0;

        bool operator[](unsigned n) const {
            if (n >= 16) throw std::out_of_range("index");
            return (bits >> n) & 1u;
        }

        struct Proxy {
            uint16_t &bits;
            unsigned n;
            operator bool() const { return (bits >> n) & 1u; }
            Proxy& operator=(bool v) {
                if (v) bits |= (uint16_t(1u) << n);
                else   bits &= uint16_t(~(uint16_t(1u) << n));
                return *this;
            }
        };

        Proxy operator[](unsigned n) {
            if (n >= 16) throw std::out_of_range("index");
            return Proxy{bits, n};
        }

        void set(unsigned n, bool v) { (*this)[n] = v; }
        bool get(unsigned n) const { return (*this)[n]; }
    };

    struct bool8 {
        uint8_t bits = 0;

        bool operator[](unsigned n) const {
            if (n >= 8) throw std::out_of_range("index");
            return (bits >> n) & 1u;
        }

        struct Proxy {
            uint8_t &bits;
            unsigned n;
            operator bool() const { return (bits >> n) & 1u; }
            Proxy& operator=(bool v) {
                if (v) bits |= (uint8_t(1u) << n);
                else   bits &= uint8_t(~(uint8_t(1u) << n));
                return *this;
            }
        };

        Proxy operator[](unsigned n) {
            if (n >= 8) throw std::out_of_range("index");
            return Proxy{bits, n};
        }

        void set(unsigned n, bool v) { (*this)[n] = v; }
        bool get(unsigned n) const { return (*this)[n]; }

    };

    // 1-bit logic gates
    bool NOT(bool in);
    bool AND(bool a, bool b);
    bool OR(bool a, bool b);
    bool XOR(bool a, bool b);
    bool MUX(bool a, bool b, bool sel);

    // helpers and demultiplexer
    ab make_bools(bool a, bool b);
    ab DMUX(bool in, bool sel);

    // 16-bit variants
    bool16 NOT16(bool16 in);
    bool16 AND16(bool16 a, bool16 b);
    bool16 OR16(bool16 a, bool16 b);
    bool16 MUX16(bool16 a, bool16 b, bool sel);
    bool OR8WAY(bool8 in);

} // namespace LogicFunctions

#endif // LOGICCOMPUTER_LOGICFUNCTIONS_H