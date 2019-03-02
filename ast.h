#define PROGRAM 1
#define CLASSDECLLIST 2
#define VARDECLLIST 3
#define MAINCLASS 4
#define CLASSDECL 5
#define VARDECL 6
#define TYPE 7
#define PRIMTYPE 8
#define METHODDECLLIST 9
#define METHODDECL 10
#define FORMALLIST 11
#define FORMALRESTLIST 12
#define FORMALREST 13
#define TYPEPRIM 15
#define TYPEARR 16
#define ARRAYTYPE 18
#define CLASSDECLSIMPLE 19
#define CLASSDECLEXTENDS 20
#define PRIMTYPEINT 21
#define PRIMTYPEBOOL 22
#define PRIMTYPEID 23
#define STATEMENTLIST 24
#define STATEMENT 26
#define BLOCK 27
#define PRINTLNEXP 30
#define PRINTLNSTR 33
#define PRINTEXP 34
#define PRINTSTR 35
#define ASSIGN 36
#define ARRASSGN 39
#define RET 40
#define MULTIINDEX 42
#define PLUS 43
#define MINUS 44
#define TIMES 45
#define DIVIDE 46
#define NEGATE 47
#define BINARYOP 48
#define EXP 49
#define LESSTHAN 50
#define GREATTHAN 51
#define UNARYOP 52
#define EXPTRUE 55
#define EXPFALSE 56
#define EXPOBJECT 57
#define OBJECT 58
#define PAREN 59
#define ARRLOOKUP 60
#define IDENTIFIERLEN 61
#define ARRLEN 62
#define IDENTIFIER 63
#define ASSGN 66
#define INDEX 67
#define EXPINT 68
#define CALL 69
#define OBJID 70
#define OBJTHIS 71
#define NEWOBJ 72
#define NEWARR 73
#define EXPLIST 74
#define EXPRESTLIST 75
#define EXPREST 76
#define INTEGERTYPE 77
#define BOOLEANTYPE 78


typedef struct Program Program;
typedef struct MainClass MainClass;
typedef struct ClassDeclList ClassDeclList;
typedef struct ClassDecl ClassDecl;
typedef struct ClassDeclSimple ClassDeclSimple;
typedef struct ClassDeclExtends ClassDeclExtends;
typedef struct VarDecl VarDecl;
typedef struct VarDeclList VarDeclList;
typedef struct MethodDeclList MethodDeclList;
typedef struct MethodDecl MethodDecl;
typedef struct FormalList FormalList;
typedef struct FormalRestList FormalRestList;
typedef struct FormalRest FormalRest;
typedef struct Type Type;
typedef struct ArrayType ArrayType;
typedef struct PrimType PrimType;
typedef struct IntegerType IntegerType;
typedef struct BooleanType BooleanType;
typedef struct Identifier Identifier;
typedef struct StatementList StatementList;
typedef struct Statement Statement;
typedef struct Block Block;
typedef struct If If;
typedef struct While While;
typedef struct Print Print;
typedef struct Assign Assign;
typedef struct ArrayAssign ArrayAssign;
typedef struct Index Index;
typedef struct MultiIndex MultiIndex;
typedef struct Exp Exp;
typedef struct BinaryOp BinaryOp;
typedef struct UnaryOp UnaryOp;
typedef struct ArrayLookup ArrayLookup;
typedef struct ArrayLength ArrayLength;
typedef struct Object Object;
typedef struct This This;
typedef struct NewObject NewObject;
typedef struct NewArray NewArray;
typedef struct ParenExp ParenExp;
typedef struct Call Call;
typedef struct IntegerLiteral IntegerLiteral;
typedef struct Boolean Boolean;
typedef struct ExpList ExpList;
typedef struct ExpRestList ExpRestList;
typedef struct ExpRest ExpRest;
typedef struct AST_Node AST_Node;
typedef struct Table Table;
typedef struct Entry Entry;
typedef struct IdentifierLength IdentifierLength;
typedef struct StringLiteral StringLiteral;

AST_Node * mknode0(int mode);
AST_Node * mknode1(int mode, AST_Node * n1);
AST_Node * mknode2(int mode, AST_Node * n1, AST_Node * n2);
AST_Node * mknode3(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3);
AST_Node * mknode4(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3, AST_Node * n4);
AST_Node * mknode5(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3, AST_Node * n4, AST_Node * n5);
AST_Node * mknode6(int mode, AST_Node * n1, AST_Node * n2, AST_Node * n3, AST_Node * n4, AST_Node * n5, AST_Node * n6);

struct Table {
	int size;
	Entry * entries[];
};

struct Entry {
	int mode;
	union {
		Identifier * i;
		IntegerLiteral * il;
		Boolean * b;
	};
};

