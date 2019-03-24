#include "y.tab.h"

PrimType * getPrimType(Type * t);
ClassDecl * findClass(Identifier * i);
MethodDecl * findMethod(ClassDecl * cd, Identifier * i, ExpList * el);
int identifiersEqual(Identifier * i1, Identifier * i2);
int typecheckArrayLookup(Exp * e, int lineno);
int typecheckArrayAssign(ArrayAssign * aa, int lineno);
int typecheckCall(Exp * e, int lineno);
int typecheckArrayLen(Exp * e, int lineno);
int typecheckIdentifierLen(Exp * e, int lineno);
int typecheckParen(Exp * e, int lineno);
int typecheckBinaryOp(Exp * e, int lineno);
int typecheckUnaryOp(Exp * e, int lineno);
int typecheckObject(Exp * e, int lineno);
int typecheckFormalRest(FormalRest * fr, int lineno);
int typecheckVarDecl(VarDecl * vd, int lineno);
int typecheckClassDecl(ClassDecl * cl, int lineno);
int typecheckMethodDecl(MethodDecl * md, int lineno);
int typecheckIf(If * i, int lineno);
int typecheckWhile(While * w, int lineno);
int typecheckType(Type * t, int lineno);
int typecheckFormalList(FormalList * fl, int lineno);
int typecheckReturn(Exp * e, int lineno);
int typecheckIntegerLiteral(Exp * e, int lineno);
int typecheckBoolean(Exp * e, int lineno);
int typecheckAssign(Assign * a, int lineno);
int typecheckPrint(Print * p, int lineno);
int typecheckIndex(Index * i, int lineno);
