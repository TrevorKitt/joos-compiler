#ifndef __LOCALTABLE_H__
#define __LOCALTABLE_H__

#include "symbolTable.h"

class LocalDecl;

class LocalTable : public SymbolTable {
    private:
        LocalDecl* local;
    public:
        LocalTable(LocalDecl* local) : SymbolTable(STT_LOCAL), local(local) {}
        ~LocalTable() {}

        LocalDecl* getLocalDecl() { return local; }
};

#endif
