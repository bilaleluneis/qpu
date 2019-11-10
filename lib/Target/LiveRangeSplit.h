#ifndef _LIVERANGESPLIT_H_
#define _LIVERANGESPLIT_H_

#include "../Common/Seq.h"
#include "CFG.h"
#include "Syntax.h"

void liveRangeSplit(Seq<Instr>* instrs, CFG* cfg);

#endif
