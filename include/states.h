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

#endif
