#ifndef CASM_CASM_H
#define CASM_CASM_H

#include "datatypes.h"

typedef struct SLLexerContext SLLexerContext;

typedef enum CASMLabelType CASMLabelType;

typedef struct CASMContext CASMContext;
typedef struct CASMLabel CASMLabel;
typedef struct CASMOpcode CASMOpcode;

CASMContext* casm_initContext();



#endif //CASM_CASM_H
