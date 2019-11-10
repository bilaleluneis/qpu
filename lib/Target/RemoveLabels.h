#ifndef _REMOVELABELS_H_
#define _REMOVELABELS_H_

#include "Syntax.h"
#include "CFG.h"
#include "Liveness.h"
#include "../Common/Seq.h"

// Remove all labels, replacing absolute branch-label instructions
// with relative branch-target instructions.
void removeLabels(Seq<Instr>* instrs);

#endif
