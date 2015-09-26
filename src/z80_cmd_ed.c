// The MIT License (MIT)
//
// Copyright (c) 2015 Aleksandr Aleshin <silencer@quadrius.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "z80.h"
#include "z80_cmd.h"

void Z80_Exec_ED(Z80_State *state, uint8_t opcode)
{
    uint16_t addr;
    uint8_t tmp;
    //uint16_t tmp_16;

    switch (opcode)
    {
    case 0x40: // in b, (c)
        rB = in(rBC);
        in_f(rB);
        break;

    case 0x41: // out (c), b
        out(rBC, rB);
        break;

    case 0x42: // sbc hl, bc
        t_states(7);
        sbc_16(rHL, rBC);
        break;

    case 0x43: // ld (**), bc
        addr = arg_16();
        write_16(addr, rBC);
        break;

    case 0x44: // neg
        neg();
        break;

    case 0x45: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x46: // im 0
        S(IM) = 0;
        break;

    case 0x47: // ld i, a
        t_states(1);
        rI = rA;
        break;

    case 0x48: // in c, (c)
        rC = in(rBC);
        in_f(rC);
        break;

    case 0x49: // out (c), c
        out(rBC, rC);
        break;

    case 0x4A: // adc hl, bc
        t_states(7);
        adc_16(rHL, rBC);
        break;

    case 0x4B: // ld bc, (**)
        addr = arg_16();
        rBC = read_16(addr);
        break;

    case 0x4C: // neg
        neg();
        break;

    case 0x4D: // reti
        rPC = pop_16();
        break;

    case 0x4E: // im 0/1
        S(IM) = 0;
        break;

    case 0x4F: // ld r, a
        t_states(1);
        rR = rA;
        break;

    case 0x50: // in d, (c)
        rD = in(rBC);
        in_f(rD);
        break;

    case 0x51: // out (c), d
        out(rBC, rD);
        break;

    case 0x52: // sbc hl, de
        t_states(7);
        sbc_16(rHL, rDE);
        break;

    case 0x53: // ld (**), de
        addr = arg_16();
        write_16(addr, rDE);
        break;

    case 0x54: // neg
        neg();
        break;

    case 0x55: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x56: // im 1
        S(IM) = 1;
        break;

    case 0x57: // ld a, i
        t_states(1);
        rA = rI;
        ld_f(rA);
        break;

    case 0x58: // in e, (c)
        rE = in(rBC);
        in_f(rE);
        break;

    case 0x59: // out (c), e
        out(rBC, rE);
        break;

    case 0x5A: // adc hl, de
        t_states(7);
        adc_16(rHL, rDE);
        break;

    case 0x5B: // ld de, (**)
        addr = arg_16();
        rDE = read_16(addr);
        break;

    case 0x5C: // neg
        neg();
        break;

    case 0x5D: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x5E: // im 2
        S(IM) = 2;
        break;

    case 0x5F: // ld a, r
        t_states(1);
        rA = rR;
        ld_f(rA);
        break;

    case 0x60: // in h, (c)
        rH = in(rBC);
        in_f(rH);
        break;

    case 0x61: // out (c), h
        out(rBC, rH);
        break;

    case 0x62: // sbc hl, hl
        t_states(7);
        sbc_16(rHL, rHL);
        break;

    case 0x63: // ld (**), hl
        addr = arg_16();
        write_16(addr, rHL);
        break;

    case 0x64: // neg
        neg();
        break;

    case 0x65: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x66: // im 0
        S(IM) = 0;
        break;

    case 0x67: // rrd
        tmp = read(rHL);
        t_states(4);
        rrd(tmp);
        write(rHL, tmp);
        break;

    case 0x68: // in l, (c)
        rL = in(rBC);
        in_f(rL);
        break;

    case 0x69: // out (c), l
        out(rBC, rL);
        break;

    case 0x6A: // adc hl, hl
        t_states(7);
        adc_16(rHL, rHL);
        break;

    case 0x6B: // ld hl, (**)
        addr = arg_16();
        rHL = read_16(addr);
        break;

    case 0x6C: // neg
        neg();
        break;

    case 0x6D: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x6E: // im 0/1
        S(IM) = 0;
        break;

    case 0x6F: // rld
        tmp = read(rHL);
        t_states(4);
        rld(tmp);
        write(rHL, tmp);
        break;

    case 0x70: // in (c)
        tmp = in(rBC);
        in_f(tmp);
        break;

    case 0x71: // out (c), 0
        out(rBC, 0);
        break;

    case 0x72: // sbc hl, sp
        t_states(7);
        sbc_16(rHL, rSP);
        break;

    case 0x73: // ld (**), sp
        addr = arg_16();
        write_16(addr, rSP);
        break;

    case 0x74: // neg
        neg();
        break;

    case 0x75: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x76: // im 1
        S(IM) = 1;
        break;

    case 0x78: // in a, (c)
        rA = in(rBC);
        in_f(rA);
        break;

    case 0x79: // out (c), a
        out(rBC, rA);
        break;

    case 0x7A: // adc hl, sp
        t_states(7);
        adc_16(rHL, rSP);
        break;

    case 0x7B: // ld sp, (**)
        addr = arg_16();
        rSP = read_16(addr);
        break;

    case 0x7C: // neg
        neg();
        break;

    case 0x7D: // retn
        S(IFF1) = S(IFF2);
        rPC = pop_16();
        break;

    case 0x7E: // im 2
        S(IM) = 2;
        break;

    case 0xA0: // ldi
        tmp = read(rHL++);
        write(rDE++, tmp);
        t_states(2);
        rBC--;
        ldr_f(tmp);
        break;

    case 0xA1: // cpi
        tmp = read(rHL++);
        t_states(5);
        rBC--;
        cpr_f(tmp);
        break;

    case 0xA2: // ini
        t_states(1);
        tmp = in(rBC);
        write(rHL++, tmp);
        rB--;
        inir_f(tmp);
        break;

    case 0xA3: // outi
        t_states(1);
        tmp = read(rHL++);
        rB--;
        out(rBC, tmp);
        outr_f(tmp);
        break;

    case 0xA8: // ldd
        tmp = read(rHL--);
        write(rDE--, tmp);
        t_states(2);
        rBC--;
        ldr_f(tmp);
        break;

    case 0xA9: // cpd
        tmp = read(rHL--);
        t_states(5);
        rBC--;
        cpr_f(tmp);
        break;

    case 0xAA: // ind
        t_states(1);
        tmp = in(rBC);
        write(rHL--, tmp);
        rB--;
        indr_f(tmp);
        break;

    case 0xAB: // outd
        t_states(1);
        tmp = read(rHL--);
        rB--;
        out(rBC, tmp);
        outr_f(tmp);
        break;

    case 0xB0: // ldir
        tmp = read(rHL++);
        write(rDE++, tmp);
        t_states(2);
        rBC--;
        ldr_f(tmp);
        if (rBC) {
            t_states(5);
            rep();
        }
        break;

    case 0xB1: // cpir
        tmp = read(rHL++);
        t_states(5);
        rBC--;
        cpr_f(tmp);
        if (rBC && !(rF & fZ)) {
            t_states(5);
            rep();
        }
        break;

    case 0xB2: // inir
        t_states(1);
        tmp = in(rBC);
        write(rHL++, tmp);
        rB--;
        inir_f(tmp);
        if (rB) {
            t_states(5);
            rep();
        }
        break;

    case 0xB3: // otir
        t_states(1);
        tmp = read(rHL++);
        rB--;
        out(rBC, tmp);
        outr_f(tmp);
        if (rB) {
            t_states(5);
            rep();
        }
        break;

    case 0xB8: // lddr
        tmp = read(rHL--);
        write(rDE--, tmp);
        t_states(2);
        rBC--;
        ldr_f(tmp);
        if (rBC) {
            t_states(5);
            rep();
        }
        break;

    case 0xB9: // cpdr
        tmp = read(rHL--);
        t_states(5);
        rBC--;
        cpr_f(tmp);
        if (rBC && !(rF & fZ)) {
            t_states(5);
            rep();
        }
        break;

    case 0xBA: // indr
        t_states(1);
        tmp = in(rBC);
        write(rHL--, tmp);
        rB--;
        indr_f(tmp);
        if (rB) {
            t_states(5);
            rep();
        }
        break;

    case 0xBB: // otdr
        t_states(1);
        tmp = read(rHL--);
        rB--;
        out(rBC, tmp);
        outr_f(tmp);
        if (rB) {
            t_states(5);
            rep();
        }
        break;
    }
}
