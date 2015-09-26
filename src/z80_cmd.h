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

#ifndef _Z80_CMD_H
#define _Z80_CMD_H

#include "z80.h"

#ifdef __cplusplus
extern "C" {
#ifndef __cplusplus
}
#endif
#endif

#define S(s)    state->s
#define R(r)    S(regs.r)

#define rA      R(A)
#define rF      R(F)
#define rB      R(B)
#define rC      R(C)
#define rD      R(D)
#define rE      R(E)
#define rH      R(H)
#define rL      R(L)

#define rIXH    R(IXH)
#define rIXL    R(IXL)
#define rIYH    R(IYH)
#define rIYL    R(IYL)

#define rAF     R(AF)
#define rBC     R(BC)
#define rDE     R(DE)
#define rHL     R(HL)

#define rAF_    R(AF_)
#define rBC_    R(BC_)
#define rDE_    R(DE_)
#define rHL_    R(HL_)

#define rIX     R(IX)
#define rIY     R(IY)

#define rSP     R(SP)
#define rPC     R(PC)

#define rI      R(I)
#define rR      R(R)

#define t_states(t)     state->T += t

#define read(a)         Z80_Read(state, a)          // t_states = 3
#define read_16(a)      Z80_Read_16(state, a)       // t_states = 6

#define in(a)           Z80_Read_IO(state, a)       // t_states = 4

#define arg()           Z80_Fetch_Arg(state)        // t_states = 3
#define arg_16()        Z80_Fetch_Arg_16(state)     // t_states = 6

#define pop_16()        Z80_Pop_16(state)           // t_states = 6

#define write(a, v)     Z80_Write(state, a, v)      // t_states = 3
#define write_16(a, v)  Z80_Write_16(state, a, v)   // t_states = 6

#define out(a, v)       Z80_Write_IO(state, a, v)   // t_states = 4

#define push_16(v)      Z80_Push_16(state, v)       // t_states = 6

#define swap_16(a, b)   tmp_16 = a; a = b; b = tmp_16;

#define cmd_cb()        Z80_Exec_CB(state, Z80_Fetch_Cmd(state))
#define cmd_ed()        Z80_Exec_ED(state, Z80_Fetch_Cmd(state))

#define cmd_dd()        Z80_Exec_DD(state, Z80_Fetch_Cmd(state))
#define cmd_fd()        Z80_Exec_FD(state, Z80_Fetch_Cmd(state))

#define cmd_ddcb()      tmp = arg(); Z80_Exec_DDCB(state, arg(), tmp);
#define cmd_fdcb()      tmp = arg(); Z80_Exec_FDCB(state, arg(), tmp);

#define rep()           Z80_Repeat(state);

static __inline int P(uint8_t value)
{
    uint8_t parity = value;

    parity ^= parity >> 4;
    parity ^= parity >> 2;
    parity ^= parity >> 1;

    return parity & 1 ? 0 : 1;
}

#define scf()\
{\
    rF =\
        (rF & (fP | fZ | fS)) |\
        fC |\
        (rA & (f3 | f5));\
}

#define ccf()\
{\
    rF =\
        (rF & (fP | fZ | fS)) |\
        (rA & (f3 | f5)) |\
        (rF & fC ? fH : fC);\
}

#define inc(r)\
{\
    r++;\
    rF =\
        (rF & fC) |\
        (r & (f3 | f5 | fS)) |\
        (r == 128 ? fP : 0) |\
        ((r & 15) == 0 ? fH : 0) |\
        (!r ? fZ : 0);\
}

#define dec(r)\
{\
    r--;\
    rF =\
        (rF & fC) |\
        fN |\
        (r & (f3 | f5 | fS)) |\
        (r == 127 ? fP : 0) |\
        ((r & 15) == 15 ? fH : 0) |\
        (!r ? fZ : 0);\
}

#define add(v)\
{\
    unsigned res = rA + v;\
    unsigned carry = rA ^ v ^ res;\
    rA = res;\
    rF =\
        (rA & (f3 | f5 | fS)) |\
        (carry & 256 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 128 ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!rA ? fZ : 0);\
}

#define adc(v)\
{\
    unsigned res = rA + v + (rF & fC ? 1 : 0);\
    unsigned carry = rA ^ v ^ res;\
    rA = res;\
    rF =\
        (rA & (f3 | f5 | fS)) |\
        (carry & 256 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 128 ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!rA ? fZ : 0);\
}

#define sub(v)\
{\
    unsigned res = rA - v;\
    unsigned carry = rA ^ v ^ res;\
    rA = res;\
    rF =\
        fN |\
        (rA & (f3 | f5 | fS)) |\
        (carry & 256 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 128 ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!rA ? fZ : 0);\
}

