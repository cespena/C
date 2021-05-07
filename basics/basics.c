//basics.c
/*
This file is what is called a source file. We identify source files by the .c
at the end of the file name. Source files contain the source code of your program.
These are the human readable instructions of your program that the C compiler will 
turn into machine code.
*/

/*
This is what is called a preprocessor directive. You can identify a preprocessor
directive by the hash symbol (#) at the beginning of the line. Preprocessor directives
are instructions of what to do before your code is compiled.

This particular preprocessor called the include directive. It allows you import 
libraries into your code. The library that has been imported is the stdio.h 
library. We imported this library to allow us to use the printf() function.
*/
#include <stdio.h>


/*
This is a function in C. All functions have a return type, identifier (a name), any 
number of parameters (the parameters are the x and y in between the parenthesis), a 
body, and its return value. This function, called sum, takes in two integers and 
returns an integer value. 

The function below is declared, but not defined. The function
definition is below the main function. The way C works is that it reads your code from 
top to bottom. If you tried calling a function that is written below the caller function,
then C will throw you an error. To the caller function, the calling function does not
exist. That is why we give the function declaration above all the functions. Note the 
semicolon placed at the end of the declaration.
*/
int sum(int x, int y);

/*
A better practice is to write both the declaration and definition above the caller function. 
Since main will be calling the square function, we write everything before main.
*/
int square(int x)
{
	//The return statement returns a value based on the return type of the function.
	//Since this function return type is an int, we return an int. Whenever a function 
	//hits a return statement, anything that comes after is ignored.
	return x * x;
	printf("After the return\n"); //This will not execute.
}

/*
A void function is a function that returns nothing. You do not need to have a return statement.
*/
void void_function()
{
	printf("This is a void function\n");
	//The return statement is not necessary. But there will be times when you need to leave a
	//void function. This statement will allow you to do so.
	return ;
}

//In order to fully understand functions, one needs to know how C handles functions in memory.
//When you call a function, your C program finds a portion of memory to load the function. Once 
//it has been loaded, your program jumps to that section in memory and executes the instructions
//of the function. After the function has completed its task, the program exits this portion of 
//memory and continues to the next line of code after the function call. This means anything that
//was created within a function will be erased whenever the function is done. The only way to save 
//anything is to return the value you wish to save. 
//The function below returns the summation of numbers up to a certain value. In order to store the
//sum of all the values, we create a variable called finalSum. This variable is what is called a
//local variable since it will no longer exist when this function is done executing. Since we want
//to save the value of finalSum, we return it. 
//Another thing to note about local variables is that only the function in which it exists can access
//it. If another function wishes to access it, then you must pass it to that function.
int summation(int value)
{
	int finalSum = 0;

	for (int i = 1; i <= value; i++)
	{
		finalSum += value;
	}

	return finalSum;
}

//If your program requires the use of a variable that will be called in different functions, use a 
//global variable. A global variable will be seen by all the functions in your program. This allows
//the variable to be called anywhere in your program. Global variables exist for the entire lifetime
//of your program. 
//To create a global variable, define it outside of all functions. For example, the variable globalInt 
//below has been defined outside of all functions, including the main function. 
//Another difference between local and global variables is that C automatically initializes global 
//variables to some default value. Currently, globalInt is initialized to the value of 0. 
//There is a general consensus amongst Computer Scientists that global variables should be avoided. They
//cause many issues since anything can modify its value. The are also known to create security risks.
//There are times when you will need a global variable, but they are so few. The best thing to do is
//to just pass a variable between functions. This provides many levels of protection to the variable that
//a global variable does not.
int globalInt;


