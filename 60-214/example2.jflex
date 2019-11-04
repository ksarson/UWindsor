import java.util.*;
%%
%class example2
%standalone
%line
%column
Identifiers = [A-Za-z_][A-Za-z_0-9]*
Numbers = [0-9]+

%{
	List<String> identifiers = new ArrayList();
	List<String> numbers = new ArrayList();
%}

%eof{
	System.out.println("Identifiers: "+identifiers.toString().replaceAll("\\[\\]", ""));
	System.out.print("Numbers: ");
	for (int i = 0; i<numbers.size();i++){
		if (i==numbers.size()-1)
			System.out.print(numbers.get(i));
		else
			System.out.print(numbers.get(i)+", ");
	}
	
%eof}

%%
{Identifiers} {identifiers.add(yytext());}
{Numbers} {numbers.add(yytext());}
\n { /* Do nothing */}
. {/* Do nothing */}