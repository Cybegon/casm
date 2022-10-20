#include "casm.h"
#include "casm_p.h"
#include "config.h"

#include "libsl/config.h"
#include "libsl/lexer.h"

CASMContext* casm_initContext(SLLexerContext* slLexerContext)
{
    CASMContext* ctx = (CASMContext*)SL_MALLOC( sizeof( CASMContext ) );
    SL_BZERO( ctx, sizeof(CASMContext) );

    ctx->labels     = (CASMLabel*)SL_MALLOC( sizeof( CASMLabel ) * MIN_LABEL_COUNT );
    ctx->opcodes    = (CASMOpcode*)SL_MALLOC( sizeof( CASMOpcode ) * MIN_OPCODE_COUNT );

    if ( slLexerContext != NULL ) {
        ctx->in.slLexerContext = slLexerContext;
    } else {
        // buf
    }

    return ctx;
}

