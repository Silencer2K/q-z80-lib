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

#include <stdlib.h>
#include <memory.h>

#include "z80.h"

// initialization

Z80_State *Z80_Init(void *data, Z80_Read_CB *read, Z80_Read_IO_CB *read_io, Z80_Write_CB *write, Z80_Write_IO_CB *write_io)
{
    Z80_State *state = malloc(sizeof(Z80_State));

    if (!state) return NULL;

    memset(state, 0, sizeof(Z80_State));
    memset(&state->regs, -1, sizeof(Z80_Regs));

    state->data = data;

    state->read = read;
    state->read_io = read_io;
    state->write = write;
    state->write_io = write_io;

    Z80_Reset(state);

    return state;
}

void Z80_Free(Z80_State *state)
{
    free(state);
}

// control

void Z80_Reset(Z80_State *state)
{
    state->T += 3;

    state->regs.PC = 0;

    state->IFF1 = state->IFF2 = 0;
    state->IM = 0;
    state->HALT = 0;
}

void Z80_NMI(Z80_State *state)
{
    state->HALT = 0;
}

void Z80_IRQ(Z80_State *state, unsigned n_bytes, ...)
{
    state->HALT = 0;
}

void Z80_Trace(Z80_State *state)
{
    state->regs.PC_ = state->regs.PC;
    Z80_Exec(state, Z80_Fetch_Cmd(state));
}

void Z80_Repeat(Z80_State *state)
{
    state->regs.PC = state->regs.PC_;
}

void Z80_Run(Z80_State *state, unsigned n_clocks)
{
    unsigned t = state->T;
    while (state->T - t < n_clocks)
        Z80_Trace(state);
}

// memory and io

uint8_t Z80_Read(Z80_State *state, uint16_t addr)
{
    state->T += 3;
    return state->read(state->data, addr);
}

uint16_t Z80_Read_16(Z80_State *state, uint16_t addr)
{
    Z80_R16_HL(r16, r8h, r8l) tmp;

    tmp.r8l = Z80_Read(state, addr);
    tmp.r8h = Z80_Read(state, addr + 1);

    return tmp.r16;
}

uint8_t Z80_Read_IO(Z80_State *state, uint16_t addr)
{
    state->T += 1;
    uint8_t value = state->read_io(state->data, addr);
    state->T += 3;

    return value;
}

uint8_t Z80_Fetch_Cmd(Z80_State *state)
{
    state->regs.R = (state->regs.R & 0x80) | ((state->regs.R + 1) & 0x7F);
    state->T += 4;
    return state->read(state->data, state->regs.PC++);
}

uint8_t Z80_Fetch_Arg(Z80_State *state)
{
    state->T += 3;
    return state->read(state->data, state->regs.PC++);
}

uint16_t Z80_Fetch_Arg_16(Z80_State *state)
{
    Z80_R16_HL(r16, r8h, r8l) tmp;

    tmp.r8l = Z80_Fetch_Arg(state);
    tmp.r8h = Z80_Fetch_Arg(state);

    return tmp.r16;
}

uint8_t Z80_Pop(Z80_State *state)
{
    state->T += 3;
    return state->read(state->data, state->regs.SP++);
}

uint16_t Z80_Pop_16(Z80_State *state)
{
    Z80_R16_HL(r16, r8h, r8l) tmp;

    tmp.r8l = Z80_Pop(state);
    tmp.r8h = Z80_Pop(state);

    return tmp.r16;
}

void Z80_Write(Z80_State *state, uint16_t addr, uint8_t value)
{
    state->T += 3;
    state->write(state->data, addr, value);
}

void Z80_Write_16(Z80_State *state, uint16_t addr, uint16_t value)
{
    Z80_Write(state, addr, value & 255);
    Z80_Write(state, addr + 1, (value >> 8) & 255);
}

void Z80_Write_IO(Z80_State *state, uint16_t addr, uint8_t value)
{
    state->T += 1;
    state->write_io(state->data, addr, value);
    state->T += 3;
}

void Z80_Push(Z80_State *state, uint8_t value)
{
    state->T += 3;
    state->write(state->data, --state->regs.SP, value);
}

void Z80_Push_16(Z80_State *state, uint16_t value)
{
    Z80_Push(state, (value >> 8) & 255);
    Z80_Push(state, value & 255);
}
