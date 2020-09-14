#include <stdio.h>
#include <string.h>
#include "Diss.h"
#include "Ass.h"

void help(char *);

int main(int argc, char *argv[])
{
	FILE *out;
	out=fopen("out.txt", "w");
	int control1, control2;
	if (argc!=3)
	{ 	help(*argv);	}
	else if( (control1=strcasecmp(argv[1], "instr.asm"))==0 &&  (control2=strcasecmp(argv[2], "pic16"))==0)
	{		Assembler(argv[1], 16, out);}
	else if((control1=strcasecmp(argv[1], "instr.hex"))==0 &&  (control2=strcasecmp(argv[2], "pic16"))==0)
	{		Disassembler(argv[1], 16, out);	}
	else if((control1=strcasecmp(argv[1], "instr.asm"))==0 &&  (control2=strcasecmp(argv[2], "pic18"))==0)
	{		Assembler(argv[1], 18, out);}
	else if((control1=strcasecmp(argv[1], "instr.hex"))==0 &&  (control2=strcasecmp(argv[2], "pic18"))==0)
	{		Disassembler(argv[1], 18, out);	}
	else if ( control1!=-1 || control2!=-1 )
	{	printf("Errore\n");		}		
	return 0;
}

void help (char *name)
{
	printf ("Help:\nErrore d'uso del programma:\nSintassi: %s inputFile picName \n", name);
	printf ("Parametri:\n\tinputFile: \tfile contenente istruzioni Assembly (instr.asm o instr.hex);\n\tpicName: \tpic16 | pic18;\n");
}
