#ifndef REV1_H
#define REV1_H

#include "../6pack.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

//void promicro_bootloader_jmp(bool program);

#define LAYOUT( \
	K00, K01, K02, \
	K10, K11, K12 \
	) \
	{ \
		{ K00, K01, K02 }, \
		{ K10, K11, K12 } \
	}

#endif