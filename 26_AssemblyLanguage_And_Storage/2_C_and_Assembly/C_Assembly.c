# include<stdio.h>

/*
 * What is the realtionship between C and assembly language?
 *
 * Commands:
 * gcc -S Test.c   //Compile C into assbmbly language.
 * 
 * */

int bar(int c, int d)
{
	int e = c + d;
	return e;
}

int foo(int a, int b)
{
	return bar(a, b);
}

int main(void){
	
	foo(2,3);

	return 0;

}