#define sbc(v)\
{\
    unsigned res = rA - v - (rF & fC ? 1 : 0);\
    unsigned carry = rA ^ v ^ res;\
    rA = res;\
    rF =\
        fN |\
        (rA & (f3 | f5 | fS)) |\
        (carry & 256 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 128 ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!rA ? fZ : 0);\
}

#define and(v)\
{\
    rA &= v;\
    rF =\
        fH |\
        (rA & (f3 | f5 | fS)) |\
        (P(rA) ? fP : 0) |\
        (!rA ? fZ : 0);\
}

#define xor(v)\
{\
    rA ^= v;\
    rF =\
        (rA & (f3 | f5 | fS)) |\
        (P(rA) ? fP : 0) |\
        (!rA ? fZ : 0);\
}

#define or(v)\
{\
    rA |= v;\
    rF =\
        (rA & (f3 | f5 | fS)) |\
        (P(rA) ? fP : 0) |\
        (!rA ? fZ : 0);\
}

#define cp(v)\
{\
    unsigned res = rA - v;\
    unsigned carry = rA ^ v ^ res;\
    rF =\
        fN |\
        (v & (f3 | f5)) |\
        (res & fS) |\
        (carry & 256 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 128 ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!(res & 255) ? fZ : 0);\
}

#define rlca()\
{\
    rA = (rA << 1) | (rA & 128 ? 1 : 0);\
    rF =\
        (rF & (fP | fZ | fS)) |\
        (rA & (f3 | f5)) |\
        (rA & 1 ? fC : 0);\
}

#define rrca()\
{\
    rA = (rA >> 1) | (rA & 1 ? 128 : 0);\
    rF =\
        (rF & (fP | fZ | fS)) |\
        (rA & (f3 | f5)) |\
        (rA & 128 ? fC : 0);\
}

#define rla()\
{\
    unsigned res = (rA << 1) | (rF & fC ? 1 : 0);\
    rA = res;\
    rF =\
        (rF & (fP | fZ | fS)) |\
        (rA & (f3 | f5)) |\
        (res & 256 ? fC : 0);\
}

#define rra()\
{\
    unsigned res = rA | (rF & fC ? 256 : 0);\
    rA = res >> 1;\
    rF =\
        (rF & (fP | fZ | fS)) |\
        (rA & (f3 | f5)) |\
        (res & 1 ? fC : 0);\
}

#define daa()\
{\
    unsigned value =\
        (rA > 0x99 || (rF & fC) ? 0x60 : 0) |\
        ((rA & 15) > 9 || (rF & fH) ? 6 : 0);\
    unsigned res = (rF & fN) ? rA - value : rA + value;\
    unsigned carry = rA ^ res;\
    rA = res;\
    rF =\
        (rF & fN) |\
        (rA & (f3 | f5 | fS)) |\
        ((value & 240) ? fC : 0) |\
        ((carry & 16) ? fH : 0) |\
        (!rA ? fZ : 0);\
}

#define cpl()\
{\
    rA = ~rA;\
    rF =\
        (rF & (fC | fP | fS | fZ)) |\
        fN | fH |\
        (rA & (f3 | f5));\
}

#define neg()\
{\
    unsigned res = -rA;\
    unsigned carry = rA ^ res;\
    rA = res;\
    rF =\
        (rA & (f3 | f5 | fS)) |\
        fN |\
        (carry & 256 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 128 ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!rA ? fZ : 0);\
}

#define rld(r)\
{\
    unsigned res =\
        ((rA & 240) << 8) |\
        (r << 4) |\
        (rA & 15);\
    rA = (res >> 8) & 255;\
    r = res & 255;\
    rF =\
        (rF & fC) |\
        (rA & (fS | f3 | f5)) |\
        (P(rA) ? fP : 0) |\
        (!rA ? fZ : 0);\
}

#define rrd(r)\
{\
    unsigned res =\
        ((rA & 240) << 8) |\
        ((r & 15) << 8) |\
        ((rA & 15) << 4) |\
        ((r & 240) >> 4);\
    rA = (res >> 8) & 255;\
    r = res & 255;\
    rF =\
        (rF & fC) |\
        (rA & (fS | f3 | f5)) |\
        (P(rA) ? fP : 0) |\
        (!rA ? fZ : 0);\
}

