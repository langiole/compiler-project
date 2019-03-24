#include "y.tab.h"

int TYPECHECK;
int TYPEERR;

ClassDeclList * CLASS_DECL_LIST;
ClassDecl * CURR_CLASS;
MethodDecl * CURR_METHOD;

void dfs(AST_Node * root);