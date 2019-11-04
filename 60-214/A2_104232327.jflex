/*
 * Feb 16th 2018
 * Assignment 2 - JFlex Scanner
 * Kolby Sarson - 104232327
 * **I considered printf to be a keyword in this assignment**
 */

import java.util.*;
import java.io.*;
%%
%integer
%class A2_104232327
%line
%column
 
Identifiers = [A-Za-z_][A-Za-z_0-9]*
Numbers = [+-]?([0-9]*[.])?[0-9]+|[+-]?([0-9]*[.])?[0-9]+E\+[0-9]+
Comments = \/\*([^\*]|[\*][^\/])*\*\/|\/\/.*
Strings = \".*\"
 
%{
  public static void main(String [] args) throws java.io.IOException {
    A2_104232327 yy=new A2_104232327(new FileReader(args[0]));
    Writer.outputFileName = args[0].replaceAll("input","output");   //changes output file name
    while (0<=yy.yylex());
  }
%}
 
%{
    List<String> identifiers = new ArrayList();
    List<String> numbers = new ArrayList();
    List<String> keywords = new ArrayList();
    List<String> comments = new ArrayList();
    List<String> strings = new ArrayList();
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
    identifiers = new ArrayList<String>(new LinkedHashSet<String>(identifiers));    //removes duplicates
    keywords = new ArrayList<String>(new LinkedHashSet<String>(keywords));
    numbers = new ArrayList<String>(new LinkedHashSet<String>(numbers));
   
    Writer x= new Writer();
    x.w.write("Identifiers: "+identifiers.size()+"\r\n");   //writing array sizes to the file
    x.w.write("Keywords: "+keywords.size()+"\r\n");
    x.w.write("Numbers: "+numbers.size()+"\r\n");
    x.w.write("Comments: "+comments.size()+"\r\n");
    x.w.write("Strings: "+strings.size()+"\r\n");
    x.w.close();
   
}catch(Exception e){}
return;
%eof}
 
%%
{Strings} {strings.add(yytext());}
{Comments} {comments.add(yytext());}
if|else|do|while|for|printf|int|main {keywords.add(yytext());}
{Identifiers} {identifiers.add(yytext());}
{Numbers} {numbers.add(yytext());}
\r|\n { /* Do nothing */}
. {/* Do nothing */}