#define rlc(r)\
{\
    r = (r << 1) | (r & 128 ? 1 : 0);\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (r & 1 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define rrc(r)\
{\
    r = (r >> 1) | (r & 1 ? 128 : 0);\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (r & 128 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define rl(r)\
{\
    unsigned res = (r << 1) | (rF & fC ? 1 : 0);\
    r = res;\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (res & 256 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define rr(r)\
{\
    unsigned res = r | (rF & fC ? 256 : 0);\
    r = res >> 1;\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (res & 1 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define sla(r)\
{\
    unsigned res = r << 1;\
    r = res;\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (res & 256 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define sra(r)\
{\
    unsigned res = r | (r & 128 ? 256 : 0);\
    r = res >> 1;\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (res & 1 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define sll(r)\
{\
    unsigned res = r << 1 | 1;\
    r = res;\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (res & 256 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define srl(r)\
{\
    unsigned res = r;\
    r = res >> 1;\
    rF =\
        (r & (f3 | f5 | fS)) |\
        (res & 1 ? fC : 0) |\
        (P(r) ? fP : 0) |\
        (!r ? fZ : 0);\
}

#define bit(r, n)\
{\
    unsigned res = r & (1 << n);\
    rF =\
        (rF & fC) |\
        fH |\
        (r & (f3 | f5)) |\
        (res & fS) |\
        (!res ? fP | fZ : 0);\
}

#define bit_a(r, n, a)\
{\
    unsigned res = r & (1 << n);\
    rF =\
        (rF & fC) |\
        fH |\
        ((a >> 8) & (f3 | f5)) |\
        (res & fS) |\
        (!res ? fP | fZ : 0);\
}

#define set(r, n)\
{\
    r |= 1 << n;\
}

#define res(r, n)\
{\
    r &= ~(1 << n);\
}

#define add_16(r, v)\
{\
    unsigned res = r + v;\
    unsigned carry = r ^ v ^ res;\
    r = res;\
    rF =\
        (rF & (fP | fZ | fS)) |\
        ((r >> 8) & (f3 | f5)) |\
        (carry & 65536 ? fC : 0) |\
        (carry & 4096 ? fH : 0);\
}

#define adc_16(r, v)\
{\
    unsigned res = r + v + (rF & fC ? 1 : 0);\
    unsigned carry = r ^ v ^ res;\
    r = res;\
    rF =\
        ((r >> 8) & (f3 | f5 | fS)) |\
        (carry & 65536 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 32768 ? fP : 0) |\
        (carry & 4096 ? fH : 0) |\
        (!r ? fZ : 0);\
}

#define sbc_16(r, v)\
{\
    unsigned res = r - v - (rF & fC ? 1 : 0);\
    unsigned carry = r ^ v ^ res;\
    r = res;\
    rF =\
        fN |\
        ((r >> 8) & (f3 | f5 | fS)) |\
        (carry & 65536 ? fC : 0) |\
        (((carry >> 1) ^ carry) & 32768 ? fP : 0) |\
        (carry & 4096 ? fH : 0) |\
        (!r ? fZ : 0);\
}

#define ld_f(v)\
{\
    rF =\
        (rF & fC) |\
        (v & (f3 | f5 | fS)) |\
        (S(IFF2) ? fP : 0) |\
        (!v ? fZ : 0);\
}

#define in_f(v)\
{\
    rF =\
        (rF & fC) |\
        (v & (f3 | f5 | fS)) |\
        (P(v) ? fP : 0) |\
        (!v ? fZ : 0);\
}

#define ldr_f(v)\
{\
    unsigned f35 = rA + v;\
    rF =\
        (rF & (fC | fZ | fS)) |\
        (rBC ? fP : 0) |\
        (f35 & f3) |\
        ((f35 & 2) ? f5 : 0);\
}

#define cpr_f(v)\
{\
    unsigned res = rA - v;\
    unsigned carry = rA ^ v ^ res;\
    unsigned f35 = res - (carry & 16 ? 1 : 0);\
    rF =\
        (rF & fC) |\
        fN |\
        (rBC ? fP : 0) |\
        (carry & 16 ? fH : 0) |\
        (!(res & 255) ? fZ : 0) |\
        (res & fS) |\
        (f35 & f3) |\
        ((f35 & 2) ? f5 : 0);\
}

#define indr_f(v)\
{\
    uint8_t c = (rC - 1) & 255;\
    rF =\
        (rB & (f3 | f5 | fS)) |\
        (!rB ? fZ : 0) |\
        ((v & 128) ? fN : 0) |\
        (P(((v + c) & 7) ^ rB) ? fP : 0) |\
        (((v + c) & 256) ? fH | fC : 0);\
}

#define inir_f(v)\
{\
    uint8_t c = (rC + 1) & 255;\
    rF =\
        (rB & (f3 | f5 | fS)) |\
        (!rB ? fZ : 0) |\
        ((v & 128) ? fN : 0) |\
        (P(((v + c) & 7) ^ rB) ? fP : 0) |\
        (((v + c) & 256) ? fH | fC : 0);\
}

#define outr_f(v)\
{\
    rF =\
        (rB & (f3 | f5 | fS)) |\
        (!rB ? fZ : 0) |\
        ((v & 128) ? fN : 0) |\
        (P(((v + rL) & 7) ^ rB) ? fP : 0) |\
        (((v + rL) & 256) ? fH | fC : 0);\
}

#ifdef __cplusplus
#ifndef __cplusplus
{
#endif
}
#endif

#endif //_Z80_CMD_H
