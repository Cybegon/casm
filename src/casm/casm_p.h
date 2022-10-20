#ifndef CASM_CASM_P_H
#define CASM_CASM_P_H

#include "datatypes.h"

#include "casm.h"
#include "config.h"

struct CASMContext {
    CASMLabel*  labels;
    CASMOpcode* opcodes;

    union {
        struct {
            char*   buffer;
            duint64 bufferSize;
            duint64 cursor;
        } buf;

        SLLexerContext* slLexerContext;
    } in;


    struct {
        char*   buffer;
        duint64 bufferSize;
        duint64 cursor;
    } out;
};

enum CASMLabelType {
    LT_NONE,
    LT_LOCAL,
    LT_GLOBAL
};

struct CASMLabel {
    CASMLabelType   type;
    char*           name;
    duint64         address;
};

struct CASMOpcode {
    dsize       size;
    OPCODE_T    opcode;
};

#endif //CASM_CASM_P_H
