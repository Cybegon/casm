#include "lex.h"

#include "libsl/reader.h"
#include "libsl/lexer.h"

dint casm_lexemeHandler(SLLexerContext* ctx, SLToken* token)
{
    if (isalpha(ctx->LastChar) || ctx->LastChar == '.' || ctx->LastChar == '_') { // [a-zA-Z.][a-zA-Z0-9_:]*
        memset(ctx->IdentifierStr.data, 0, ctx->IdentifierStr.len);
        ctx->IdentifierStr.len = 0;

        ctx->IdentifierStr.data[ctx->IdentifierStr.len++] = (char)ctx->LastChar;

        while (isalnum((ctx->LastChar = sl_advance(ctx))) || ctx->LastChar == '_')
            ctx->IdentifierStr.data[ctx->IdentifierStr.len++] = (char)ctx->LastChar;

        if (ctx->LastChar == ':') {
            ctx->IdentifierStr.data[ctx->IdentifierStr.len++] = (char)ctx->LastChar;
            ctx->LastChar = sl_advance(ctx);
        }

        for (dint i = 0; ctx->lexemeList[i].tokenType != T_EOF; ++i) {
            if (ctx->IdentifierStr.len == ctx->lexemeList[i].lexeme.len && ctx->lexemeList[i].lexeme.len != 0) {
                if (strncmp(ctx->IdentifierStr.data, ctx->lexemeList[i].lexeme.data, ctx->lexemeList[i].lexeme.len) == 0) {
                    token->type         = ctx->lexemeList[i].tokenType;
                    token->typeName     = ctx->lexemeList[i].tokenName;
                    token->tokenInfo    = ctx->lexemeList[i].tokenInfo;
                    token->identString  = (char*)ctx->lexemeList[i].lexeme.data;

                    return SL_LEX_RET_TOK;
                }
            }
        }

        if (ctx->IdentifierStr.data[ctx->IdentifierStr.len - 1] == ':')
        {
            token->type             = T_LABEL;
            token->typeName         = SL_SET_STRING(SL_TOSTRING(T_LABEL));
        }
        else
        {
            token->type             = T_IDENTIFIER;
            token->typeName         = SL_SET_STRING(SL_TOSTRING(T_IDENTIFIER));
        }

        token->tokenInfo        = SL_TOKEN_INFO_NONE;
        token->identString      = SL_STRDUP(ctx->IdentifierStr.data);

        return SL_LEX_RET_TOK;
    }

    return SL_LEX_SUCCESS;
}
