#include <stdint.h>

typedef struct{
	char *instr_name[20];
	char *opcode_bin;
	size_t numb_bit;
	int arg_1;//f | k
	int arg_2;//d | b
	int arg_3;//a | s
}Pic;

extern const Pic pic_16[37];
extern const Pic pic_18[82];
