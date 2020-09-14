#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ass.h"
#include "pic.h"
char *string_hex[16]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
char *string_bin[16]={"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char* BinToHex(char*, char*);
char* HexToBin_arg(char*, int, char*);
void Assembler(char *file_instr, int pic, FILE* file_out)
{
	const Pic *mapping;
	int i, j, z, pos, maxinstr, var;
	char *word_asm=(char*)malloc(sizeof(char)*20);//Da ricontrollare se 20 è troppo tra pic16 e pic18
	char *bin=(char*)malloc(sizeof(char)*16);
	char *hex=(char*)malloc(sizeof(char)*4);
	char *arg_hex=(char*)malloc(sizeof(char)*5);	
	char *arg_hex_1=(char*)malloc(sizeof(char)*5);
	char *bin_arg;
	if(pic==16)
	{	maxinstr=36;	}
	else if(pic==18)
	{	maxinstr=80;	}
	FILE* file_asm;
	file_asm=fopen(file_instr, "r");
	if(file_asm==NULL||file_out==NULL)
	{printf("Errore\n");}
	else
	{
		while(fscanf(file_asm, "%s", word_asm)>0)
		{
			if(pic == 16) 		{ mapping=pic_16; bin[0]='0'; bin[1]='0'; pos=2;}
			else if(pic ==18)	{ mapping=pic_18; pos=0;}
			i=0;
			//Opcode
			while((strcasecmp(word_asm, *(mapping->instr_name))!=0) && (i<maxinstr))
			{
				i++;
				if(pic==16){mapping=pic_16+i;}
				else if (pic==18){mapping=pic_18+i;}
			}
			if(i>maxinstr)
			{
				printf("Istruzione inserita non corretta.\n");
				continue;
			}
			for(z=0, j=pos; j<(mapping->numb_bit)+pos; j++, z++)
			{
				bin[j]=(mapping->opcode_bin[z]);
			}
			if((pic==16 && (mapping->numb_bit)!=14) || (pic==18 && (mapping->numb_bit)!=16))
			{
				var=0;
				//BinToHexArg_1	
				if((mapping->arg_1)!=0)
				{
					fscanf(file_asm, "%s", arg_hex_1);
					if(i==65 && pic==18)
					{
						bin_arg=(char*)malloc(sizeof(char)*(mapping->arg_1));
						bin_arg=HexToBin_arg((arg_hex_1+2), (mapping->arg_1), bin_arg);
						for(j=(mapping->numb_bit)+pos, z=0; j<16-(mapping->arg_2)-(mapping->arg_3); j++,z++)
						{
							bin[j]=bin_arg[z];
						}
					}
				}
				//BinToHexArg_2
				if((mapping->arg_2)!=0)
				{
					fscanf(file_asm, "%s", arg_hex);
					bin_arg=(char*)malloc(sizeof(char)*(mapping->arg_2));
					bin_arg=HexToBin_arg((arg_hex+2), (mapping->arg_2), bin_arg);
					if(i==65 && pic==18)
					{	var +=mapping->arg_1;}
					for(j=(mapping->numb_bit)+pos+var, z=0; j<16-(mapping->arg_1)-(mapping->arg_3)+var; j++, z++)
					{
						bin[j]=bin_arg[z];
					}
				}
				//BinToHexArg_3
				if((mapping->arg_3)!=0)
				{
					fscanf(file_asm, "%s", arg_hex);
					bin_arg=(char*)malloc(sizeof(char)*(mapping->arg_3));
					bin_arg=HexToBin_arg((arg_hex+2), (mapping->arg_3), bin_arg);
					for(j=(mapping->numb_bit)+(mapping->arg_2)+pos, z=0; j<16-(mapping->arg_1); z++, j++)
					{
						bin[j]=bin_arg[z];
					}
				}
				if( ((mapping->arg_1)!=0) && (i!=65))
				{
					bin_arg=(char*)malloc(sizeof(char)*(mapping->arg_1));
					bin_arg=HexToBin_arg((arg_hex_1+2), (mapping->arg_1), bin_arg);
					for(j=(mapping->numb_bit)+(mapping->arg_2)+(mapping->arg_3)+pos, z=0; j<16; j++,z++)	
					{
						bin[j]=bin_arg[z];
					}
				}
			}
			//BinToHex	
			hex=BinToHex(bin, hex);
			fprintf(file_out, "%s\n", hex);
			//istruzioni doppie pic 18		
			mapping = pic_18+i+1;
			pos=0;
			if( (*(mapping->instr_name)!= NULL) && (strcmp(word_asm, *(mapping->instr_name))==0 && i!=52) && pic==18)
			{
				for(z=0, j=pos; j<(mapping->numb_bit)+pos; j++, z++)
				{
					bin[j]=(mapping->opcode_bin[z]);
				}
				if ( i==65)
				{
					//lfsr
					arg_hex_1 = arg_hex + ((mapping-1)->arg_2)/4;
				}
				else if(i==46 || i==50)
				{
					//call / goto		
					arg_hex_1 = arg_hex_1 + ((mapping-1)->arg_1)/4 ;
				}
				else
				{//MOVFF
						fscanf(file_asm, "%s", arg_hex_1);
				}
				if((mapping->arg_1)!=0)
				{
					bin_arg=(char*)malloc(sizeof(char)*(mapping->arg_1));
					bin_arg=HexToBin_arg((arg_hex_1+2), (mapping->arg_1), bin_arg);
					for(j=(mapping->numb_bit)+(mapping->arg_2)+(mapping->arg_3)+pos, z=0; j<16; j++,z++)
					{
						bin[j]=bin_arg[z];
					}
				}
				hex=BinToHex(bin, hex);
				fprintf(file_out, "%s\n", hex);
			}
		}
	}
//	free(arg_hex_1);
	free(word_asm);
	free(bin);
	free(hex);
	free(arg_hex);
	free(bin_arg);	
	fclose(file_asm);
	fclose(file_out);
}

char* BinToHex(char *bin_instr, char* hex_result)
{
	int i, j, z=0;
	for(i=0; i<16; i+=4)
	{
		j=0;
		while(strncmp((bin_instr+i) ,string_bin[j],4)!=0)
		{
			j++;
		}
		hex_result[z]=*string_hex[j];
		z++;
	}
	return hex_result;
}

char* HexToBin_arg(char *hex_arg, int bit_numb, char*bin_arg)
{
	int bit_int=bit_numb/4;
	int bit_res=bit_numb%4;
	int a=0, b, x, y=0, z;
	if(bit_res!=0)
	{
		b=0;
		while(strncmp(hex_arg+a, string_hex[b], 1)!=0)
		{
			b++;
		}
		for(x=4-bit_res; x<4; x++, y++)
		{
			bin_arg[y]=string_bin[b][x];
		}
		a++;
	}
	if(bit_int!=0)
	{
		for(z=0; z<(bit_numb-bit_res); z+=4, a++)
		{
			b=0;
			while(strncmp(hex_arg+a, string_hex[b], 1)!=0)
			{
				b++;
			}
			for(x=0; x<4; x++, y++)
			{
				bin_arg[y]=string_bin[b][x];
			}
		}
	}
	return bin_arg;
}
