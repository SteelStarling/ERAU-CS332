public class Hello { 
    // This is the correct signature for a main in Java 
    public static void main(String[] args) { 
        // No cout or printf. Uses a static method in System.out. 
        System.out.println("Hello Java!"); 
        // Object variables are pointers. Use new to create object. 
        Hello greeter = new Hello(); 
        // args are words included on command line after "java Hello" 
        // Arrays are object with properties, like length 
        for (int i = 0; i < args.length; ++i) 
            greeter.greet(args[i]); 
        // No free/delete after new Hello. Memory is garbage collected. 
    } 
 
    // No separate header file. Define functions in class declaration. 
    public void greet(String name) { 
        // The + operator for stringsconcatenates 
        System.out.println("Hello " + name + "!"); 
    } 
 
} // Unlike C++, no semicolon at the end of a class declaration. 
