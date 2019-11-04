%%
%class example
%standalone
%line
%column
%%
(a|b)*abb {System.out.printf(
"***Found match *%s+at line %d, column %d\n",
yytext(), yyline, yycolumn);
}
\n { /* Do nothing */}
. {/* Do nothing */}