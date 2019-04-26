#include <stdlib.h>
#include "y.tab.h"
#include <string.h>

int getIndex(Identifier * i, SymTbl * tbl) {
	for (int j = 0; j < tbl->size; j++) {
		if (strcmp(i->name, tbl->entries[j].i->name) == 0) { return j; }
	}
	return -1;
}

Type * getType(Identifier * i, SymTbl * classTbl, SymTbl * methodTbl) {
	for (int j = 0; j < methodTbl->size; j++) {
		if (strcmp(i->name, methodTbl->entries[j].i->name) == 0) { return methodTbl->entries[j].t; }
	}
	for (int j = 0; j < classTbl->size; j++) {
		if (strcmp(i->name, classTbl->entries[j].i->name) == 0) { return classTbl->entries[j].t; }
	}
	return 0;
}

void buildSymTbl(AST_Node * node) {
	SymTbl * tbl = malloc(sizeof(SymTbl));
	Entry * entries;

	switch (node->mode) {
	case METHODDECL:
	{
		MethodDecl * md = node->methoddecl;
		tbl->size = md->vl->count + md->fl->count;

		if (tbl->size != 0) {
			entries = malloc(tbl->size * sizeof(Entry));

			int i = 0;
			FormalRest * currFormalRest = md->fl->head;
			while (currFormalRest != NULL) {
				entries[i].i = currFormalRest->i;
				entries[i++].t = currFormalRest->t;
				currFormalRest = currFormalRest->next;
			}
			VarDecl * currVarDecl = md->vl->head;
			while (currVarDecl != NULL) {
				entries[i].i = currVarDecl->i;
				entries[i++].t = currVarDecl->t;
				currVarDecl = currVarDecl->next;
			}
			tbl->entries = entries;
		}
		md->tbl = tbl;
		break;
	}
	case CLASSDECL:
	{
		int i = 0;
		ClassDecl * cd = node->classdecl;
		while (1) {
			if (cd->vl->count != 0) {
				tbl->size += cd->vl->count;
				entries = realloc(entries, tbl->size * sizeof(Entry));

				VarDecl * currVarDecl = cd->vl->head;
				while (currVarDecl != NULL) {
					entries[i].i = currVarDecl->i;
					entries[i++].t = currVarDecl->t;
					currVarDecl = currVarDecl->next;
				}
			}
			if (cd->mode != CLASSDECLEXTENDS) { break; }
			cd = findClass(cd->i2);
		}
		if (tbl->size != 0) { tbl->entries = entries; }
		node->classdecl->tbl = tbl;
		break;
	}
	}
}