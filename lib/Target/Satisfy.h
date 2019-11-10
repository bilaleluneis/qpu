#ifndef _SATISFY_H_
#define _SATISFY_H_

#include "Syntax.h"
#include "CFG.h"

RegTag regFileOf(Reg r);
void satisfy(Seq<Instr>* instrs);

#endif
