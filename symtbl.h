#include "y.tab.h"

void buildSymTbl(AST_Node * node);
int getIndex(Identifier * i, SymTbl * tbl);
Type * getType(Identifier * i, SymTbl * classTbl, SymTbl * methodTbl);
