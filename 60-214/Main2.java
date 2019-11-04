import java.io.*;
import java_cup.runtime.Symbol;

class Main {
  public static void main(String[] args) throws Exception {
       File inputFile = new File (args[0]);
       A5_104232327_Parser parser= new A5_104232327_Parser(new A5_104232327_Scanner(new FileReader(inputFile)));
       String result = (String)parser.debug_parse().value;
       String outputFileName = "A5_output.java";
       FileWriter fw = new FileWriter(new File(outputFileName));
       fw.write(result);
       fw.close();
  }
}