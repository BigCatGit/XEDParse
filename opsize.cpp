#include "Translator.h"

unsigned int opsizetobits(OPSIZE opsize)
{
	return OpsizeEntryTable[opsize].Bits;
} 

int opsizetoint(OPSIZE opsize)
{
	return OpsizeEntryTable[opsize].Bytes;
}

OPSIZE bitstoopsize(int bits)
{
	return inttoopsize(bits / 8);
}

OPSIZE inttoopsize(int opsize)
{
	//return OpsizeEntryTable[log2(opsize) - 3].Size;

	switch (opsize)
	{
	case 1:		return SIZE_BYTE;
	case 2:		return SIZE_WORD;
	case 4:		return SIZE_DWORD;
	case 8:		return SIZE_QWORD;
	case 16:	return SIZE_XMMWORD;
	case 32:	return SIZE_YMMWORD;
	case 64:	return SIZE_ZMMWORD;
	}

	return SIZE_UNSET;
}

int opsizetoeosz(OPSIZE Value)
{
	// Opsize to XED's effective operand size
	switch (Value)
	{
	case SIZE_BYTE:		return 0;
	case SIZE_WORD:		return 1;
	case SIZE_DWORD:	return 2;
	case SIZE_QWORD:	return 3;
	}

	return 0;
}

OPSIZE StringToOpsize(const char *Value)
{
	for (int i = 0; i < ARRAYSIZE(OpsizeEntryTable); i++)
	{
		if (!_stricmp(OpsizeEntryTable[i].Name, Value))
			return OpsizeEntryTable[i].Size;
	}

	return SIZE_UNSET;
}

const char *OpsizeToString(OPSIZE Size)
{
	return OpsizeEntryTable[Size].Name;
}