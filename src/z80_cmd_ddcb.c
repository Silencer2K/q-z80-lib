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

void Z80_Exec_DDCB(Z80_State *state, uint8_t opcode, int8_t offset)
{
    uint16_t addr = state->regs.IX + offset;
    state->T += 2;
    uint8_t tmp = Z80_Read(state, addr);
    state->T += 1;

    switch (opcode)
    {
    case 0x00: // rlc (ix + *), b
        rlc(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x01: // rlc (ix + *), c
        rlc(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x02: // rlc (ix + *), d
        rlc(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x03: // rlc (ix + *), e
        rlc(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x04: // rlc (ix + *), h
        rlc(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x05: // rlc (ix + *), l
        rlc(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x06: // rlc (ix + *)
        rlc(tmp);
        write(addr, tmp);
        break;

    case 0x07: // rlc (ix + *), a
        rlc(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x08: // rrc (ix + *), b
        rrc(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x09: // rrc (ix + *), c
        rrc(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x0A: // rrc (ix + *), d
        rrc(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x0B: // rrc (ix + *), e
        rrc(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x0C: // rrc (ix + *), h
        rrc(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x0D: // rrc (ix + *), l
        rrc(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x0E: // rrc (ix + *)
        rrc(tmp);
        write(addr, tmp);
        break;

    case 0x0F: // rrc (ix + *), a
        rrc(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x10: // rl (ix + *), b
        rl(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x11: // rl (ix + *), c
        rl(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x12: // rl (ix + *), d
        rl(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x13: // rl (ix + *), e
        rl(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x14: // rl (ix + *), h
        rl(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x15: // rl (ix + *), l
        rl(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x16: // rl (ix + *)
        rl(tmp);
        write(addr, tmp);
        break;

    case 0x17: // rl (ix + *), a
        rl(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x18: // rr (ix + *), b
        rr(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x19: // rr (ix + *), c
        rr(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x1A: // rr (ix + *), d
        rr(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x1B: // rr (ix + *), e
        rr(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x1C: // rr (ix + *), h
        rr(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x1D: // rr (ix + *), l
        rr(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x1E: // rr (ix + *)
        rr(tmp);
        write(addr, tmp);
        break;

    case 0x1F: // rr (ix + *), a
        rr(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x20: // sla (ix + *), b
        sla(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x21: // sla (ix + *), c
        sla(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x22: // sla (ix + *), d
        sla(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x23: // sla (ix + *), e
        sla(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x24: // sla (ix + *), h
        sla(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x25: // sla (ix + *), l
        sla(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x26: // sla (ix + *)
        sla(tmp);
        write(addr, tmp);
        break;

    case 0x27: // sla (ix + *), a
        sla(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x28: // sra (ix + *), b
        sra(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x29: // sra (ix + *), c
        sra(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x2A: // sra (ix + *), d
        sra(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x2B: // sra (ix + *), e
        sra(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x2C: // sra (ix + *), h
        sra(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x2D: // sra (ix + *), l
        sra(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x2E: // sra (ix + *)
        sra(tmp);
        write(addr, tmp);
        break;

    case 0x2F: // sra (ix + *), a
        sra(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x30: // sll (ix + *), b
        sll(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x31: // sll (ix + *), c
        sll(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x32: // sll (ix + *), d
        sll(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x33: // sll (ix + *), e
        sll(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x34: // sll (ix + *), h
        sll(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x35: // sll (ix + *), l
        sll(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x36: // sll (ix + *)
        sll(tmp);
        write(addr, tmp);
        break;

    case 0x37: // sll (ix + *), a
        sll(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x38: // srl (ix + *), b
        srl(tmp);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x39: // srl (ix + *), c
        srl(tmp);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x3A: // srl (ix + *), d
        srl(tmp);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x3B: // srl (ix + *), e
        srl(tmp);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x3C: // srl (ix + *), h
        srl(tmp);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x3D: // srl (ix + *), l
        srl(tmp);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x3E: // srl (ix + *)
        srl(tmp);
        write(addr, tmp);
        break;

    case 0x3F: // srl (ix + *), a
        srl(tmp);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x40: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x41: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x42: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x43: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x44: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x45: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x46: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x47: // bit 0, (ix + *)
        bit_a(tmp, 0, addr);
        break;

    case 0x48: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x49: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x4A: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x4B: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x4C: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x4D: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x4E: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x4F: // bit 1, (ix + *)
        bit_a(tmp, 1, addr);
        break;

    case 0x50: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x51: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x52: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x53: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x54: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x55: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x56: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x57: // bit 2, (ix + *)
        bit_a(tmp, 2, addr);
        break;

    case 0x58: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x59: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x5A: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x5B: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x5C: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x5D: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x5E: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x5F: // bit 3, (ix + *)
        bit_a(tmp, 3, addr);
        break;

    case 0x60: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x61: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x62: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x63: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x64: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x65: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x66: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x67: // bit 4, (ix + *)
        bit_a(tmp, 4, addr);
        break;

    case 0x68: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x69: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x6A: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x6B: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x6C: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x6D: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x6E: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x6F: // bit 5, (ix + *)
        bit_a(tmp, 5, addr);
        break;

    case 0x70: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x71: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x72: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x73: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x74: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x75: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x76: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x77: // bit 6, (ix + *)
        bit_a(tmp, 6, addr);
        break;

    case 0x78: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x79: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x7A: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x7B: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x7C: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x7D: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x7E: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x7F: // bit 7, (ix + *)
        bit_a(tmp, 7, addr);
        break;

    case 0x80: // res 0, (ix + *), b
        res(tmp, 0);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x81: // res 0, (ix + *), c
        res(tmp, 0);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x82: // res 0, (ix + *), d
        res(tmp, 0);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x83: // res 0, (ix + *), e
        res(tmp, 0);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x84: // res 0, (ix + *), h
        res(tmp, 0);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x85: // res 0, (ix + *), l
        res(tmp, 0);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x86: // res 0, (ix + *)
        res(tmp, 0);
        write(addr, tmp);
        break;

    case 0x87: // res 0, (ix + *), a
        res(tmp, 0);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x88: // res 1, (ix + *), b
        res(tmp, 1);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x89: // res 1, (ix + *), c
        res(tmp, 1);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x8A: // res 1, (ix + *), d
        res(tmp, 1);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x8B: // res 1, (ix + *), e
        res(tmp, 1);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x8C: // res 1, (ix + *), h
        res(tmp, 1);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x8D: // res 1, (ix + *), l
        res(tmp, 1);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x8E: // res 1, (ix + *)
        res(tmp, 1);
        write(addr, tmp);
        break;

    case 0x8F: // res 1, (ix + *), a
        res(tmp, 1);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x90: // res 2, (ix + *), b
        res(tmp, 2);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x91: // res 2, (ix + *), c
        res(tmp, 2);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x92: // res 2, (ix + *), d
        res(tmp, 2);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x93: // res 2, (ix + *), e
        res(tmp, 2);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x94: // res 2, (ix + *), h
        res(tmp, 2);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x95: // res 2, (ix + *), l
        res(tmp, 2);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x96: // res 2, (ix + *)
        res(tmp, 2);
        write(addr, tmp);
        break;

    case 0x97: // res 2, (ix + *), a
        res(tmp, 2);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0x98: // res 3, (ix + *), b
        res(tmp, 3);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0x99: // res 3, (ix + *), c
        res(tmp, 3);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0x9A: // res 3, (ix + *), d
        res(tmp, 3);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0x9B: // res 3, (ix + *), e
        res(tmp, 3);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0x9C: // res 3, (ix + *), h
        res(tmp, 3);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0x9D: // res 3, (ix + *), l
        res(tmp, 3);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0x9E: // res 3, (ix + *)
        res(tmp, 3);
        write(addr, tmp);
        break;

    case 0x9F: // res 3, (ix + *), a
        res(tmp, 3);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xA0: // res 4, (ix + *), b
        res(tmp, 4);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xA1: // res 4, (ix + *), c
        res(tmp, 4);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xA2: // res 4, (ix + *), d
        res(tmp, 4);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xA3: // res 4, (ix + *), e
        res(tmp, 4);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xA4: // res 4, (ix + *), h
        res(tmp, 4);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xA5: // res 4, (ix + *), l
        res(tmp, 4);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xA6: // res 4, (ix + *)
        res(tmp, 4);
        write(addr, tmp);
        break;

    case 0xA7: // res 4, (ix + *), a
        res(tmp, 4);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xA8: // res 5, (ix + *), b
        res(tmp, 5);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xA9: // res 5, (ix + *), c
        res(tmp, 5);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xAA: // res 5, (ix + *), d
        res(tmp, 5);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xAB: // res 5, (ix + *), e
        res(tmp, 5);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xAC: // res 5, (ix + *), h
        res(tmp, 5);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xAD: // res 5, (ix + *), l
        res(tmp, 5);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xAE: // res 5, (ix + *)
        res(tmp, 5);
        write(addr, tmp);
        break;

    case 0xAF: // res 5, (ix + *), a
        res(tmp, 5);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xB0: // res 6, (ix + *), b
        res(tmp, 6);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xB1: // res 6, (ix + *), c
        res(tmp, 6);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xB2: // res 6, (ix + *), d
        res(tmp, 6);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xB3: // res 6, (ix + *), e
        res(tmp, 6);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xB4: // res 6, (ix + *), h
        res(tmp, 6);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xB5: // res 6, (ix + *), l
        res(tmp, 6);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xB6: // res 6, (ix + *)
        res(tmp, 6);
        write(addr, tmp);
        break;

    case 0xB7: // res 6, (ix + *), a
        res(tmp, 6);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xB8: // res 7, (ix + *), b
        res(tmp, 7);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xB9: // res 7, (ix + *), c
        res(tmp, 7);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xBA: // res 7, (ix + *), d
        res(tmp, 7);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xBB: // res 7, (ix + *), e
        res(tmp, 7);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xBC: // res 7, (ix + *), h
        res(tmp, 7);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xBD: // res 7, (ix + *), l
        res(tmp, 7);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xBE: // res 7, (ix + *)
        res(tmp, 7);
        write(addr, tmp);
        break;

    case 0xBF: // res 7, (ix + *), a
        res(tmp, 7);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xC0: // set 0, (ix + *), b
        set(tmp, 0);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xC1: // set 0, (ix + *), c
        set(tmp, 0);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xC2: // set 0, (ix + *), d
        set(tmp, 0);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xC3: // set 0, (ix + *), e
        set(tmp, 0);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xC4: // set 0, (ix + *), h
        set(tmp, 0);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xC5: // set 0, (ix + *), l
        set(tmp, 0);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xC6: // set 0, (ix + *)
        set(tmp, 0);
        write(addr, tmp);
        break;

    case 0xC7: // set 0, (ix + *), a
        set(tmp, 0);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xC8: // set 1, (ix + *), b
        set(tmp, 1);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xC9: // set 1, (ix + *), c
        set(tmp, 1);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xCA: // set 1, (ix + *), d
        set(tmp, 1);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xCB: // set 1, (ix + *), e
        set(tmp, 1);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xCC: // set 1, (ix + *), h
        set(tmp, 1);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xCD: // set 1, (ix + *), l
        set(tmp, 1);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xCE: // set 1, (ix + *)
        set(tmp, 1);
        write(addr, tmp);
        break;

    case 0xCF: // set 1, (ix + *), a
        set(tmp, 1);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xD0: // set 2, (ix + *), b
        set(tmp, 2);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xD1: // set 2, (ix + *), c
        set(tmp, 2);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xD2: // set 2, (ix + *), d
        set(tmp, 2);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xD3: // set 2, (ix + *), e
        set(tmp, 2);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xD4: // set 2, (ix + *), h
        set(tmp, 2);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xD5: // set 2, (ix + *), l
        set(tmp, 2);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xD6: // set 2, (ix + *)
        set(tmp, 2);
        write(addr, tmp);
        break;

    case 0xD7: // set 2, (ix + *), a
        set(tmp, 2);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xD8: // set 3, (ix + *), b
        set(tmp, 3);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xD9: // set 3, (ix + *), c
        set(tmp, 3);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xDA: // set 3, (ix + *), d
        set(tmp, 3);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xDB: // set 3, (ix + *), e
        set(tmp, 3);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xDC: // set 3, (ix + *), h
        set(tmp, 3);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xDD: // set 3, (ix + *), l
        set(tmp, 3);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xDE: // set 3, (ix + *)
        set(tmp, 3);
        write(addr, tmp);
        break;

    case 0xDF: // set 3, (ix + *), a
        set(tmp, 3);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xE0: // set 4, (ix + *), b
        set(tmp, 4);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xE1: // set 4, (ix + *), c
        set(tmp, 4);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xE2: // set 4, (ix + *), d
        set(tmp, 4);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xE3: // set 4, (ix + *), e
        set(tmp, 4);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xE4: // set 4, (ix + *), h
        set(tmp, 4);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xE5: // set 4, (ix + *), l
        set(tmp, 4);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xE6: // set 4, (ix + *)
        set(tmp, 4);
        write(addr, tmp);
        break;

    case 0xE7: // set 4, (ix + *), a
        set(tmp, 4);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xE8: // set 5, (ix + *), b
        set(tmp, 5);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xE9: // set 5, (ix + *), c
        set(tmp, 5);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xEA: // set 5, (ix + *), d
        set(tmp, 5);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xEB: // set 5, (ix + *), e
        set(tmp, 5);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xEC: // set 5, (ix + *), h
        set(tmp, 5);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xED: // set 5, (ix + *), l
        set(tmp, 5);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xEE: // set 5, (ix + *)
        set(tmp, 5);
        write(addr, tmp);
        break;

    case 0xEF: // set 5, (ix + *), a
        set(tmp, 5);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xF0: // set 6, (ix + *), b
        set(tmp, 6);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xF1: // set 6, (ix + *), c
        set(tmp, 6);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xF2: // set 6, (ix + *), d
        set(tmp, 6);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xF3: // set 6, (ix + *), e
        set(tmp, 6);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xF4: // set 6, (ix + *), h
        set(tmp, 6);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xF5: // set 6, (ix + *), l
        set(tmp, 6);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xF6: // set 6, (ix + *)
        set(tmp, 6);
        write(addr, tmp);
        break;

    case 0xF7: // set 6, (ix + *), a
        set(tmp, 6);
        rA = tmp;
        write(addr, tmp);
        break;

    case 0xF8: // set 7, (ix + *), b
        set(tmp, 7);
        rB = tmp;
        write(addr, tmp);
        break;

    case 0xF9: // set 7, (ix + *), c
        set(tmp, 7);
        rC = tmp;
        write(addr, tmp);
        break;

    case 0xFA: // set 7, (ix + *), d
        set(tmp, 7);
        rD = tmp;
        write(addr, tmp);
        break;

    case 0xFB: // set 7, (ix + *), e
        set(tmp, 7);
        rE = tmp;
        write(addr, tmp);
        break;

    case 0xFC: // set 7, (ix + *), h
        set(tmp, 7);
        rH = tmp;
        write(addr, tmp);
        break;

    case 0xFD: // set 7, (ix + *), l
        set(tmp, 7);
        rL = tmp;
        write(addr, tmp);
        break;

    case 0xFE: // set 7, (ix + *)
        set(tmp, 7);
        write(addr, tmp);
        break;

    case 0xFF: // set 7, (ix + *), a
        set(tmp, 7);
        rA = tmp;
        write(addr, tmp);
        break;
    }
}
