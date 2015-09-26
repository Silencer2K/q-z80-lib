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

void Z80_Exec_CB(Z80_State *state, uint8_t opcode)
{
    //uint16_t addr;
    uint8_t tmp;
    //uint16_t tmp_16;

    switch (opcode)
    {
    case 0x00: // rlc b
        rlc(rB);
        break;

    case 0x01: // rlc c
        rlc(rC);
        break;

    case 0x02: // rlc d
        rlc(rD);
        break;

    case 0x03: // rlc e
        rlc(rE);
        break;

    case 0x04: // rlc h
        rlc(rH);
        break;

    case 0x05: // rlc l
        rlc(rL);
        break;

    case 0x06: // rlc (hl)
        tmp = read(rHL);
        t_states(1);
        rlc(tmp);
        write(rHL, tmp);
        break;

    case 0x07: // rlc a
        rlc(rA);
        break;

    case 0x08: // rrc b
        rrc(rB);
        break;

    case 0x09: // rrc c
        rrc(rC);
        break;

    case 0x0A: // rrc d
        rrc(rD);
        break;

    case 0x0B: // rrc e
        rrc(rE);
        break;

    case 0x0C: // rrc h
        rrc(rH);
        break;

    case 0x0D: // rrc l
        rrc(rL);
        break;

    case 0x0E: // rrc (hl)
        tmp = read(rHL);
        t_states(1);
        rrc(tmp);
        write(rHL, tmp);
        break;

    case 0x0F: // rrc a
        rrc(rA);
        break;

    case 0x10: // rl b
        rl(rB);
        break;

    case 0x11: // rl c
        rl(rC);
        break;

    case 0x12: // rl d
        rl(rD);
        break;

    case 0x13: // rl e
        rl(rE);
        break;

    case 0x14: // rl h
        rl(rH);
        break;

    case 0x15: // rl l
        rl(rL);
        break;

    case 0x16: // rl (hl)
        tmp = read(rHL);
        t_states(1);
        rl(tmp);
        write(rHL, tmp);
        break;

    case 0x17: // rl a
        rl(rA);
        break;

    case 0x18: // rr b
        rr(rB);
        break;

    case 0x19: // rr c
        rr(rC);
        break;

    case 0x1A: // rr d
        rr(rD);
        break;

    case 0x1B: // rr e
        rr(rE);
        break;

    case 0x1C: // rr h
        rr(rH);
        break;

    case 0x1D: // rr l
        rr(rL);
        break;

    case 0x1E: // rr (hl)
        tmp = read(rHL);
        t_states(1);
        rr(tmp);
        write(rHL, tmp);
        break;

    case 0x1F: // rr a
        rr(rA);
        break;

    case 0x20: // sla b
        sla(rB);
        break;

    case 0x21: // sla c
        sla(rC);
        break;

    case 0x22: // sla d
        sla(rD);
        break;

    case 0x23: // sla e
        sla(rE);
        break;

    case 0x24: // sla h
        sla(rH);
        break;

    case 0x25: // sla l
        sla(rL);
        break;

    case 0x26: // sla (hl)
        tmp = read(rHL);
        t_states(1);
        sla(tmp);
        write(rHL, tmp);
        break;

    case 0x27: // sla a
        sla(rA);
        break;

    case 0x28: // sra b
        sra(rB);
        break;

    case 0x29: // sra c
        sra(rC);
        break;

    case 0x2A: // sra d
        sra(rD);
        break;

    case 0x2B: // sra e
        sra(rE);
        break;

    case 0x2C: // sra h
        sra(rH);
        break;

    case 0x2D: // sra l
        sra(rL);
        break;

    case 0x2E: // sra (hl)
        tmp = read(rHL);
        t_states(1);
        sra(tmp);
        write(rHL, tmp);
        break;

    case 0x2F: // sra a
        sra(rA);
        break;

    case 0x30: // sll b
        sll(rB);
        break;

    case 0x31: // sll c
        sll(rC);
        break;

    case 0x32: // sll d
        sll(rD);
        break;

    case 0x33: // sll e
        sll(rE);
        break;

    case 0x34: // sll h
        sll(rH);
        break;

    case 0x35: // sll l
        sll(rL);
        break;

    case 0x36: // sll (hl)
        tmp = read(rHL);
        t_states(1);
        sll(tmp);
        write(rHL, tmp);
        break;

    case 0x37: // sll a
        sll(rA);
        break;

    case 0x38: // srl b
        srl(rB);
        break;

    case 0x39: // srl c
        srl(rC);
        break;

    case 0x3A: // srl d
        srl(rD);
        break;

    case 0x3B: // srl e
        srl(rE);
        break;

    case 0x3C: // srl h
        srl(rH);
        break;

    case 0x3D: // srl l
        srl(rL);
        break;

    case 0x3E: // srl (hl)
        tmp = read(rHL);
        t_states(1);
        srl(tmp);
        write(rHL, tmp);
        break;

    case 0x3F: // srl a
        srl(rA);
        break;

    case 0x40: // bit 0, b
        bit(rB, 0);
        break;

    case 0x41: // bit 0, c
        bit(rC, 0);
        break;

    case 0x42: // bit 0, d
        bit(rD, 0);
        break;

    case 0x43: // bit 0, e
        bit(rE, 0);
        break;

    case 0x44: // bit 0, h
        bit(rH, 0);
        break;

    case 0x45: // bit 0, l
        bit(rL, 0);
        break;

    case 0x46: // bit 0, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 0);
        break;

    case 0x47: // bit 0, a
        bit(rA, 0);
        break;

    case 0x48: // bit 1, b
        bit(rB, 1);
        break;

    case 0x49: // bit 1, c
        bit(rC, 1);
        break;

    case 0x4A: // bit 1, d
        bit(rD, 1);
        break;

    case 0x4B: // bit 1, e
        bit(rE, 1);
        break;

    case 0x4C: // bit 1, h
        bit(rH, 1);
        break;

    case 0x4D: // bit 1, l
        bit(rL, 1);
        break;

    case 0x4E: // bit 1, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 1);
        break;

    case 0x4F: // bit 1, a
        bit(rA, 1);
        break;

    case 0x50: // bit 2, b
        bit(rB, 2);
        break;

    case 0x51: // bit 2, c
        bit(rC, 2);
        break;

    case 0x52: // bit 2, d
        bit(rD, 2);
        break;

    case 0x53: // bit 2, e
        bit(rE, 2);
        break;

    case 0x54: // bit 2, h
        bit(rH, 2);
        break;

    case 0x55: // bit 2, l
        bit(rL, 2);
        break;

    case 0x56: // bit 2, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 2);
        break;

    case 0x57: // bit 2, a
        bit(rA, 2);
        break;

    case 0x58: // bit 3, b
        bit(rB, 3);
        break;

    case 0x59: // bit 3, c
        bit(rC, 3);
        break;

    case 0x5A: // bit 3, d
        bit(rD, 3);
        break;

    case 0x5B: // bit 3, e
        bit(rE, 3);
        break;

    case 0x5C: // bit 3, h
        bit(rH, 3);
        break;

    case 0x5D: // bit 3, l
        bit(rL, 3);
        break;

    case 0x5E: // bit 3, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 3);
        break;

    case 0x5F: // bit 3, a
        bit(rA, 3);
        break;

    case 0x60: // bit 4, b
        bit(rB, 4);
        break;

    case 0x61: // bit 4, c
        bit(rC, 4);
        break;

    case 0x62: // bit 4, d
        bit(rD, 4);
        break;

    case 0x63: // bit 4, e
        bit(rE, 4);
        break;

    case 0x64: // bit 4, h
        bit(rH, 4);
        break;

    case 0x65: // bit 4, l
        bit(rL, 4);
        break;

    case 0x66: // bit 4, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 4);
        break;

    case 0x67: // bit 4, a
        bit(rA, 4);
        break;

    case 0x68: // bit 5, b
        bit(rB, 5);
        break;

    case 0x69: // bit 5, c
        bit(rC, 5);
        break;

    case 0x6A: // bit 5, d
        bit(rD, 5);
        break;

    case 0x6B: // bit 5, e
        bit(rE, 5);
        break;

    case 0x6C: // bit 5, h
        bit(rH, 5);
        break;

    case 0x6D: // bit 5, l
        bit(rL, 5);
        break;

    case 0x6E: // bit 5, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 5);
        break;

    case 0x6F: // bit 5, a
        bit(rA, 5);
        break;

    case 0x70: // bit 6, b
        bit(rB, 6);
        break;

    case 0x71: // bit 6, c
        bit(rC, 6);
        break;

    case 0x72: // bit 6, d
        bit(rD, 6);
        break;

    case 0x73: // bit 6, e
        bit(rE, 6);
        break;

    case 0x74: // bit 6, h
        bit(rH, 6);
        break;

    case 0x75: // bit 6, l
        bit(rL, 6);
        break;

    case 0x76: // bit 6, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 6);
        break;

    case 0x77: // bit 6, a
        bit(rA, 6);
        break;

    case 0x78: // bit 7, b
        bit(rB, 7);
        break;

    case 0x79: // bit 7, c
        bit(rC, 7);
        break;

    case 0x7A: // bit 7, d
        bit(rD, 7);
        break;

    case 0x7B: // bit 7, e
        bit(rE, 7);
        break;

    case 0x7C: // bit 7, h
        bit(rH, 7);
        break;

    case 0x7D: // bit 7, l
        bit(rL, 7);
        break;

    case 0x7E: // bit 7, (hl)
        tmp = read(rHL);
        t_states(1);
        bit(tmp, 7);
        break;

    case 0x7F: // bit 7, a
        bit(rA, 7);
        break;

    case 0x80: // res 0, b
        res(rB, 0);
        break;

    case 0x81: // res 0, c
        res(rC, 0);
        break;

    case 0x82: // res 0, d
        res(rD, 0);
        break;

    case 0x83: // res 0, e
        res(rE, 0);
        break;

    case 0x84: // res 0, h
        res(rH, 0);
        break;

    case 0x85: // res 0, l
        res(rL, 0);
        break;

    case 0x86: // res 0, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 0);
        write(rHL, tmp);
        break;

    case 0x87: // res 0, a
        res(rA, 0);
        break;

    case 0x88: // res 1, b
        res(rB, 1);
        break;

    case 0x89: // res 1, c
        res(rC, 1);
        break;

    case 0x8A: // res 1, d
        res(rD, 1);
        break;

    case 0x8B: // res 1, e
        res(rE, 1);
        break;

    case 0x8C: // res 1, h
        res(rH, 1);
        break;

    case 0x8D: // res 1, l
        res(rL, 1);
        break;

    case 0x8E: // res 1, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 1);
        write(rHL, tmp);
        break;

    case 0x8F: // res 1, a
        res(rA, 1);
        break;

    case 0x90: // res 2, b
        res(rB, 2);
        break;

    case 0x91: // res 2, c
        res(rC, 2);
        break;

    case 0x92: // res 2, d
        res(rD, 2);
        break;

    case 0x93: // res 2, e
        res(rE, 2);
        break;

    case 0x94: // res 2, h
        res(rH, 2);
        break;

    case 0x95: // res 2, l
        res(rL, 2);
        break;

    case 0x96: // res 2, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 2);
        write(rHL, tmp);
        break;

    case 0x97: // res 2, a
        res(rA, 2);
        break;

    case 0x98: // res 3, b
        res(rB, 3);
        break;

    case 0x99: // res 3, c
        res(rC, 3);
        break;

    case 0x9A: // res 3, d
        res(rD, 3);
        break;

    case 0x9B: // res 3, e
        res(rE, 3);
        break;

    case 0x9C: // res 3, h
        res(rH, 3);
        break;

    case 0x9D: // res 3, l
        res(rL, 3);
        break;

    case 0x9E: // res 3, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 3);
        write(rHL, tmp);
        break;

    case 0x9F: // res 3, a
        res(rA, 3);
        break;

    case 0xA0: // res 4, b
        res(rB, 4);
        break;

    case 0xA1: // res 4, c
        res(rC, 4);
        break;

    case 0xA2: // res 4, d
        res(rD, 4);
        break;

    case 0xA3: // res 4, e
        res(rE, 4);
        break;

    case 0xA4: // res 4, h
        res(rH, 4);
        break;

    case 0xA5: // res 4, l
        res(rL, 4);
        break;

    case 0xA6: // res 4, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 4);
        write(rHL, tmp);
        break;

    case 0xA7: // res 4, a
        res(rA, 4);
        break;

    case 0xA8: // res 5, b
        res(rB, 5);
        break;

    case 0xA9: // res 5, c
        res(rC, 5);
        break;

    case 0xAA: // res 5, d
        res(rD, 5);
        break;

    case 0xAB: // res 5, e
        res(rE, 5);
        break;

    case 0xAC: // res 5, h
        res(rH, 5);
        break;

    case 0xAD: // res 5, l
        res(rL, 5);
        break;

    case 0xAE: // res 5, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 5);
        write(rHL, tmp);
        break;

    case 0xAF: // res 5, a
        res(rA, 5);
        break;

    case 0xB0: // res 6, b
        res(rB, 6);
        break;

    case 0xB1: // res 6, c
        res(rC, 6);
        break;

    case 0xB2: // res 6, d
        res(rD, 6);
        break;

    case 0xB3: // res 6, e
        res(rE, 6);
        break;

    case 0xB4: // res 6, h
        res(rH, 6);
        break;

    case 0xB5: // res 6, l
        res(rL, 6);
        break;

    case 0xB6: // res 6, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 6);
        write(rHL, tmp);
        break;

    case 0xB7: // res 6, a
        res(rA, 6);
        break;

    case 0xB8: // res 7, b
        res(rB, 7);
        break;

    case 0xB9: // res 7, c
        res(rC, 7);
        break;

    case 0xBA: // res 7, d
        res(rD, 7);
        break;

    case 0xBB: // res 7, e
        res(rE, 7);
        break;

    case 0xBC: // res 7, h
        res(rH, 7);
        break;

    case 0xBD: // res 7, l
        res(rL, 7);
        break;

    case 0xBE: // res 7, (hl)
        tmp = read(rHL);
        t_states(1);
        res(tmp, 7);
        write(rHL, tmp);
        break;

    case 0xBF: // res 7, a
        res(rA, 7);
        break;

    case 0xC0: // set 0, b
        set(rB, 0);
        break;

    case 0xC1: // set 0, c
        set(rC, 0);
        break;

    case 0xC2: // set 0, d
        set(rD, 0);
        break;

    case 0xC3: // set 0, e
        set(rE, 0);
        break;

    case 0xC4: // set 0, h
        set(rH, 0);
        break;

    case 0xC5: // set 0, l
        set(rL, 0);
        break;

    case 0xC6: // set 0, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 0);
        write(rHL, tmp);
        break;

    case 0xC7: // set 0, a
        set(rA, 0);
        break;

    case 0xC8: // set 1, b
        set(rB, 1);
        break;

    case 0xC9: // set 1, c
        set(rC, 1);
        break;

    case 0xCA: // set 1, d
        set(rD, 1);
        break;

    case 0xCB: // set 1, e
        set(rE, 1);
        break;

    case 0xCC: // set 1, h
        set(rH, 1);
        break;

    case 0xCD: // set 1, l
        set(rL, 1);
        break;

    case 0xCE: // set 1, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 1);
        write(rHL, tmp);
        break;

    case 0xCF: // set 1, a
        set(rA, 1);
        break;

    case 0xD0: // set 2, b
        set(rB, 2);
        break;

    case 0xD1: // set 2, c
        set(rC, 2);
        break;

    case 0xD2: // set 2, d
        set(rD, 2);
        break;

    case 0xD3: // set 2, e
        set(rE, 2);
        break;

    case 0xD4: // set 2, h
        set(rH, 2);
        break;

    case 0xD5: // set 2, l
        set(rL, 2);
        break;

    case 0xD6: // set 2, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 2);
        write(rHL, tmp);
        break;

    case 0xD7: // set 2, a
        set(rA, 2);
        break;

    case 0xD8: // set 3, b
        set(rB, 3);
        break;

    case 0xD9: // set 3, c
        set(rC, 3);
        break;

    case 0xDA: // set 3, d
        set(rD, 3);
        break;

    case 0xDB: // set 3, e
        set(rE, 3);
        break;

    case 0xDC: // set 3, h
        set(rH, 3);
        break;

    case 0xDD: // set 3, l
        set(rL, 3);
        break;

    case 0xDE: // set 3, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 3);
        write(rHL, tmp);
        break;

    case 0xDF: // set 3, a
        set(rA, 3);
        break;

    case 0xE0: // set 4, b
        set(rB, 4);
        break;

    case 0xE1: // set 4, c
        set(rC, 4);
        break;

    case 0xE2: // set 4, d
        set(rD, 4);
        break;

    case 0xE3: // set 4, e
        set(rE, 4);
        break;

    case 0xE4: // set 4, h
        set(rH, 4);
        break;

    case 0xE5: // set 4, l
        set(rL, 4);
        break;

    case 0xE6: // set 4, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 4);
        write(rHL, tmp);
        break;

    case 0xE7: // set 4, a
        set(rA, 4);
        break;

    case 0xE8: // set 5, b
        set(rB, 5);
        break;

    case 0xE9: // set 5, c
        set(rC, 5);
        break;

    case 0xEA: // set 5, d
        set(rD, 5);
        break;

    case 0xEB: // set 5, e
        set(rE, 5);
        break;

    case 0xEC: // set 5, h
        set(rH, 5);
        break;

    case 0xED: // set 5, l
        set(rL, 5);
        break;

    case 0xEE: // set 5, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 5);
        write(rHL, tmp);
        break;

    case 0xEF: // set 5, a
        set(rA, 5);
        break;

    case 0xF0: // set 6, b
        set(rB, 6);
        break;

    case 0xF1: // set 6, c
        set(rC, 6);
        break;

    case 0xF2: // set 6, d
        set(rD, 6);
        break;

    case 0xF3: // set 6, e
        set(rE, 6);
        break;

    case 0xF4: // set 6, h
        set(rH, 6);
        break;

    case 0xF5: // set 6, l
        set(rL, 6);
        break;

    case 0xF6: // set 6, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 6);
        write(rHL, tmp);
        break;

    case 0xF7: // set 6, a
        set(rA, 6);
        break;

    case 0xF8: // set 7, b
        set(rB, 7);
        break;

    case 0xF9: // set 7, c
        set(rC, 7);
        break;

    case 0xFA: // set 7, d
        set(rD, 7);
        break;

    case 0xFB: // set 7, e
        set(rE, 7);
        break;

    case 0xFC: // set 7, h
        set(rH, 7);
        break;

    case 0xFD: // set 7, l
        set(rL, 7);
        break;

    case 0xFE: // set 7, (hl)
        tmp = read(rHL);
        t_states(1);
        set(tmp, 7);
        write(rHL, tmp);
        break;

    case 0xFF: // set 7, a
        set(rA, 7);
        break;
    }
}
