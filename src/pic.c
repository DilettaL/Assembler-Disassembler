#include <stdio.h>
#include "pic.h"

const Pic pic_16[37]=
{
	//0
	{
		.instr_name="ADDWF",
		.opcode_bin="000111",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//1
	{
		.instr_name="ANDWF",
		.opcode_bin="000101",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//2
	{
		.instr_name="CLRF",
		.opcode_bin="0000011",
		.numb_bit=7,
		.arg_1=7,
		.arg_2=0,
		.arg_3=0
	},
	//3
	{
		.instr_name="CLRW",
		.opcode_bin="00000100000000",
		.numb_bit=14,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//4
	{
		.instr_name="COMF",
		.opcode_bin="001001",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//5
	{
		.instr_name="DECF",
		.opcode_bin="000011",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//6
	{
		.instr_name="DECFSZ",
		.opcode_bin="001011",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//7
	{
		.instr_name="INCF",
		.opcode_bin="001010",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//8
	{
		.instr_name="INCFSZ",
		.opcode_bin="001111",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//9
	{
		.instr_name="IORWF",
		.opcode_bin="000100",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//10
	{
		.instr_name="MOVF",
		.opcode_bin="001000",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//11
	{
		.instr_name="MOVWF",
		.opcode_bin="0000001",
		.numb_bit=7,
		.arg_1=7,
		.arg_2=0,
		.arg_3=0
	},
	//12
	{
		.instr_name="NOP",
		.opcode_bin="00000000000000",
		.numb_bit=14,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},	
	//13
	{
		.instr_name="RLF",
		.opcode_bin="001101",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//14
	{
		.instr_name="RRF",
		.opcode_bin="001100",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//15
	{
		.instr_name="SUBWF",
		.opcode_bin="000010",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//16
	{
		.instr_name="SWAPF",
		.opcode_bin="001110",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},	
	//17
	{
		.instr_name="XORWF",
		.opcode_bin="000110",
		.numb_bit=6,
		.arg_1=7,
		.arg_2=1,
		.arg_3=0
	},
	//Bit Oriented	
	//18
	{
		.instr_name="BCF",
		.opcode_bin="0100",
		.numb_bit=4,
		.arg_1=7,
		.arg_2=3,
		.arg_3=0
	},	
	//19
	{
		.instr_name="BSF",
		.opcode_bin="0101",
		.numb_bit=4,
		.arg_1=7,
		.arg_2=3,
		.arg_3=0
	},
	//20
	{
		.instr_name="BTFSC",
		.opcode_bin="0110",
		.numb_bit=4,
		.arg_1=7,
		.arg_2=3,
		.arg_3=0
	},
	//21
	{
		.instr_name="BTFSS",
		.opcode_bin="0111",
		.numb_bit=4,
		.arg_1=7,
		.arg_2=3,
		.arg_3=0
	},
	//Literal
	//22
	{
		.instr_name="ADDLW",
		.opcode_bin="111110",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//23
	{
		.instr_name="ANDLW",
		.opcode_bin="111001",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//24
	{
		.instr_name="CALL",
		.opcode_bin="100",
		.numb_bit=3,
		.arg_1=11,
		.arg_2=0,
		.arg_3=0
	},
	//25
	{
		.instr_name="CLRWDT",
		.opcode_bin="00000001100100",
		.numb_bit=14,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//26
	{
		.instr_name="GOTO",
		.opcode_bin="101",
		.numb_bit=3,
		.arg_1=11,
		.arg_2=0,
		.arg_3=0
	},
	//27
	{
		.instr_name="IORLW",
		.opcode_bin="111000",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//29
	{
		.instr_name="MOVLW",
		.opcode_bin="110000",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//30
	{
		.instr_name="RETFIE",
		.opcode_bin="00000000001001",
		.numb_bit=14,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//31
	{
		.instr_name="RETLW",
		.opcode_bin="110100",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//32
	{
		.instr_name="RETURN",
		.opcode_bin="00000000001000",
		.numb_bit=14,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//33
	{
		.instr_name="SLEEP",
		.opcode_bin="00000001100011",
		.numb_bit=14,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//34
	{
		.instr_name="SUBLW",
		.opcode_bin="111100",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//35
	{
		.instr_name="XORLW",
		.opcode_bin="111010",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	}
};

const Pic pic_18[82]=
{
	//0
	{
		.instr_name="ADDWF",
		.opcode_bin="001001",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//1
	{
		.instr_name="ADDWFC",
		.opcode_bin="001000",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//2
	{
		.instr_name="ANDWF",
		.opcode_bin="000101",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//3
	{
		.instr_name="CLRF",
		.opcode_bin="0110101",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//4
	{
		.instr_name="COMF",
		.opcode_bin="000111",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//5
	{
		.instr_name="CPFSEQ",
		.opcode_bin="0110001",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//6
	{
		.instr_name="CPFSGT",
		.opcode_bin="0110010",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//7
	{
		.instr_name="CPFSLT",
		.opcode_bin="0110000",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//8
	{
		.instr_name="DECF",
		.opcode_bin="000001",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//9
	{
		.instr_name="DECFSZ",
		.opcode_bin="001011",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//10
	{
		.instr_name="DCFSNZ",
		.opcode_bin="010011",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//11
	{
		.instr_name="INCF",
		.opcode_bin="001010",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//12
	{
		.instr_name="INCFSZ",
		.opcode_bin="001111",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//13
	{
		.instr_name="INFSNZ",
		.opcode_bin="010010",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//14
	{
		.instr_name="IORWF",
		.opcode_bin="000100",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//15
	{
		.instr_name="MOVF",
		.opcode_bin="010100",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//16
	{
		.instr_name="MOVFF",
		.opcode_bin="1100",
		.numb_bit=4,
		.arg_1=12,
		.arg_2=0,
		.arg_3=0
	},
	//17
	{
		.instr_name="MOVFF",
		.opcode_bin="1111",
		.numb_bit=4,
		.arg_1=12,
		.arg_2=0,
		.arg_3=0

	},
	//18
	{
		.instr_name="MOVWF",
		.opcode_bin="0110111",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//19
	{
		.instr_name="MULWF",
		.opcode_bin="0000001",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//20
	{
		.instr_name="NEGF",
		.opcode_bin="0110110",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//21
	{
		.instr_name="RLCF",
		.opcode_bin="001101",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//22
	{
		.instr_name="RLNCF",
		.opcode_bin="010001",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//23
	{
		.instr_name="RRCF",
		.opcode_bin="001100",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//24
	{
		.instr_name="RRNCF",
		.opcode_bin="010000",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//25
	{
		.instr_name="SETF",
		.opcode_bin="0110100",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//26
	{
		.instr_name="SUBFWB",
		.opcode_bin="010101",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//27
	{
		.instr_name="SUBWF",
		.opcode_bin="010111",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//28
	{
		.instr_name="SUBWFB",
		.opcode_bin="010110",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//29
	{
		.instr_name="SWAPF",
		.opcode_bin="001110",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//30
	{
		.instr_name="TSTFSZ",
		.opcode_bin="0110011",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=1,
		.arg_3=0
	},
	//31
	{
		.instr_name="XORWF",
		.opcode_bin="000110",
		.numb_bit=6,
		.arg_1=8,
		.arg_2=1,
		.arg_3=1
	},
	//Bit Oriented
	//32
	{
		.instr_name="BCF",
		.opcode_bin="1001",
		.numb_bit=4,
		.arg_1=8,
		.arg_2=3,
		.arg_3=1
	},
	//33
	{
		.instr_name="BSF",
		.opcode_bin="1000",
		.numb_bit=4,
		.arg_1=8,
		.arg_2=3,
		.arg_3=1
	},
	//34
	{
		.instr_name="BTFSC",
		.opcode_bin="1011",
		.numb_bit=4,
		.arg_1=8,
		.arg_2=3,
		.arg_3=1
	},
	//35
	{
		.instr_name="BTFSS",
		.opcode_bin="1010",
		.numb_bit=4,
		.arg_1=8,
		.arg_2=3,
		.arg_3=1
	},
	//36
	{
		.instr_name="BTG",
		.opcode_bin="0111",
		.numb_bit=4,
		.arg_1=8,
		.arg_2=3,
		.arg_3=1
	},
	//Control Operations
	//37
	{
		.instr_name="BC",
		.opcode_bin="11100010",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//38
	{
		.instr_name="BN",
		.opcode_bin="11100110",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//39
	{
		.instr_name="BNC",
		.opcode_bin="11100011",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//40
	{
		.instr_name="BNN",
		.opcode_bin="11100111",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//41
	{
		.instr_name="BNOV",
		.opcode_bin="11100101",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//42
	{
		.instr_name="BNZ",
		.opcode_bin="11100001",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//43
	{
		.instr_name="BOV",
		.opcode_bin="11100100",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//44
	{
		.instr_name="BRA",
		.opcode_bin="11010",
		.numb_bit=5,
		.arg_1=11,
		.arg_2=0,
		.arg_3=0
	},
	//45
	{
		.instr_name="BZ",
		.opcode_bin="11100000",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//46
	{
		.instr_name="CALL",
		.opcode_bin="1110110",
		.numb_bit=7,
		.arg_1=8,
		.arg_2=0,
		.arg_3=1
	},
	//47
	{
		.instr_name="CALL",
		.opcode_bin="1111",
		.numb_bit=4,
		.arg_1=12,
		.arg_2=0,
		.arg_3=0
	},
	//48
	{
		.instr_name="CLRWDT",
		.opcode_bin="0000000000000100",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//49
	{
		.instr_name="DAW",
		.opcode_bin="0000000000000111",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//50
	{
		.instr_name="GOTO",
		.opcode_bin="11101111",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//51
	{
		.instr_name="GOTO",
		.opcode_bin="1111",
		.numb_bit=4,
		.arg_1=12,
		.arg_2=0,
		.arg_3=0
	},
	//52
	{
		.instr_name="NOP",
		.opcode_bin="0000000000000000",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//53
	{
		.instr_name="NOP",
		.opcode_bin="1111000000000000",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//54
	{
		.instr_name="POP",
		.opcode_bin="0000000000000110",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//55
	{
		.instr_name="PUSH",
		.opcode_bin="0000000000000101",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//56
	{
		.instr_name="RCALL",
		.opcode_bin="11011",
		.numb_bit=5,
		.arg_1=11,
		.arg_2=0,
		.arg_3=0
	},
	//57
	{
		.instr_name="RESET",
		.opcode_bin="0000000011111111",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//58
	{
		.instr_name="RETFIE",
		.opcode_bin="000000000001000",
		.numb_bit=15,
		.arg_1=0,
		.arg_2=0,
		.arg_3=1
	},
	//59
	{
		.instr_name="RETLW",
		.opcode_bin="00001100",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//60
	{
		.instr_name="RETURN",
		.opcode_bin="000000000001001",
		.numb_bit=15,
		.arg_1=0,
		.arg_2=0,
		.arg_3=1
	},
	//61
	{
		.instr_name="SLEEP",
		.opcode_bin="0000000000000011",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//Literal Operations
	//62
	{
		.instr_name="ADDLW",
		.opcode_bin="00001111",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//63
	{
		.instr_name="ANDLW",
		.opcode_bin="00001011",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//64
	{
		.instr_name="IORLW",
		.opcode_bin="00001001",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//65
	{
		.instr_name="LFSR",
		.opcode_bin="1110111000",
		.numb_bit=10,
		.arg_1=2,
		.arg_2=4,
		.arg_3=0
	},
	//66
	{
		.instr_name="LFSR",
		.opcode_bin="11110000",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//67
	{
		.instr_name="MOVLB",
		.opcode_bin="000000010000",
		.numb_bit=12,
		.arg_1=4,
		.arg_2=0,
		.arg_3=0
	},
	//68
	{
		.instr_name="MOVLW",
		.opcode_bin="00001110",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//69
	{
		.instr_name="MULLW",
		.opcode_bin="00001101",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//70
	{
		.instr_name="RETLW",
		.opcode_bin="00001100",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//71
	{
		.instr_name="SUBLW",
		.opcode_bin="00001000",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//72
	{
		.instr_name="XORLW",
		.opcode_bin="00001010",
		.numb_bit=8,
		.arg_1=8,
		.arg_2=0,
		.arg_3=0
	},
	//73
	{
		.instr_name="TBLRD*",
		.opcode_bin="0000000000001000",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//74
	{
		.instr_name="TBLRD*+",
		.opcode_bin="0000000000001001",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//75
	{
		.instr_name="TBLRD*-",
		.opcode_bin="0000000000001010",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//76
	{
		.instr_name="TBLRD+*",
		.opcode_bin="0000000000001011",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//77
	{
		.instr_name="TBLWT*",
		.opcode_bin="0000000000001100",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//78
	{
		.instr_name="TBLWT*+",
		.opcode_bin="0000000000001101",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//79
	{
		.instr_name="TBLWT*-",
		.opcode_bin="0000000000001110",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	},
	//80
	{
		.instr_name="TBLWT+*",
		.opcode_bin="0000000000001111",
		.numb_bit=16,
		.arg_1=0,
		.arg_2=0,
		.arg_3=0
	}
};
