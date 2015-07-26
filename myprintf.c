#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h> /* facilities for variable length argument lists */

/* This program is a simplified version of the similar
 * program in Kernighan and Ritchie "The 'C' Programming
 * Language, 2e page 156 */


void myprintf(char *fmt, ...); /* var length arg list function */

int main(void){
	myprintf("hello myprintf world!\n");
	myprintf("An escaped percent: %%\n");
	myprintf("An integer: %d\n",2*3);
	myprintf("A float: %f\n",sinf(2*3.14159/12)); /* sin of 30 degrees */
	myprintf("An embedded string: %s\n","Hello string world");
	myprintf("Int %d, Float %f, String %s\n",42,10.0/3,"Hello");
	return 0;
}

void myprintf(char *fmt, ...){
       	/* var length arg list function similar to printf() */
	char *s;
	float f;
	int i,j,lenfmt;
	va_list ap; /* argument pointer */
	va_start(ap,fmt); /* make ap point to first unnamed argument */
	lenfmt=strlen(fmt);
	for(j=0;j<lenfmt;j++){
		if(fmt[j]!='%'){
			putchar(fmt[j]);
		} else {
			j++;
			if(fmt[j]=='d'){
				i=va_arg(ap,int);
				printf("%d",i);
			} else if(fmt[j]=='f'){
				f=(float)va_arg(ap,double);
				printf("%f",f);
			} else if(fmt[j]=='s'){
				s=va_arg(ap,char*);
				while(*s)
					putchar(*s++);
			} else 
				putchar(fmt[j]);
		}
			
	}
	
}
