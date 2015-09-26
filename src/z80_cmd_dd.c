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

void Z80_Exec_DD(Z80_State *state, uint8_t opcode)
{
    uint16_t addr;
    uint8_t tmp;
    uint16_t tmp_16;

    switch (opcode)
    {
    case 0x09: // add ix, bc
        t_states(7);
        add_16(rIX, rBC);
        break;

    case 0x19: // add ix, de
        t_states(7);
        add_16(rIX, rDE);
        break;

    case 0x21: // ld ix, **
        rIX = arg_16();
        break;

    case 0x22: // ld (**), ix
        addr = arg_16();
        write_16(addr, rIX);
        break;

    case 0x23: // inc ix
        t_states(2);
        rIX++;
        break;

    case 0x24: // inc ixh
        inc(rIXH);
        break;

    case 0x25: // dec ixh
        dec(rIXH);
        break;

    case 0x26: // ld ixh, *
        rIXH = arg();
        break;

    case 0x29: // add ix, ix
        t_states(7);
        add_16(rIX, rIX);
        break;

    case 0x2A: // ld ix, (**)
        addr = arg_16();
        rIX = read_16(addr);
        break;

    case 0x2B: // dec ix
        t_states(2);
        rIX--;
        break;

    case 0x2C: // inc ixl
        inc(rIXL);
        break;

    case 0x2D: // dec ixl
        dec(rIXL);
        break;

    case 0x2E: // ld ixl, *
        rIXL = arg();
        break;

    case 0x34: // inc (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        t_states(1);
        inc(tmp);
        write(addr, tmp);
        break;

    case 0x35: // dec (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        t_states(1);
        dec(tmp);
        write(addr, tmp);
        break;

    case 0x36: // ld (ix + *), *
        addr = rIX + (int8_t)arg();
        tmp = arg();
        t_states(2);
        write(addr, tmp);
        break;

    case 0x39: // add ix, sp
        t_states(7);
        add_16(rIX, rSP);
        break;

    case 0x44: // ld b, ixh
        rB = rIXH;
        break;

    case 0x45: // ld b, ixl
        rB = rIXL;
        break;

    case 0x46: // ld b, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rB = tmp;
        break;

    case 0x4C: // ld c, ixh
        rC = rIXH;
        break;

    case 0x4D: // ld c, ixl
        rC = rIXL;
        break;

    case 0x4E: // ld c, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rC = tmp;
        break;

    case 0x54: // ld d, ixh
        rD = rIXH;
        break;

    case 0x55: // ld d, ixl
        rD = rIXL;
        break;

    case 0x56: // ld d, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rD = tmp;
        break;

    case 0x5C: // ld e, ixh
        rE = rIXH;
        break;

    case 0x5D: // ld e, ixl
        rE = rIXL;
        break;

    case 0x5E: // ld e, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rE = tmp;
        break;

    case 0x60: // ld ixh, b
        rIXH = rB;
        break;

    case 0x61: // ld ixh, c
        rIXH = rC;
        break;

    case 0x62: // ld ixh, d
        rIXH = rD;
        break;

    case 0x63: // ld ixh, e
        rIXH = rE;
        break;

    case 0x64: // ld ixh, ixh
        rIXH = rIXH;
        break;

    case 0x65: // ld ixh, ixl
        rIXH = rIXL;
        break;

    case 0x66: // ld h, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rH = tmp;
        break;

    case 0x67: // ld ixh, a
        rIXH = rA;
        break;

    case 0x68: // ld ixl, b
        rIXL = rB;
        break;

    case 0x69: // ld ixl, c
        rIXL = rC;
        break;

    case 0x6A: // ld ixl, d
        rIXL = rD;
        break;

    case 0x6B: // ld ixl, e
        rIXL = rE;
        break;

    case 0x6C: // ld ixl, ixh
        rIXL = rIXH;
        break;

    case 0x6D: // ld ixl, ixl
        rIXL = rIXL;
        break;

    case 0x6E: // ld l, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rL = tmp;
        break;

    case 0x6F: // ld ixl, a
        rIXL = rA;
        break;

    case 0x70: // ld (ix + *), b
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rB);
        break;

    case 0x71: // ld (ix + *), c
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rC);
        break;

    case 0x72: // ld (ix + *), d
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rD);
        break;

    case 0x73: // ld (ix + *), e
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rE);
        break;

    case 0x74: // ld (ix + *), h
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rH);
        break;

    case 0x75: // ld (ix + *), l
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rL);
        break;

    case 0x77: // ld (ix + *), a
        addr = rIX + (int8_t)arg();
        t_states(5);
        write(addr, rA);
        break;

    case 0x7C: // ld a, ixh
        rA = rIXH;
        break;

    case 0x7D: // ld a, ixl
        rA = rIXL;
        break;

    case 0x7E: // ld a, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rA = tmp;
        break;

    case 0x84: // add a, ixh
        add(rIXH);
        break;

    case 0x85: // add a, ixl
        add(rIXL);
        break;

    case 0x86: // add a, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        add(tmp);
        break;

    case 0x8C: // adc a, ixh
        adc(rIXH);
        break;

    case 0x8D: // adc a, ixl
        adc(rIXL);
        break;

    case 0x8E: // adc a, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        adc(tmp);
        break;

    case 0x94: // sub ixh
        sub(rIXH);
        break;

    case 0x95: // sub ixl
        sub(rIXL);
        break;

    case 0x96: // sub (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        sub(tmp);
        break;

    case 0x9C: // sbc a, ixh
        sbc(rIXH);
        break;

    case 0x9D: // sbc a, ixl
        sbc(rIXL);
        break;

    case 0x9E: // sbc a, (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        sbc(tmp);
        break;

    case 0xA4: // and ixh
        and(rIXH);
        break;

    case 0xA5: // and ixl
        and(rIXL);
        break;

    case 0xA6: // and (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        and(tmp);
        break;

    case 0xAC: // xor ixh
        xor(rIXH);
        break;

    case 0xAD: // xor ixl
        xor(rIXL);
        break;

    case 0xAE: // xor (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        xor(tmp);
        break;

    case 0xB4: // or ixh
        or(rIXH);
        break;

    case 0xB5: // or ixl
        or(rIXL);
        break;

    case 0xB6: // or (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        or(tmp);
        break;

    case 0xBC: // cp ixh
        cp(rIXH);
        break;

    case 0xBD: // cp ixl
        cp(rIXL);
        break;

    case 0xBE: // cp (ix + *)
        addr = rIX + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        cp(tmp);
        break;

    case 0xCB: // ext ddcb
        cmd_ddcb();
        break;

    case 0xDD: // ext dd
        cmd_dd();
        break;

    case 0xE1: // pop ix
        rIX = pop_16();
        break;

    case 0xE3: // ex (sp), ix
        tmp_16 = pop_16();
        t_states(1);
        push_16(rIX);
        t_states(2);
        rIX = tmp_16;
        break;

    case 0xE5: // push ix
        t_states(1);
        push_16(rIX);
        break;

    case 0xE9: // jp (ix)
        rPC = rIX;
        break;

    case 0xED: // ext ed
        cmd_ed();
        break;

    case 0xF9: // ld sp, ix
        t_states(2);
        rSP = rIX;
        break;

    case 0xFD: // ext fd
        cmd_fd();
        break;
    }
}
