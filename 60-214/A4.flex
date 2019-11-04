import java_cup.runtime.*;
import java.util.*;
import java.io.*;
import java.lang.System;

%%

%function next_token
%class A4Scanner
%cup

%eofval{
          return null;
%eofval}
%state COMMENTS, INLINECOMMENTS, HASH


ID = [a-zA-Z_][a-zA-Z0-9_]*
NUMBER = -?[0-9]+(\.[0-9]+)?([eE][\-\+][0-9]+)?

%%

<YYINITIAL>"void"		{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.VOID); }
<YYINITIAL>"int"		{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.INT); }
<YYINITIAL>"return"		{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.RETURN); }
<YYINITIAL>"main"		{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.MAIN); }
<YYINITIAL>"+"          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.PLUS); }
<YYINITIAL>"-"          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.MINUS); }
<YYINITIAL>";"          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.SEMI); }
<YYINITIAL>","          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.COMMA); }
<YYINITIAL>"("          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.LPAR); }
<YYINITIAL>")"          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.RPAR); }
<YYINITIAL>"{"          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.LBRA); }
<YYINITIAL>"}"          { return new java_cup.runtime.Symbol( A4_104232327_Symbol.RBRA); }
<YYINITIAL>"="			{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.EQUAL); }
<YYINITIAL>"printf"		{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.PRINTF); }
<YYINITIAL>{ID}         { return new java_cup.runtime.Symbol( A4_104232327_Symbol.ID); }
<YYINITIAL>{NUMBER}		{ return new java_cup.runtime.Symbol( A4_104232327_Symbol.NUMBER); }
<YYINITIAL>\"[^\"]*\"   { return new Symbol( A4_104232327_Symbol.QUOTES); }

<YYINITIAL>"/*" {yybegin(COMMENTS);}
<COMMENTS>"*/" {yybegin(YYINITIAL); }
<COMMENTS>{ID}|{NUMBER}|<QUOTES> {}

<YYINITIAL>"//" {yybegin(INLINECOMMENTS);}
<INLINECOMMENTS>"\r"|"\n" {yybegin(YYINITIAL); }
<INLINECOMMENTS>{ID}|{NUMBER}|<QUOTES> {}

<YYINITIAL>"#" {yybegin(HASH);}
<HASH>"\r"|"\n" {yybegin(YYINITIAL); }
<HASH>{ID}|{NUMBER}|<QUOTES> {}

\r|\n {/* Do nothing */}
. {/* Do nothing */}
