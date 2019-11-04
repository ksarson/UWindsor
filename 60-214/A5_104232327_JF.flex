import java_cup.runtime.*;
import java.util.*;
import java.io.*;
import java.lang.System;

%%

%function next_token
%class A5_104232327_Scanner
%cup

%eofval{
          return null;
%eofval}
%state COMMENTS, INLINECOMMENTS, HASH


ID = [a-zA-Z_][a-zA-Z0-9_]*
NUMBER = -?[0-9]+(\.[0-9]+)?([eE][\-\+][0-9]+)?

%%

//Initialize key words and symbols with reference words for the cup file
<YYINITIAL>"if"			{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.IF); }
<YYINITIAL>"else"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.ELSE); }
<YYINITIAL>"while"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.WHILE); }
<YYINITIAL>"do"			{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.DO); }
<YYINITIAL>"switch"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.SWITCH); }
<YYINITIAL>"case"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.CASE); }
<YYINITIAL>"default"	{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.DEFAULT); }
<YYINITIAL>"void"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.VOID); }
<YYINITIAL>"int"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.INT); }
<YYINITIAL>"return"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.RETURN); }
<YYINITIAL>"for"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.FOR); }
<YYINITIAL>"main"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.MAIN); }
<YYINITIAL>"+"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.PLUS); }
<YYINITIAL>"++"         { return new java_cup.runtime.Symbol( A5_104232327_Symbol.PLUSPLUS); }
<YYINITIAL>"*"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.MULT); }
<YYINITIAL>"-"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.MINUS); }
<YYINITIAL>">"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.GTHAN); }
<YYINITIAL>"<"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.LTHAN); }
<YYINITIAL>":"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.COLON); }
<YYINITIAL>";"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.SEMI); }
<YYINITIAL>","          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.COMMA); }
<YYINITIAL>"("          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.LPAR); }
<YYINITIAL>")"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.RPAR); }
<YYINITIAL>"{"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.LBRA); }
<YYINITIAL>"}"          { return new java_cup.runtime.Symbol( A5_104232327_Symbol.RBRA); }
<YYINITIAL>"="			{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.EQUAL); }
<YYINITIAL>"printf"		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.PRINTF); }
<YYINITIAL>{ID}         { return new java_cup.runtime.Symbol( A5_104232327_Symbol.ID,yytext());}
<YYINITIAL>{NUMBER}		{ return new java_cup.runtime.Symbol( A5_104232327_Symbol.NUMBER,yytext());}
<YYINITIAL>"return 0;"  { return new java_cup.runtime.Symbol( A5_104232327_Symbol.RETURNBOI); }
<YYINITIAL>\"[^\"]*\"   { return new java_cup.runtime.Symbol( A5_104232327_Symbol.QUOTES,yytext()); }


//Initialize comment formatting
<YYINITIAL>"/*" {yybegin(COMMENTS);}
<COMMENTS>"*/" {yybegin(YYINITIAL); }
<COMMENTS>. {}

//Initialize inline comment formatting
<YYINITIAL>"//" {yybegin(INLINECOMMENTS);}
<INLINECOMMENTS>"\r"|"\n" {yybegin(YYINITIAL); }
<INLINECOMMENTS>. {}


//Initialize hash formatting
<YYINITIAL>"#" {yybegin(HASH);}
<HASH>"\r"|"\n" {yybegin(YYINITIAL); }
<HASH>. {}

//Initialize items which do not require action
\r|\n {/* Do nothing */}
. {/* Do nothing */}
