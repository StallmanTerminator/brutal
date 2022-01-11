#pragma once

#include <brutal/ds.h>
#include <cc/lex/lexer.h>

typedef Vec(Lexemes) MacroArgsCodes;

typedef struct
{
    Str name;
    Lexemes source;
    Vec(Str) args;
} CProcMacro;

typedef Vec(Str) CProcIncludes;

typedef struct
{
    Lexemes source;
    Str filename;
    Vec(CProcMacro) macros;
    CProcIncludes files_included;
    Vec(Str) include_path;
    Vec(Str) inside_macro;
    Alloc *alloc;
} CProc;

void cproc_lex(Lex *result, Lex *source, CProc *ctx);

Lex cproc_file(Lex *source, Str filename, Alloc *alloc);

void cproc_gen_macro(Lex *out, Lex *source, CProc *ctx, CProcMacro *macro);

void cproc_parse_define(Lex *source, CProc *ctx);

CProcMacro *cproc_define(CProc *ctx, Str name, Str value);

void cproc_define_arg(CProcMacro *targ, Str name);

CProcIncludes cproc_get_includes(Lex *source, Alloc *alloc);
