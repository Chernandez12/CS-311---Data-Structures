//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application
//Your name: Carlos Andre Hernandez
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: To 
//Algorithm: **
int main(){
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  int result = 0; // The total computed
  int number; // Temp position for int conversion
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  char item;  // one char out of the expression
  
    while (expression[i] != '\0'){
     try{
	    item = expression[i];  // current char
 
         // If the expression is too small throws exception
         if(expression.size() == 1)
             throw "Too Few Operands";
         
         // If a character is withing range of a number, converts to int
         if((item >= 48) && (item <= 57)){
             number = (item - 48); //convert char to an int
             postfixstack.push(number); //push int onto stack
             i++;
         }
	 
         // Checks if character is an operator
         else if((item == '*') || (item == '+') || (item == '-')){
             
             //if stack isn't empty pop operand into box1, else throw exception
             if(postfixstack.isEmpty()!= true){
                 postfixstack.pop(box1);
             }
             else
                 throw "Too few Operands";
             
             //if stack isn't empty pop operand into box2, else throw exception
             if(postfixstack.isEmpty()!=true)
                 postfixstack.pop(box2);
             else
                 throw "Too few Oprands";
             
             //if operator +, add operands and store in result
             if(item == '+')
                 result = box1 + box2;
             
             //if operator -, subtract box2 from box1 and store in result
             else if(item == '-')
                 result = box2 - box1;
             
             //if operator *, multiply operands and store in result
             else if(item == '*')
                 result = box1 * box2;
             
             postfixstack.push(result);//push result onto the stack
             i++;   // Go back to the loop after incrementing i
         }
         
         // Throws exception if character is neither an operator or operand
         else
             throw "Invalid Element";
         
         
       } // this closes try
      
        // Catch exceptions and report problems and quit the program now.
        // Error messages describe what is wrong with the expression.
        catch (stack::Overflow) { cerr<<"ERROR: There were Too Many Characters Entered"<<endl; exit(1);}
        catch (stack::Underflow){ cerr<<"ERROR: No Characters Entered"<<endl; exit(1); }
        // for invalid item case
        catch (char const* errormsg){cerr<<"ERROR: "<<errormsg <<endl; exit(1);}
    }// end of while
  
    
    
    postfixstack.pop(result); // Pop the result to show it
    // If anything is left on the stack, throw Error: incomplete expression
    try{
        if (postfixstack.isEmpty()!=true)
            throw "ERROR: Incomplete Expression";
    }
    catch(char const* errorString2){
        cerr<<"ERROR: " <<errorString2 <<endl; exit(1);
    }
    cout<< "The Result is: "<< result <<endl; //show final result
    
    return 0;
} // end of the program
