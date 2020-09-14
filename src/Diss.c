#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Diss.h"
#include "pic.h"

char *hex_string[16]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
char *bin_string[16]={"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char* HexToBin(char*, char*);
char *BinToHex_arg(char*, int, char*);
void Disassembler(char *file_instr, int pic, FILE* file_out)
{
	const Pic *mapping;
	ssize_t nread;
	size_t n=0;
	int pos, pos1, i, plus, pos_hex;
	char *hex_arg=(char*)malloc(sizeof(char)*5), *hex_arg_2=(char*)malloc(sizeof(char)*5);
	char *word = NULL;
	char *word_hex=(char*)malloc(sizeof(char)*4);
	char *bin=(char*)malloc(sizeof(char)*16);	
	FILE* file_hex;
	file_hex=fopen(file_instr, "r");
	if(file_hex==NULL||file_out==NULL)
	{printf("Errore\n");}
	else
	{
		while( (nread=getline(&word, &n, file_hex))!=-1)
		{
printf("%s", word);
			pos_hex=9;
			while(word[7]=='0' && word[8]=='0' && (word[pos_hex+3]!=0))
			{
				word_hex[0]=word[pos_hex+2];
				word_hex[1]=word[pos_hex+3];
				word_hex[2]=word[pos_hex];
				word_hex[3]=word[pos_hex+1];
printf("%s\t", word_hex);
				if(pic == 16) 		{ mapping=pic_16; pos=2; }
				else if(pic ==18)	{ mapping=pic_18; pos=0; }
				i=0; pos1=0;
				bin=HexToBin(word_hex, bin);
				while(strncmp((bin+pos), (mapping->opcode_bin), (mapping->numb_bit))!=0)
				{
					i++;
					if(pic==16){mapping=pic_16+i;}
					else if (pic==18){mapping=pic_18+i;}
				}
				fprintf(file_out, "%s", *(mapping->instr_name));
				if( ((mapping->numb_bit)!=14 && pic==16) || ((mapping->numb_bit)!=16 && pic==18)) 	
				{
					pos=pos+(mapping->numb_bit);
/*					if( strcmp( *(mapping->instr_name), *((mapping+1)->instr_name))==0 && pic==18 && i!=52)
					{
						//MOVFF && CALL && GOTO && LFSR
						if(i==46)
						{
							if(mapping->arg_3%4!=0){plus=1;}
							else if(mapping->arg_3%4==0){plus=0;}
							hex_arg_2=(char*)malloc(sizeof(char)*(mapping->arg_3/4+plus));
							hex_arg_2=BinToHex_arg(bin+pos, mapping->arg_3, hex_arg_2);
							pos = pos+(mapping->arg_3);
						}
						if(mapping->arg_1%4!=0){plus=1;}
						else if(mapping->arg_1%4==0){plus=0;}
						hex_arg=(char*)malloc(sizeof(char)*(mapping->arg_1/4+plus));
						hex_arg=BinToHex_arg(bin+pos, mapping->arg_1, hex_arg);	
						if (i==16){fprintf(file_out, "\t0x%s\t0x", hex_arg);}
						else if(i==46 || i==50){fprintf(file_out, "\t0x%s", hex_arg);}
						else if(i==65)
						{
							fprintf(file_out, "\t0x%s", hex_arg);
							pos=pos+(mapping->arg_1);
							if(mapping->arg_2%4!=0){plus=1;}
							else if(mapping->arg_2%4==0){plus=0;}
							hex_arg=(char*)malloc(sizeof(char)*(mapping->arg_2/4+plus));
							hex_arg=BinToHex_arg(bin+pos, mapping->arg_2, hex_arg);
							fprintf(file_out, "\t0x%s", hex_arg);
						}	
				fscanf(file_hex,"%s",word_hex);								
						bin=HexToBin(word_hex, bin);
						pos=((mapping+1)->numb_bit);
						if((mapping+1)->arg_1%4!=0){plus=1;}
						else if((mapping+1)->arg_1%4==0){plus=0;}
						hex_arg=(char*)malloc(sizeof(char)*((mapping+1)->arg_1/4+plus));
						hex_arg=BinToHex_arg(bin+pos, (mapping+1)->arg_1, hex_arg);
						fprintf(file_out, "%s", hex_arg);
						if(i==46){ fprintf(file_out, "\t0x%s", hex_arg_2);}
					}	
					else
					{
*/						if((mapping->arg_1)!=0)
						{
							//BinToHexArg_1
							pos1=pos+(mapping->arg_2)+(mapping->arg_3);
							if(mapping->arg_1%4!=0){plus=1;}
							else if(mapping->arg_1%4==0){plus=0;}
							hex_arg=(char*)malloc(sizeof(char)*(mapping->arg_1/4+plus));
							hex_arg=BinToHex_arg(bin+pos1, mapping->arg_1, hex_arg);
							fprintf(file_out, "\t0x%s", hex_arg);
						}
						if((mapping->arg_2)!=0)
						{
							//BinToHexArg_2
							pos1=pos;
							hex_arg=(char*)malloc(sizeof(char));
							hex_arg=BinToHex_arg(bin+pos1, mapping->arg_2, hex_arg);
							fprintf(file_out, "\t0x%s", hex_arg);
						}
						if((mapping->arg_3)!=0)	
						{
							//BinToHexArg_3
							pos1=pos+(mapping->arg_2);
							hex_arg=(char*)malloc(sizeof(char));
							hex_arg=BinToHex_arg(bin+pos1, mapping->arg_3, hex_arg);
							fprintf(file_out, "\t0x%s", hex_arg);
						}
					//}
				}
printf("\n");
				fprintf(file_out, "\n");
				pos_hex+=4;
			}
		}
	}
	free(hex_arg);
	free(hex_arg_2);
	free(word);
	free(word_hex);
	free(bin);
	fclose(file_hex);
	fclose(file_out);
}

char* HexToBin(char *hex, char *bin_instr)
{
	int i, j, z=0;
	for(i=0; i<4; i++)
	{
		j=0;
		while(strncmp(hex+i, hex_string[j], 1)!=0)
		{
			j++;
		}
		bin_instr[0+z]=bin_string[j][0];
		bin_instr[1+z]=bin_string[j][1];
		bin_instr[2+z]=bin_string[j][2];
		bin_instr[3+z]=bin_string[j][3];
		z+=4;
	}	
	return bin_instr;
}

char *BinToHex_arg(char *bin_code, int bit_numb, char *hex_out)
{
	int bit_int=bit_numb/4;
	int bit_res=bit_numb%4;
	int i, j=0, a;
	if(bit_res!=0)
	{
		i=0;
		while(strncmp(bin_code, (bin_string[i]+4-bit_res), bit_res)!=0)
		{ i++;}
		hex_out[j]=*hex_string[i];
		j++;
	}
	if(bit_int!=0)
	{
		for(a=0; a<(bit_numb-bit_res); a+=4)
		{
			i=0;
			while(strncmp((bin_code+bit_res+a), bin_string[i], 4)!=0)
			{i++;}
			hex_out[j]=*hex_string[i];
			j++;
		}
	}
	return hex_out;
}
