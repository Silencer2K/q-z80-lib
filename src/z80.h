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

#ifndef _Z80_H
#define _Z80_H

#include <stdint.h>

#define Z80_R16(r16)                union { uint16_t r16; unsigned e##r16; }
#define Z80_R16_HL(r16, r8h, r8l)   union { uint16_t r16; struct { uint8_t r8l, r8h; }; unsigned e##r16; }
#define Z80_R8(r8)                  union { uint8_t r8; unsigned e##r8; }

#define fC      1
#define fN      2
#define fP      4
#define f3      8
#define fH      16
#define f5      32
#define fZ      64
#define fS      128

struct Z80_Regs
{
    Z80_R16_HL(AF, A, F);
    Z80_R16_HL(BC, B, C);
    Z80_R16_HL(DE, D, E);
    Z80_R16_HL(HL, H, L);

    Z80_R16(AF_);
    Z80_R16(BC_);
    Z80_R16(DE_);
    Z80_R16(HL_);

    Z80_R16_HL(IX, IXH, IXL);
    Z80_R16_HL(IY, IYH, IYL);

    Z80_R16(SP);
    Z80_R16(PC);

    Z80_R8(I);
    Z80_R8(R);

    Z80_R16(PC_);
};

typedef struct Z80_Regs Z80_Regs;

typedef uint8_t(Z80_Read_CB)(void *data, uint16_t addr);
typedef uint8_t(Z80_Read_IO_CB)(void *data, uint16_t addr);

typedef void(Z80_Write_CB)(void *data, uint16_t addr, uint8_t value);
typedef void(Z80_Write_IO_CB)(void *data, uint16_t addr, uint8_t value);

struct Z80_State
{
    Z80_Regs regs;

    unsigned T;

    unsigned IFF1, IFF2;
    unsigned IM;

    unsigned HALT;

    void *data;

    Z80_Read_CB *read;
    Z80_Read_IO_CB *read_io;

    Z80_Write_CB *write;
    Z80_Write_IO_CB *write_io;
};

typedef struct Z80_State Z80_State;

// initialization

Z80_State *Z80_Init(void *data, Z80_Read_CB *read, Z80_Read_IO_CB *read_io, Z80_Write_CB *write, Z80_Write_IO_CB *write_io);

void Z80_Free(Z80_State *state);

// control

void Z80_Reset(Z80_State *state);

void Z80_NMI(Z80_State *state);
void Z80_IRQ(Z80_State *state, unsigned n_bytes, ...);

void Z80_Trace(Z80_State *state);
void Z80_Repeat(Z80_State *state);

void Z80_Run(Z80_State *state, unsigned n_clocks);

// memory and io

uint8_t Z80_Read(Z80_State *state, uint16_t addr);
uint16_t Z80_Read_16(Z80_State *state, uint16_t addr);

uint8_t Z80_Read_IO(Z80_State *state, uint16_t addr);

uint8_t Z80_Fetch_Cmd(Z80_State *state);

uint8_t Z80_Fetch_Arg(Z80_State *state);
uint16_t Z80_Fetch_Arg_16(Z80_State *state);

uint8_t Z80_Pop(Z80_State *state);
uint16_t Z80_Pop_16(Z80_State *state);

void Z80_Write(Z80_State *state, uint16_t addr, uint8_t value);
void Z80_Write_16(Z80_State *state, uint16_t addr, uint16_t value);

void Z80_Write_IO(Z80_State *state, uint16_t addr, uint8_t value);

void Z80_Push(Z80_State *state, uint8_t value);
void Z80_Push_16(Z80_State *state, uint16_t value);

// execute

void Z80_Exec(Z80_State *state, uint8_t opcode);

void Z80_Exec_CB(Z80_State *state, uint8_t opcode);
void Z80_Exec_ED(Z80_State *state, uint8_t opcode);

void Z80_Exec_DD(Z80_State *state, uint8_t opcode);
void Z80_Exec_FD(Z80_State *state, uint8_t opcode);

void Z80_Exec_DDCB(Z80_State *state, uint8_t opcode, int8_t offset);
void Z80_Exec_FDCB(Z80_State *state, uint8_t opcode, int8_t offset);

#endif //_Z80_H