struct AST_Node {
	int mode;
	union {
		Program * program; 
		MainClass * mainclass;
		ClassDeclList * classdecllist;
		ClassDecl * classdecl;
		VarDecl * vardecl;
		VarDeclList * vardecllist;
		MethodDeclList * methoddecllist;
		MethodDecl * methoddecl;
		FormalList * formallist;
		FormalRestList * formalrestlist;
		FormalRest * formalrest;
		Type * type;
		PrimType * primetype;
		Identifier * identifier;
		StatementList * statementlist;
		Statement * statement;
		Index * index;
		Exp * exp;
		Object * object;
		IntegerLiteral * integerliteral;
		StringLiteral * stringliteral;
		ExpList * explist;
		ExpRestList * exprestlist;
		ExpRest * exprest;
		PrimType * primtype;
	};
};

struct ExpList {
	Exp * e;
	ExpRestList * erl;
};

struct ExpRestList {
	ExpRest * head;
	ExpRest * curr;
};

struct ExpRest {
	Exp * e;
	ExpRest * next;
};

struct Exp {
	int mode;
	union {
		BinaryOp * bo;
		UnaryOp * uo;
		ArrayLookup * alook;
		ArrayLength * alen;
		IdentifierLength * ilen;
		Boolean * b;
		IntegerLiteral * il;
		Object * o;
		ParenExp * pe;
		Call * c;
	};
};

struct Boolean {
	int value;
};

struct IntegerLiteral {
	int value;
};

struct Call {
	Object * o;
	Identifier * i;
	ExpList * el;
};

struct BinaryOp {
	int op;
	Exp * e1;
	Exp * e2;
};

struct UnaryOp {
	int op;
	Exp * e;
};

struct ArrayLookup {
	Identifier * i;
	Index * ix;
};

struct ArrayLength {
	Identifier * i;
	Index * ix;
};

struct IdentifierLength {
	Identifier * i;
};

struct ParenExp {
	Exp * e;
};

struct Object {
	int mode;
	union {
		Identifier * i;
		This * t;
		NewObject * no;
		NewArray * na;
	};
};

struct This {

};

struct NewObject {
	Identifier * i;
};

struct NewArray {
	PrimType * pt;
	Index * ix;
};

struct MultiIndex {
	Index * ix;
	Exp * e;
};

struct Index {
	int mode;
	union {
		Exp * e;
		MultiIndex * mi;
	};
};

struct Identifier {
	char * name;
};

struct BooleanType {

};

struct IntegerType {

};

struct StatementList {
	Statement * head;
	Statement * curr;
};

struct Statement {
	int mode;
	union {
		Block * b;
		If * i;
		While * w;
		Print * p;
		Assign * a;
		ArrayAssign * aa;
		Exp * e;
	};
	Statement * next;
};

struct Block {
	StatementList * sl;
};

struct If {
	Exp * e;
	Statement * s1;
	Statement * s2;
};

struct While {
	Exp * e;
	Statement * s;
};

struct StringLiteral {
	char * str;
};

struct Print {
	int newline;
	int mode;
	union {
		Exp * e;
		StringLiteral * sl;
	};
};

struct Assign {
	Identifier * i;
	Exp * e;
};

struct ArrayAssign {
	Identifier * i;
	Index * ix;
	Exp * e;
};

struct PrimType {
	int mode;
	union {
		IntegerType * it;
		BooleanType * bt;
		Identifier * i;
	};
};

struct ArrayType {
	Type * t;
};

struct Type {
	int mode;
	union {
		PrimType * pt;
		ArrayType * at;
	};
};
	
struct FormalRest {
	Type * t;
	Identifier * i;
	FormalRest * next;
};

struct FormalRestList {
	FormalRest * head;
	FormalRest * curr;
};

struct FormalList {
	Type * t;
	Identifier * i;
	FormalRestList * fr;
};

struct MethodDecl {
	Type * t;
	Identifier * i;
	FormalList * fl;
	VarDeclList * vl;
	StatementList * sl;
	Exp * e;
	MethodDecl * next;
};

struct MethodDeclList {
	MethodDecl * head;
	MethodDecl * curr;
};

struct VarDecl {
	Type * t;
	Identifier * i;
	VarDecl * next;
};

struct VarDeclList {
	VarDecl * head;
	VarDecl * curr;
};

struct ClassDeclExtends {
	Identifier * i1;
	Identifier * i2;
	VarDeclList * vl;
	MethodDeclList * ml;
};

struct ClassDeclSimple {
	Identifier * i;
	VarDeclList * vl;
	MethodDeclList * ml;
};

struct ClassDecl {
	int mode;
	union {
		ClassDeclSimple * cs;
		ClassDeclExtends * ce;
	};
	ClassDecl * next;
};

struct ClassDeclList {
	ClassDecl * head;
	ClassDecl * curr;
};

struct MainClass {
	Identifier * i1;
	Identifier * i2;
	Statement * s;
};

struct Program {
	MainClass * m;
	ClassDeclList * cl;
};


