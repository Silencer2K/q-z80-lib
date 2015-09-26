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

void Z80_Exec(Z80_State *state, uint8_t opcode)
{
    uint16_t addr;
    uint8_t tmp;
    uint16_t tmp_16;

    switch (opcode)
    {
    case 0x00: // nop
        break;

    case 0x01: // ld bc, **
        rBC = arg_16();
        break;

    case 0x02: // ld (bc), a
        write(rBC, rA);
        break;

    case 0x03: // inc bc
        t_states(2);
        rBC++;
        break;

    case 0x04: // inc b
        inc(rB);
        break;

    case 0x05: // dec b
        dec(rB);
        break;

    case 0x06: // ld b, *
        rB = arg();
        break;

    case 0x07: // rlca
        rlca();
        break;

    case 0x08: // ex af, af'
        swap_16(rAF, rAF_);
        break;

    case 0x09: // add hl, bc
        t_states(7);
        add_16(rHL, rBC);
        break;

    case 0x0A: // ld a, (bc)
        rA = read(rBC);
        break;

    case 0x0B: // dec bc
        t_states(2);
        rBC--;
        break;

    case 0x0C: // inc c
        inc(rC);
        break;

    case 0x0D: // dec c
        dec(rC);
        break;

    case 0x0E: // ld c, *
        rC = arg();
        break;

    case 0x0F: // rrca
        rrca();
        break;

    case 0x10: // djnz *
        t_states(1);
        tmp = arg();
        if (--rB) {
            t_states(5);
            rPC += (int8_t)tmp;
        }
        break;

    case 0x11: // ld de, **
        rDE = arg_16();
        break;

    case 0x12: // ld (de), a
        write(rDE, rA);
        break;

    case 0x13: // inc de
        t_states(2);
        rDE++;
        break;

    case 0x14: // inc d
        inc(rD);
        break;

    case 0x15: // dec d
        dec(rD);
        break;

    case 0x16: // ld d, *
        rD = arg();
        break;

    case 0x17: // rla
        rla();
        break;

    case 0x18: // jr *
        tmp = arg();
        t_states(5);
        rPC += (int8_t)tmp;
        break;

    case 0x19: // add hl, de
        t_states(7);
        add_16(rHL, rDE);
        break;

    case 0x1A: // ld a, (de)
        rA = read(rDE);
        break;

    case 0x1B: // dec de
        t_states(2);
        rDE--;
        break;

    case 0x1C: // inc e
        inc(rE);
        break;

    case 0x1D: // dec e
        dec(rE);
        break;

    case 0x1E: // ld e, *
        rE = arg();
        break;

    case 0x1F: // rra
        rra();
        break;

    case 0x20: // jr nz, *
        tmp = arg();
        if (!(rF & fZ)) {
            t_states(5);
            rPC += (int8_t)tmp;
        }
        break;

    case 0x21: // ld hl, **
        rHL = arg_16();
        break;

    case 0x22: // ld (**), hl
        addr = arg_16();
        write_16(addr, rHL);
        break;

    case 0x23: // inc hl
        t_states(2);
        rHL++;
        break;

    case 0x24: // inc h
        inc(rH);
        break;

    case 0x25: // dec h
        dec(rH);
        break;

    case 0x26: // ld h, *
        rH = arg();
        break;

    case 0x27: // daa
        daa();
        break;

    case 0x28: // jr z, *
        tmp = arg();
        if (rF & fZ) {
            t_states(5);
            rPC += (int8_t)tmp;
        }
        break;

    case 0x29: // add hl, hl
        t_states(7);
        add_16(rHL, rHL);
        break;

    case 0x2A: // ld hl, (**)
        addr = arg_16();
        rHL = read_16(addr);
        break;

    case 0x2B: // dec hl
        t_states(2);
        rHL--;
        break;

    case 0x2C: // inc l
        inc(rL);
        break;

    case 0x2D: // dec l
        dec(rL);
        break;

    case 0x2E: // ld l, *
        rL = arg();
        break;

    case 0x2F: // cpl
        cpl();
        break;

    case 0x30: // jr nc, *
        tmp = arg();
        if (!(rF & fC)) {
            t_states(5);
            rPC += (int8_t)tmp;
        }
        break;

    case 0x31: // ld sp, **
        rSP = arg_16();
        break;

    case 0x32: // ld (**), a
        addr = arg_16();
        write(addr, rA);
        break;

    case 0x33: // inc sp
        t_states(2);
        rSP++;
        break;

    case 0x34: // inc (hl)
        tmp = read(rHL);
        t_states(1);
        inc(tmp);
        write(rHL, tmp);
        break;

    case 0x35: // dec (hl)
        tmp = read(rHL);
        t_states(1);
        dec(tmp);
        write(rHL, tmp);
        break;

    case 0x36: // ld (hl), *
        tmp = arg();
        write(rHL, tmp);
        break;

    case 0x37: // scf
        scf();
        break;

    case 0x38: // jr c, *
        tmp = arg();
        if (rF & fC) {
            t_states(5);
            rPC += (int8_t)tmp;
        }
        break;

    case 0x39: // add hl, sp
        t_states(7);
        add_16(rHL, rSP);
        break;

    case 0x3A: // ld a, (**)
        addr = arg_16();
        rA = read(addr);
        break;

    case 0x3B: // dec sp
        t_states(2);
        rSP--;
        break;

    case 0x3C: // inc a
        inc(rA);
        break;

    case 0x3D: // dec a
        dec(rA);
        break;

    case 0x3E: // ld a, *
        rA = arg();
        break;

    case 0x3F: // ccf
        ccf();
        break;

    case 0x40: // ld b, b
        rB = rB;
        break;

    case 0x41: // ld b, c
        rB = rC;
        break;

    case 0x42: // ld b, d
        rB = rD;
        break;

    case 0x43: // ld b, e
        rB = rE;
        break;

    case 0x44: // ld b, h
        rB = rH;
        break;

    case 0x45: // ld b, l
        rB = rL;
        break;

    case 0x46: // ld b, (hl)
        rB = read(rHL);
        break;

    case 0x47: // ld b, a
        rB = rA;
        break;

    case 0x48: // ld c, b
        rC = rB;
        break;

    case 0x49: // ld c, c
        rC = rC;
        break;

    case 0x4A: // ld c, d
        rC = rD;
        break;

    case 0x4B: // ld c, e
        rC = rE;
        break;

    case 0x4C: // ld c, h
        rC = rH;
        break;

    case 0x4D: // ld c, l
        rC = rL;
        break;

    case 0x4E: // ld c, (hl)
        rC = read(rHL);
        break;

    case 0x4F: // ld c, a
        rC = rA;
        break;

    case 0x50: // ld d, b
        rD = rB;
        break;

    case 0x51: // ld d, c
        rD = rC;
        break;

    case 0x52: // ld d, d
        rD = rD;
        break;

    case 0x53: // ld d, e
        rD = rE;
        break;

    case 0x54: // ld d, h
        rD = rH;
        break;

    case 0x55: // ld d, l
        rD = rL;
        break;

    case 0x56: // ld d, (hl)
        rD = read(rHL);
        break;

    case 0x57: // ld d, a
        rD = rA;
        break;

    case 0x58: // ld e, b
        rE = rB;
        break;

    case 0x59: // ld e, c
        rE = rC;
        break;

    case 0x5A: // ld e, d
        rE = rD;
        break;

    case 0x5B: // ld e, e
        rE = rE;
        break;

    case 0x5C: // ld e, h
        rE = rH;
        break;

    case 0x5D: // ld e, l
        rE = rL;
        break;

    case 0x5E: // ld e, (hl)
        rE = read(rHL);
        break;

    case 0x5F: // ld e, a
        rE = rA;
        break;

    case 0x60: // ld h, b
        rH = rB;
        break;

    case 0x61: // ld h, c
        rH = rC;
        break;

    case 0x62: // ld h, d
        rH = rD;
        break;

    case 0x63: // ld h, e
        rH = rE;
        break;

    case 0x64: // ld h, h
        rH = rH;
        break;

    case 0x65: // ld h, l
        rH = rL;
        break;

    case 0x66: // ld h, (hl)
        rH = read(rHL);
        break;

    case 0x67: // ld h, a
        rH = rA;
        break;

    case 0x68: // ld l, b
        rL = rB;
        break;

    case 0x69: // ld l, c
        rL = rC;
        break;

    case 0x6A: // ld l, d
        rL = rD;
        break;

    case 0x6B: // ld l, e
        rL = rE;
        break;

    case 0x6C: // ld l, h
        rL = rH;
        break;

    case 0x6D: // ld l, l
        rL = rL;
        break;

    case 0x6E: // ld l, (hl)
        rL = read(rHL);
        break;

    case 0x6F: // ld l, a
        rL = rA;
        break;

    case 0x70: // ld (hl), b
        write(rHL, rB);
        break;

    case 0x71: // ld (hl), c
        write(rHL, rC);
        break;

    case 0x72: // ld (hl), d
        write(rHL, rD);
        break;

    case 0x73: // ld (hl), e
        write(rHL, rE);
        break;

    case 0x74: // ld (hl), h
        write(rHL, rH);
        break;

    case 0x75: // ld (hl), l
        write(rHL, rL);
        break;

    case 0x76: // halt
        S(HALT) = 1;
        break;

    case 0x77: // ld (hl), a
        write(rHL, rA);
        break;

    case 0x78: // ld a, b
        rA = rB;
        break;

    case 0x79: // ld a, c
        rA = rC;
        break;

    case 0x7A: // ld a, d
        rA = rD;
        break;

    case 0x7B: // ld a, e
        rA = rE;
        break;

    case 0x7C: // ld a, h
        rA = rH;
        break;

    case 0x7D: // ld a, l
        rA = rL;
        break;

    case 0x7E: // ld a, (hl)
        rA = read(rHL);
        break;

    case 0x7F: // ld a, a
        rA = rA;
        break;

    case 0x80: // add a, b
        add(rB);
        break;

    case 0x81: // add a, c
        add(rC);
        break;

    case 0x82: // add a, d
        add(rD);
        break;

    case 0x83: // add a, e
        add(rE);
        break;

    case 0x84: // add a, h
        add(rH);
        break;

    case 0x85: // add a, l
        add(rL);
        break;

    case 0x86: // add a, (hl)
        tmp = read(rHL);
        add(tmp);
        break;

    case 0x87: // add a, a
        add(rA);
        break;

    case 0x88: // adc a, b
        adc(rB);
        break;

    case 0x89: // adc a, c
        adc(rC);
        break;

    case 0x8A: // adc a, d
        adc(rD);
        break;

    case 0x8B: // adc a, e
        adc(rE);
        break;

    case 0x8C: // adc a, h
        adc(rH);
        break;

    case 0x8D: // adc a, l
        adc(rL);
        break;

    case 0x8E: // adc a, (hl)
        tmp = read(rHL);
        adc(tmp);
        break;

    case 0x8F: // adc a, a
        adc(rA);
        break;

    case 0x90: // sub b
        sub(rB);
        break;

    case 0x91: // sub c
        sub(rC);
        break;

    case 0x92: // sub d
        sub(rD);
        break;

    case 0x93: // sub e
        sub(rE);
        break;

    case 0x94: // sub h
        sub(rH);
        break;

    case 0x95: // sub l
        sub(rL);
        break;

    case 0x96: // sub (hl)
        tmp = read(rHL);
        sub(tmp);
        break;

    case 0x97: // sub a
        sub(rA);
        break;

    case 0x98: // sbc a, b
        sbc(rB);
        break;

    case 0x99: // sbc a, c
        sbc(rC);
        break;

    case 0x9A: // sbc a, d
        sbc(rD);
        break;

    case 0x9B: // sbc a, e
        sbc(rE);
        break;

    case 0x9C: // sbc a, h
        sbc(rH);
        break;

    case 0x9D: // sbc a, l
        sbc(rL);
        break;

    case 0x9E: // sbc a, (hl)
        tmp = read(rHL);
        sbc(tmp);
        break;

    case 0x9F: // sbc a, a
        sbc(rA);
        break;

    case 0xA0: // and b
        and(rB);
        break;

    case 0xA1: // and c
        and(rC);
        break;

    case 0xA2: // and d
        and(rD);
        break;

    case 0xA3: // and e
        and(rE);
        break;

    case 0xA4: // and h
        and(rH);
        break;

    case 0xA5: // and l
        and(rL);
        break;

    case 0xA6: // and (hl)
        tmp = read(rHL);
        and(tmp);
        break;

    case 0xA7: // and a
        and(rA);
        break;

    case 0xA8: // xor b
        xor(rB);
        break;

    case 0xA9: // xor c
        xor(rC);
        break;

    case 0xAA: // xor d
        xor(rD);
        break;

    case 0xAB: // xor e
        xor(rE);
        break;

    case 0xAC: // xor h
        xor(rH);
        break;

    case 0xAD: // xor l
        xor(rL);
        break;

    case 0xAE: // xor (hl)
        tmp = read(rHL);
        xor(tmp);
        break;

    case 0xAF: // xor a
        xor(rA);
        break;

    case 0xB0: // or b
        or(rB);
        break;

    case 0xB1: // or c
        or(rC);
        break;

    case 0xB2: // or d
        or(rD);
        break;

    case 0xB3: // or e
        or(rE);
        break;

    case 0xB4: // or h
        or(rH);
        break;

    case 0xB5: // or l
        or(rL);
        break;

    case 0xB6: // or (hl)
        tmp = read(rHL);
        or(tmp);
        break;

    case 0xB7: // or a
        or(rA);
        break;

    case 0xB8: // cp b
        cp(rB);
        break;

    case 0xB9: // cp c
        cp(rC);
        break;

    case 0xBA: // cp d
        cp(rD);
        break;

    case 0xBB: // cp e
        cp(rE);
        break;

    case 0xBC: // cp h
        cp(rH);
        break;

    case 0xBD: // cp l
        cp(rL);
        break;

    case 0xBE: // cp (hl)
        tmp = read(rHL);
        cp(tmp);
        break;

    case 0xBF: // cp a
        cp(rA);
        break;

    case 0xC0: // ret nz
        t_states(1);
        if (!(rF & fZ)) {
            rPC = pop_16();
        }
        break;

    case 0xC1: // pop bc
        rBC = pop_16();
        break;

    case 0xC2: // jp nz, **
        addr = arg_16();
        if (!(rF & fZ)) {
            rPC = addr;
        }
        break;

    case 0xC3: // jp **
        rPC = arg_16();
        break;

    case 0xC4: // call nz, **
        addr = arg_16();
        if (!(rF & fZ)) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xC5: // push bc
        t_states(1);
        push_16(rBC);
        break;

    case 0xC6: // add a, *
        tmp = arg();
        add(tmp);
        break;

    case 0xC7: // rst 00h
        t_states(1);
        push_16(rPC);
        rPC = 0x00;
        break;

    case 0xC8: // ret z
        t_states(1);
        if (rF & fZ) {
            rPC = pop_16();
        }
        break;

    case 0xC9: // ret
        rPC = pop_16();
        break;

    case 0xCA: // jp z, **
        addr = arg_16();
        if (rF & fZ) {
            rPC = addr;
        }
        break;

    case 0xCB: // ext cb
        cmd_cb();
        break;

    case 0xCC: // call z, **
        addr = arg_16();
        if (rF & fZ) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xCD: // call **
        addr = arg_16();
        t_states(1);
        push_16(rPC);
        rPC = addr;
        break;

    case 0xCE: // adc a, *
        tmp = arg();
        adc(tmp);
        break;

    case 0xCF: // rst 08h
        t_states(1);
        push_16(rPC);
        rPC = 0x08;
        break;

    case 0xD0: // ret nc
        t_states(1);
        if (!(rF & fC)) {
            rPC = pop_16();
        }
        break;

    case 0xD1: // pop de
        rDE = pop_16();
        break;

    case 0xD2: // jp nc, **
        addr = arg_16();
        if (!(rF & fC)) {
            rPC = addr;
        }
        break;

    case 0xD3: // out (*), a
        tmp = arg();
        out((rA << 8) | tmp, rA);
        break;

    case 0xD4: // call nc, **
        addr = arg_16();
        if (!(rF & fC)) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xD5: // push de
        t_states(1);
        push_16(rDE);
        break;

    case 0xD6: // sub *
        tmp = arg();
        sub(tmp);
        break;

    case 0xD7: // rst 10h
        t_states(1);
        push_16(rPC);
        rPC = 0x10;
        break;

    case 0xD8: // ret c
        t_states(1);
        if (rF & fC) {
            rPC = pop_16();
        }
        break;

    case 0xD9: // exx
        swap_16(rBC, rBC_);
        swap_16(rDE, rDE_);
        swap_16(rHL, rHL_);
        break;

    case 0xDA: // jp c, **
        addr = arg_16();
        if (rF & fC) {
            rPC = addr;
        }
        break;

    case 0xDB: // in a, (*)
        tmp = arg();
        rA = in((rA << 8) | tmp);
        break;

    case 0xDC: // call c, **
        addr = arg_16();
        if (rF & fC) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xDD: // ext dd
        cmd_dd();
        break;

    case 0xDE: // sbc a, *
        tmp = arg();
        sbc(tmp);
        break;

    case 0xDF: // rst 18h
        t_states(1);
        push_16(rPC);
        rPC = 0x18;
        break;

    case 0xE0: // ret po
        t_states(1);
        if (!(rF & fP)) {
            rPC = pop_16();
        }
        break;

    case 0xE1: // pop hl
        rHL = pop_16();
        break;

    case 0xE2: // jp po, **
        addr = arg_16();
        if (!(rF & fP)) {
            rPC = addr;
        }
        break;

    case 0xE3: // ex (sp), hl
        tmp_16 = pop_16();
        t_states(1);
        push_16(rHL);
        t_states(2);
        rHL = tmp_16;
        break;

    case 0xE4: // call po, **
        addr = arg_16();
        if (!(rF & fP)) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xE5: // push hl
        t_states(1);
        push_16(rHL);
        break;

    case 0xE6: // and *
        tmp = arg();
        and(tmp);
        break;

    case 0xE7: // rst 20h
        t_states(1);
        push_16(rPC);
        rPC = 0x20;
        break;

    case 0xE8: // ret pe
        t_states(1);
        if (rF & fP) {
            rPC = pop_16();
        }
        break;

    case 0xE9: // jp (hl)
        rPC = rHL;
        break;

    case 0xEA: // jp pe, **
        addr = arg_16();
        if (rF & fP) {
            rPC = addr;
        }
        break;

    case 0xEB: // ex de, hl
        swap_16(rDE, rHL);
        break;

    case 0xEC: // call pe, **
        addr = arg_16();
        if (rF & fP) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xED: // ext ed
        cmd_ed();
        break;

    case 0xEE: // xor *
        tmp = arg();
        xor(tmp);
        break;

    case 0xEF: // rst 28h
        t_states(1);
        push_16(rPC);
        rPC = 0x28;
        break;

    case 0xF0: // ret p
        t_states(1);
        if (!(rF & fS)) {
            rPC = pop_16();
        }
        break;

    case 0xF1: // pop af
        rAF = pop_16();
        break;

    case 0xF2: // jp p, **
        addr = arg_16();
        if (!(rF & fS)) {
            rPC = addr;
        }
        break;

    case 0xF3: // di
        S(IFF1) = S(IFF2) = 0;
        break;

    case 0xF4: // call p, **
        addr = arg_16();
        if (!(rF & fS)) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xF5: // push af
        t_states(1);
        push_16(rAF);
        break;

    case 0xF6: // or *
        tmp = arg();
        or(tmp);
        break;

    case 0xF7: // rst 30h
        t_states(1);
        push_16(rPC);
        rPC = 0x30;
        break;

    case 0xF8: // ret m
        t_states(1);
        if (rF & fS) {
            rPC = pop_16();
        }
        break;

    case 0xF9: // ld sp, hl
        t_states(2);
        rSP = rHL;
        break;

    case 0xFA: // jp m, **
        addr = arg_16();
        if (rF & fS) {
            rPC = addr;
        }
        break;

    case 0xFB: // ei
        S(IFF1) = S(IFF2) = 1;
        break;

    case 0xFC: // call m, **
        addr = arg_16();
        if (rF & fS) {
            t_states(1);
            push_16(rPC);
            rPC = addr;
        }
        break;

    case 0xFD: // ext fd
        cmd_fd();
        break;

    case 0xFE: // cp *
        tmp = arg();
        cp(tmp);
        break;

    case 0xFF: // rst 38h
        t_states(1);
        push_16(rPC);
        rPC = 0x38;
        break;
    }
}
