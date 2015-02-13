#ifndef __STATES_H__
#define __STATES_H__

enum COMPILER_PHASE {
    CP_SCANNING = 0,
    CP_PARSING,
    CP_WEEDING,
    CP_SYMBOLTABLE_GEN,
    CP_NAME_RESOLUTION,
    CP_TYPE_CHECKING,
    CP_STATIC_ANAYLSIS,
    CP_OPTIMIZATION,
    CP_CODE_GEN,
    CP_TOTAL_PHASES,
};

enum DFA_STATES {
    // Shared DFA States
    DS_ERROR = 0,
    DS_START,
    DS_RUNNING,
    DS_ABORT,
    DS_ACCEPT,

    // Keyword DFA States
    DS_A,
    DS_B,
    DS_C,
    DS_D,
    DS_E,
    DS_F,
    DS_I,
    DS_G,
    DS_L,
    DS_N,
    DS_P,
    DS_R,
    DS_S,
    DS_T,
    DS_V,
    DS_W,
    DS_AB,
    DS_AS,
    DS_BO,
    DS_BR,
    DS_BY,
    DS_CA,
    DS_CH,
    DS_CL,
    DS_CO,
    DS_DE,
    DS_DO,
    DS_EL,
    DS_EN,
    DS_EX,
    DS_FI,
    DS_FL,
    DS_FO,
    DS_IF,
    DS_GO,
    DS_IM,
    DS_IN,
    DS_LO,
    DS_NA,
    DS_NE,
    DS_NU,
    DS_PA,
    DS_PR,
    DS_PU,
    DS_RE,
    DS_SH,
    DS_ST,
    DS_SU,
    DS_SW,
    DS_SY,
    DS_TH,
    DS_TR,
    DS_VO,
    DS_WH,
    DS_ABS,
    DS_ASS,
    DS_BOO,
    DS_BRE,
    DS_BYT,
    DS_CAS,
    DS_CAT,
    DS_CHA,
    DS_CLA,
    DS_CON,
    DS_DEF,
    DS_DOU,
    DS_ELS,
    DS_ENU,
    DS_EXT,
    DS_FIN,
    DS_FLO,
    DS_FOR,
    DS_GOT,
    DS_IMP,
    DS_INS,
    DS_INT,
    DS_LON,
    DS_NAT,
    DS_NEW,
    DS_NUL,
    DS_PAC,
    DS_PRI,
    DS_PRO,
    DS_PUB,
    DS_RET,
    DS_SHO,
    DS_STA,
    DS_STR,
    DS_SUP,
    DS_SWI,
    DS_SYN,
    DS_THI,
    DS_THR,
    DS_TRA,
    DS_TRY,
    DS_VOI,
    DS_VOL,
    DS_WHI,
    DS_ABST,
    DS_ASSE,
    DS_BOOL,
    DS_BREA,
    DS_BYTE,
    DS_CASE,
    DS_CATC,
    DS_CHAR,
    DS_CLAS,
    DS_CONS,
    DS_CONT,
    DS_DEFA,
    DS_DOUB,
    DS_ELSE,
    DS_ENUM,
    DS_EXTE,
    DS_FINA,
    DS_FLOA,
    DS_GOTO,
    DS_IMPL,
    DS_IMPO,
    DS_INST,
    DS_INTE,
    DS_LONG,
    DS_NATI,
    DS_NULL,
    DS_PACK,
    DS_PRIV,
    DS_PROT,
    DS_PUBL,
    DS_RETU,
    DS_SHOR,
    DS_STAT,
    DS_STRI,
    DS_SUPE,
    DS_SWIT,
    DS_SYNC,
    DS_THIS,
    DS_THRO,
    DS_TRAN,
    DS_VOID,
    DS_VOLA,
    DS_WHIL,
    DS_ABSTR,
    DS_ASSER,
    DS_BOOLE,
    DS_BREAK,
    DS_CATCH,
    DS_CLASS,
    DS_CONST,
    DS_CONTI,
    DS_DEFAU,
    DS_DOUBL,
    DS_EXTEN,
    DS_FINAL,
    DS_FLOAT,
    DS_IMPLE,
    DS_IMPOR,
    DS_INSTA,
    DS_INTER,
    DS_NATIV,
    DS_PACKA,
    DS_PRIVA,
    DS_PROTE,
    DS_PUBLI,
    DS_RETUR,
    DS_SHORT,
    DS_STATI,
    DS_STRIC,
    DS_SUPER,
    DS_SWITC,
    DS_SYNCH,
    DS_THROW,
    DS_TRANS,
    DS_VOLAT,
    DS_WHILE,
    DS_ABSTRA,
    DS_ASSERT,
    DS_BOOLEA,
    DS_CONTIN,
    DS_DEFAUL,
    DS_DOUBLE,
    DS_EXTEND,
    DS_FINALL,
    DS_IMPLEM,
    DS_IMPORT,
    DS_INSTAN,
    DS_INTERF,
    DS_NATIVE,
    DS_PACKAG,
    DS_PRIVAT,
    DS_PROTEC,
    DS_PUBLIC,
    DS_RETURN,
    DS_STATIC,
    DS_STRICT,
    DS_SWITCH,
    DS_SYNCHR,
    DS_THROWS,
    DS_TRANSI,
    DS_VOLATI,
    DS_ABSTRAC,
    DS_BOOLEAN,
    DS_CONTINU,
    DS_DEFAULT,
    DS_EXTENDS,
    DS_FINALLY,
    DS_IMPLEME,
    DS_INSTANC,
    DS_INTERFA,
    DS_PACKAGE,
    DS_PRIVATE,
    DS_PROTECT,
    DS_STRICTF,
    DS_SYNCHRO,
    DS_TRANSIE,
    DS_VOLATIL,
    DS_ABSTRACT,
    DS_CONTINUE,
    DS_IMPLEMEN,
    DS_INSTANCE,
    DS_INTERFAC,
    DS_PROTECTE,
    DS_STRICTFP,
    DS_SYNCHRON,
    DS_TRANSIEN,
    DS_VOLATILE,
    DS_IMPLEMENT,
    DS_INSTANCEO,
    DS_INTERFACE,
    DS_PROTECTED,
    DS_SYNCHRONI,
    DS_TRANSIENT,
    DS_IMPLEMENTS,
    DS_INSTANCEOF,
    DS_SYNCHRONIZ,
    DS_SYNCHRONIZE,
    DS_SYNCHRONIZED,

    // Valid number DFA states
    DS_ZERO,

    // Char or string literal DFA states
    DS_SINGLEQUOTE,
    DS_DOUBLEQUOTE,
    DS_ENCLOSESINGLE,
    DS_ESCAPESINGLE,
    DS_ESCAPEDOUBLE,
    DS_OCTALSINGLE,
    DS_OCTALDOUBLE,
    DS_ACCEPTCHAR,
    DS_ACCEPTSTRING,

    // Separator DFA states
    
    // Operator DFA states
    DS_CHECKEQUAL,
    DS_CHECKLAZYOP,
    DS_PLUS,
    DS_MINUS,

    //Comment DFA states
    DS_SLASHFIRST,
    DS_STARSECOND,
    DS_MIDCOMMENT,
};

#endif