/*
All programs written in C have a main function. The main function is the entry point
of the program. The main function always returns an integer. Whatever you want your
program to do goes in the body of the main function. The body of the function is
everything that belongs within the curly braces {}. This particular main function 
does not take any parameters; that is why the parenthesis are empty. However, there
are a few parameters that the main function can take. More on that later.
*/
int main()
{
	/*
	This is the body of the main program. Anything in here will be executed.
	*/

	//This line is a statement. Statements always end in semicolons (;). This
	//statement calls a function called printf. This is the function that you
	//use to print text from your program. The text being printed here is 
	//Hello World followed by a newline character (\n). Note that the string
	//must be in between double quotes (") as opposed to single quotes (').
	//Single quotes are reserved for characters.
	printf("Hello World\n");

	//These are some common examples of variables that you will use. Before you 
	//can declare a variable, you must tell C what kind of variable it is going 
	//to be. C is strict about the type that you declare a variable. Once declared,
	//you cannot put in a different type of data into that variable. The variable i
	//has been declared as an integer. The variable c has been declared as a character.
	//This means that variable i cannot store a character and variable c cannto store
	//an integer.
	//The identifier of a variable is the name used to identify a variable, function, 
	//or anything that is user defined. An identifier can start with a letter, or an
	//underscore. Afterward, the identifier can have any number of letters, underscores,
	//or numbers. Keep in mind that identifiers are case sensitive. So variable and Variable
	//are two different identifiers in C.
	//All three variables have been initialized. We give variables their initial value using
	//the assignment operator (=). This gives a value to the variable. It is always a good 
	//practice to give a variable an initial value. Do not confuse the assignment operator 
	//with the equality operator(==).
	char c = 'a';	//Character. Size: 1 byte.  Stores characters. DO NOT USE DOUBLE QUOTES!
	int i = 1;		//Integer.   Size: 4 bytes. Stores whole numbers
	double d = 2.0;	//Double.    Size: 8 bytes. Stores decimal values

	//You can change the value of a variable anytime you want with the assignment operator.
	c = 'b';
	i = 2;
	d = 3.4;

	//In order to print these variables, use the printf function. Note the difference 
	//in syntax for each variable.
	printf("c: %c\n", c);	//char uses %c
	printf("i: %d\n", i);	//int uses %d
	printf("d: %f\n", d);	//double uses %f

	//In order to get input from a user, use the scanf function. This function waits until the 
	//user inputs a value and stores it in a variable. You will use the same specifiers that you
	//used when using the printf function. As opposed to the printf function, the scanf function 
	//requires the memory location of the variable. In order to do this, we put the address-of (&) 
	//symbol in front of the variable.
	//Note the difference between the printf and scanf lines for the double variable. They both 
	//use f, however, scanf requires you to use lf due to the size of double. If the variable
	//was defined as a float rather than double, then you would not need the l.
	scanf("%c", &c);
	scanf("%d", &i);
	scanf("%lf", &d);

	//If we print the variables, you can see that their values have been updated.
	printf("New value of c: %c\n", c);
	printf("New value of i: %d\n", i);
	printf("New value of d: %f\n", d);

	//If you have to define several variables of the same type, you can list them on the same
	//line.
	int x = 3, y = 4;

	//You can also print several variables in the same printf call. The \t character means tab.
	printf("x: %d\ty: %d\n", x, y); 

	//Operators
	i = x + y;
	printf("Sum: %d\n", i);

	i = x - y;
	printf("Difference: %d\n", i);

	i = x * y;
	printf("Multiplication: %d\n", i);

	i = y / x; //Only grabs the whole number
	printf("Division with integers: %d\n", i); 

	d = 11 / 7.0; //In order to get a decimal, either one, or both, values must be decimals
	printf("Division with doubles: %f\n", d);

	i = y % x;
	printf("Modulus (remainder): %d\n", i);

	i = 3;
	i++;	//You can also use ++i.
	printf("Increment (++): %d\n", i);

	i--;	//You can also use --i.
	printf("Decrement (--): %d\n", i);

	//Besides simple assignment (=), there are other types of assignment operators. This helps
	//shorten and clean up code.
	i += 3; //i = i + 3
	i -= 2; //i = i - 2
	i *= 4; //i = i * 4
	i /= 4; //i = i / 4
	i %= 3; //i = i % 3

	//There are also bitwise operators used to play with the bits in an integer.
	i = x & y; //i = x AND y
	i = x | y; //i = x OR y
	i = x ^ y; //i = x XOR y
	i = x << 2; //i = x SHIFT LEFT 2
	i = x >> 2; //i = x SHIFT RIGHT 2
	i = ~x;		//One's complement. Flips bits.

	//There are also assignment operators for the bitwise operators.
	i &= x;
	i |= y;
	i ^= 2;
	i <<= 2;
	i >>= 2;

	//Before we get to decision structures and loops, lets talk about conditions. Conditions are expressions
	//that evaluate to either true or false. In C, 0 represents false and any other value represents true.
	//In order to create conditions, lets look at some relational operators:
	//Equality:   				x == y		x is equal to y
	//Inequliaty: 				x != y 		x is not equal to y
	//Greater than: 			x > y		x is greater than y
	//Less than: 				x < y		x is less than y
	//Greater than/Equal to 	x >= y		x is greater than or equal to y
	//Less than/Equal to		x <= y 		x is less than equal to y	
	//
	//You can also combine relational operators with logical operators. Notice that the logical operators
	//are different from the bitwise operators.
	//Logical AND:	&&
	//Logical OR:	||
	//Logical NOT:	!
	//Ex: x == 1 && y == 2

	
	
	//If statements are decision making structures that are used to determine things in your
	//program. If statements require you to have an "if" statement; "else if" and "else" are optional.
	//An 'if' and 'else if' consist of a condition followed by a body of statements. An if statement's
	//body is executed if its condition evaluates to true. If false, it tries the condifion of it's 
	//'else if' statement(s). There can be more than one 'else if'. If all conditions fail, then the 
	//else gets executed.
	
	//An if statment.
	if (1 == 1)
	{
		printf("One is equal to one\n");
	}

	i = 4;
	//If...else
	if (i % 2 == 0)
	{
		printf("Even\n");
	}
	else
	{
		printf("Odd\n");
	}

	//if...else if...else
	if (x > y)
	{
		printf("x > y\n");
	}
	else if (x < y)
	{
		printf("x < y\n");
	}
	else
	{
		printf("x = y\n");
	}

	i = 14;
	//You can also nest if statements
	if ( i > 10)
	{
		if ( i % 2 == 0)
		{
			printf("i is greater than 10 and is even\n");
		}
	}

	//Another way to do the above nest if statement is by using logical operators.
	if (i > 10 && i % 2 == 0)
	{
		printf("i is greater than 10 and is even\n");
	}

	//A while loop is the most simplistic form of a loop. It consists of a condition and a body 
	//of statements. A while loop keeps executing its body as long as its condition evaluates to
	//true. Once the condition evaluates to false, it jumps out of the body which halts the loop.

	i = 1;
	while (i % 3 != 0)
	{
		i++;
	}
	printf("Done with while loop. Value of i: %d\n", i);

	//While very simple, the while loop requires special handling. If a programmer is not careful,
	//he/she can create what is called an infinite loop. This loop is not able to stop running its 
	//body due to the condition evaluating to true every time. Use the kill command to kill a program
	//that is in an infinite loop (ctrl + c in terminal). 
	//Example of an infinite loop. Since the condition is always 1, the body will never stop executing.
	//while (1)
	//{
	//	printf("Infinite loop\n");
	//}
	//
	//Another popular example of an inifite loop is the following:
	//int count = 0;
	//while (count < 10)
	//{
	//		printf("Count is:%d\n", count);
	//}
	//This is an infinite loop because count is never incremented. Count will always remain as 0 and 
	//the condition will always evaluate to true. Instead of using while loops, we can use for loops
	//which allow for more safety compared to while loops.

	//A for loop is a looping structure that has 3 phases and a body of statements. The three phases
	//are the following: initialization, condition and increment. In the initialization phase, the 
	//programmer can initialize a variable needed for the loop. This phase is executed once. The second
	//phase is the condition phase. In this phase, the condition is evaluated to see if the loop needs
	//to execute the body. This phase is executed before every loop. The third phase is the increment
	//phase. This phase allows you to update loop control variables.
	for(int count = 0; count < 10; count++)
	{
		printf("For count is:%d\n", count);
	}
	//The for loop above is the same as this while loop:
	int count = 0;
	while (count < 10)
	{
		printf("While count is:%d\n", count++);
	}

	//Both for and while loops are considered pre-test loops since they check their conditions before 
	//executing their bodies.A do...while loop is a post-test loop because it executes its body before
	//checking its condition. This means that at minimum, a do...while's body is executed once.

	count = 0;
	do
	{
		printf("Do while count is:%d\n", count++);
	}
	while (count < 10);


	//In order to call functions, the functions must be declared before the caller function. Let's use
	//the sum function we declared earlier. This function takes two numbers and returns an int. We will 
	//have to provide x and y as arguments and assign the result to the i variable since it is an int.
	i = sum(x, y);
	printf("Sum(x, y): %d\n", i);

	//We can also call a function without assigning it to a variable
	printf("Square(4): %d\n", square(4));

	//A function with the return type of void does not get assigned to any variable. In the void_function
	//example, we also see that it takes no arguments. We leave the parenthesis empty. However, in order
	//to call a function, you cannot forget to include the parenthesis regardless of how many arguments
	//it accepts.
	void_function();

	//Since we cannot access the variable of finalSum within the summation function, we instead return
	//the value stored within finalSum. We can then put that value into a variable within the main function.
	int getSummation = summation(5);
	printf("Summation: %d\n", getSummation);


	//This return statement is placed at the end of the main function. The main function 
	//always returns the value of 0. This signals a normal exit and hence the program executed
	//successfully. If the program has an abnormal exit, any value other than 0 is returned. Note
	//the difference in convention between programs and decision/loop statments. A program returning
	//0 means success as opposed to a decision/loop statement where 0 means failure.
	return 0;
}


//Here is the function definition for the sum function that is declared towards the top of this file.
int sum (int x, int y)
{
	return x + y;
}
