import java.io.*;
import java_cup.runtime.Symbol;

class Main {
  public static void main(String[] args) throws Exception {
       File inputFile = new File (args[0]);
       A4_104232327_Parser parser= new A4_104232327_Parser(new A4Scanner(new FileReader(inputFile)));
       Integer result =(Integer)parser.debug_parse().value;
       String outputFileName = args[0].replaceAll("input.c","output.txt");
       FileWriter fw=new FileWriter(new File(outputFileName));
       fw.write("methods: "+ result.intValue());
       fw.close();
  }
}