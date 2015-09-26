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

void Z80_Exec_FD(Z80_State *state, uint8_t opcode)
{
    uint16_t addr;
    uint8_t tmp;
    uint16_t tmp_16;

    switch (opcode)
    {
    case 0x09: // add iy, bc
        t_states(7);
        add_16(rIY, rBC);
        break;

    case 0x19: // add iy, de
        t_states(7);
        add_16(rIY, rDE);
        break;

    case 0x21: // ld iy, **
        rIY = arg_16();
        break;

    case 0x22: // ld (**), iy
        addr = arg_16();
        write_16(addr, rIY);
        break;

    case 0x23: // inc iy
        t_states(2);
        rIY++;
        break;

    case 0x24: // inc iyh
        inc(rIYH);
        break;

    case 0x25: // dec iyh
        dec(rIYH);
        break;

    case 0x26: // ld iyh, *
        rIYH = arg();
        break;

    case 0x29: // add iy, iy
        t_states(7);
        add_16(rIY, rIY);
        break;

    case 0x2A: // ld iy, (**)
        addr = arg_16();
        rIY = read_16(addr);
        break;

    case 0x2B: // dec iy
        t_states(2);
        rIY--;
        break;

    case 0x2C: // inc iyl
        inc(rIYL);
        break;

    case 0x2D: // dec iyl
        dec(rIYL);
        break;

    case 0x2E: // ld iyl, *
        rIYL = arg();
        break;

    case 0x34: // inc (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        t_states(1);
        inc(tmp);
        write(addr, tmp);
        break;

    case 0x35: // dec (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        t_states(1);
        dec(tmp);
        write(addr, tmp);
        break;

    case 0x36: // ld (iy + *), *
        addr = rIY + (int8_t)arg();
        tmp = arg();
        t_states(2);
        write(addr, tmp);
        break;

    case 0x39: // add iy, sp
        t_states(7);
        add_16(rIY, rSP);
        break;

    case 0x44: // ld b, iyh
        rB = rIYH;
        break;

    case 0x45: // ld b, iyl
        rB = rIYL;
        break;

    case 0x46: // ld b, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rB = tmp;
        break;

    case 0x4C: // ld c, iyh
        rC = rIYH;
        break;

    case 0x4D: // ld c, iyl
        rC = rIYL;
        break;

    case 0x4E: // ld c, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rC = tmp;
        break;

    case 0x54: // ld d, iyh
        rD = rIYH;
        break;

    case 0x55: // ld d, iyl
        rD = rIYL;
        break;

    case 0x56: // ld d, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rD = tmp;
        break;

    case 0x5C: // ld e, iyh
        rE = rIYH;
        break;

    case 0x5D: // ld e, iyl
        rE = rIYL;
        break;

    case 0x5E: // ld e, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rE = tmp;
        break;

    case 0x60: // ld iyh, b
        rIYH = rB;
        break;

    case 0x61: // ld iyh, c
        rIYH = rC;
        break;

    case 0x62: // ld iyh, d
        rIYH = rD;
        break;

    case 0x63: // ld iyh, e
        rIYH = rE;
        break;

    case 0x64: // ld iyh, iyh
        rIYH = rIYH;
        break;

    case 0x65: // ld iyh, iyl
        rIYH = rIYL;
        break;

    case 0x66: // ld h, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rH = tmp;
        break;

    case 0x67: // ld iyh, a
        rIYH = rA;
        break;

    case 0x68: // ld iyl, b
        rIYL = rB;
        break;

    case 0x69: // ld iyl, c
        rIYL = rC;
        break;

    case 0x6A: // ld iyl, d
        rIYL = rD;
        break;

    case 0x6B: // ld iyl, e
        rIYL = rE;
        break;

    case 0x6C: // ld iyl, iyh
        rIYL = rIYH;
        break;

    case 0x6D: // ld iyl, iyl
        rIYL = rIYL;
        break;

    case 0x6E: // ld l, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rL = tmp;
        break;

    case 0x6F: // ld iyl, a
        rIYL = rA;
        break;

    case 0x70: // ld (iy + *), b
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rB);
        break;

    case 0x71: // ld (iy + *), c
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rC);
        break;

    case 0x72: // ld (iy + *), d
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rD);
        break;

    case 0x73: // ld (iy + *), e
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rE);
        break;

    case 0x74: // ld (iy + *), h
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rH);
        break;

    case 0x75: // ld (iy + *), l
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rL);
        break;

    case 0x77: // ld (iy + *), a
        addr = rIY + (int8_t)arg();
        t_states(5);
        write(addr, rA);
        break;

    case 0x7C: // ld a, iyh
        rA = rIYH;
        break;

    case 0x7D: // ld a, iyl
        rA = rIYL;
        break;

    case 0x7E: // ld a, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        rA = tmp;
        break;

    case 0x84: // add a, iyh
        add(rIYH);
        break;

    case 0x85: // add a, iyl
        add(rIYL);
        break;

    case 0x86: // add a, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        add(tmp);
        break;

    case 0x8C: // adc a, iyh
        adc(rIYH);
        break;

    case 0x8D: // adc a, iyl
        adc(rIYL);
        break;

    case 0x8E: // adc a, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        adc(tmp);
        break;

    case 0x94: // sub iyh
        sub(rIYH);
        break;

    case 0x95: // sub iyl
        sub(rIYL);
        break;

    case 0x96: // sub (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        sub(tmp);
        break;

    case 0x9C: // sbc a, iyh
        sbc(rIYH);
        break;

    case 0x9D: // sbc a, iyl
        sbc(rIYL);
        break;

    case 0x9E: // sbc a, (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        sbc(tmp);
        break;

    case 0xA4: // and iyh
        and(rIYH);
        break;

    case 0xA5: // and iyl
        and(rIYL);
        break;

    case 0xA6: // and (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        and(tmp);
        break;

    case 0xAC: // xor iyh
        xor(rIYH);
        break;

    case 0xAD: // xor iyl
        xor(rIYL);
        break;

    case 0xAE: // xor (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        xor(tmp);
        break;

    case 0xB4: // or iyh
        or(rIYH);
        break;

    case 0xB5: // or iyl
        or(rIYL);
        break;

    case 0xB6: // or (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        or(tmp);
        break;

    case 0xBC: // cp iyh
        cp(rIYH);
        break;

    case 0xBD: // cp iyl
        cp(rIYL);
        break;

    case 0xBE: // cp (iy + *)
        addr = rIY + (int8_t)arg();
        t_states(5);
        tmp = read(addr);
        cp(tmp);
        break;

    case 0xCB: // ext fdcb
        cmd_fdcb();
        break;

    case 0xDD: // ext dd
        cmd_dd();
        break;

    case 0xE1: // pop iy
        rIY = pop_16();
        break;

    case 0xE3: // ex (sp), iy
        tmp_16 = pop_16();
        t_states(1);
        push_16(rIY);
        t_states(2);
        rIY = tmp_16;
        break;

    case 0xE5: // push iy
        t_states(1);
        push_16(rIY);
        break;

    case 0xE9: // jp (iy)
        rPC = rIY;
        break;

    case 0xED: // ext ed
        cmd_ed();
        break;

    case 0xF9: // ld sp, iy
        t_states(2);
        rSP = rIY;
        break;

    case 0xFD: // ext fd
        cmd_fd();
        break;
    }
}
