import java.util.*;
import java.io.*;
%%
%{
  public static void main(String [] args) throws java.io.IOException {
    A2_FileExample yy=new A2_FileExample(new FileReader(args[0]));
	Writer.outputFileName = args[0].replaceAll("input","output");
    while (0<=yy.yylex());
  }
%}

%{
	List<String> identifiers = new ArrayList();
	List<String> numbers = new ArrayList();
%}

%{
	static class Writer{
	public static String outputFileName;
	
		FileWriter w;
			Writer(){
			try{ w=new FileWriter(outputFileName);}catch(Exception e)
			{} 
		}
	}
%}


%eof{
try{
	Writer x= new Writer();
	x.w.write("identifiers: "+identifiers+ "\r\n");
	x.w.write("numbers: "+numbers+ "\r\n");
	x.w.close();
}catch(Exception e){}
return;
%eof}

%integer
%class A2_FileExample
%line
%column

Identifiers = [A-Za-z_][A-Za-z_0-9]*
Numbers = [0-9]+

%%
{Identifiers} {identifiers.add(yytext());}
{Numbers} {numbers.add(yytext());}
\r|\n { /* Do nothing */}
. {/* Do nothing */}