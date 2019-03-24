#include "y.tab.h"

void interpretObject(Exp * e);
void interpretReturn(Exp * e);
void interpretMethodDecl(MethodDecl * md);
void interpretAssign(Assign * a);
void interpretCall(Exp * e);
void interpretIntegerLiteral(Exp * exp);
void interpretBoolean(Exp * exp);
void interpretParen(Exp * exp);
void interpretBinaryOp(Exp * exp);
void interpretUnaryOp(Exp * exp);
void interpretIf(If * i);
void interpretWhile(While * w);
void interpretPrint(Print * p);