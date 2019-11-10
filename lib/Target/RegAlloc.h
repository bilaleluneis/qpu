#ifndef _REGALLOC_H_
#define _REGALLOC_H_

#include "CFG.h"
#include "Liveness.h"
#include "Syntax.h"
#include "../Common/Seq.h"

void regAlloc(CFG* cfg, Seq<Instr>* instrs);

#endif
