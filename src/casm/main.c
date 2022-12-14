#include <stdlib.h>

#include "libsl/reader.h"
#include "libsl/lexer.h"

#include "lex.h"
#include "casm.h"

const SLLexStage lexStageLst[] = {
        sl_skipAnyWhitespace,
        sl_setLocation,
        casm_lexemeHandler,
        sl_mathString,
        sl_matchNumber,
        sl_checkEOF,
        sl_retASCII,
        NULL
};

const SLLexList lexList[] = {
        SL_SET_LEXEME("bits", T_DIRECTIVE, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("section", T_DIRECTIVE, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("global", T_DIRECTIVE, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("extern", T_DIRECTIVE, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("db", T_DIRECTIVE, SL_TOKEN_INFO_NONE, NULL),

        // Base
        SL_SET_LEXEME("mov", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("push", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("pop", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("swp", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("ld", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("st", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("bk", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        // Interrupts
        SL_SET_LEXEME("hwi", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("swi", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        // Special
        SL_SET_LEXEME("enter", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("leave", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("inv", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        // Integer arithmetic
        SL_SET_LEXEME("add", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("sub", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("inc", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("dec", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("mul", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("div", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("imul", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("idiv", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("mod", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("shl", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("shr", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("rol", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("ror", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        // Logic
        SL_SET_LEXEME("and", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("nand", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("or", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("nor", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("xor", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("not", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("neg", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        // Compare
        SL_SET_LEXEME("cmp", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("icmp", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        // Flow
        SL_SET_LEXEME("jmp", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jeq", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jne", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jle", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jge", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jlt", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jgt", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("hls", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jhs", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jlo", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("jhi", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("call", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("ceq", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("cne", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("cle", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("cge", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("clt", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("cgt", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("cls", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("chs", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("clo", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),
        SL_SET_LEXEME("chi", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        SL_SET_LEXEME("ret", T_KEYWORD, SL_TOKEN_INFO_NONE, NULL),

        SL_END_LEXEME
};

int main(int argc, char* argv[])
{
    SLLexerContext* ctx;
    ctx = sl_createLexerContext(lexList, lexStageLst);

    sl_openFile(ctx, "dvm.asm");

    for (SLToken token = sl_getNextToken(ctx); token.type != T_EOF; token = sl_getNextToken(ctx)) {
        switch (token.type) {
            case T_IDENTIFIER: case T_KEYWORD: case T_STRING: case T_DIRECTIVE:
            case T_LABEL: {
                printf("%s name: %s\n", sl_getTokenType(ctx, token).data, token.identString);
                break;
            }
            case T_CONSTANT: {
                if (token.tokenInfo == 1)
                    printf("%s name: %s\n", sl_getTokenType(ctx, token).data, token.identString);
                else
                    printf("%s value: %f\n", sl_getTokenType(ctx, token).data, token.value);
                break;
            }
            default: {
                printf("%s\n", sl_getTokenType(ctx, token).data);
                break;
            }
        }

        if (token.type == T_IDENTIFIER || token.type == T_STRING)
            free(token.identString);
    }

    sl_closeFile(ctx);
    sl_freeLexerContext(ctx);

    return 0;
}
