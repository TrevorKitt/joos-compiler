#ifndef __OBJECTLAYOUT_H__
#define __OBJECTLAYOUT_H__

class CompilationTable;
class FieldTable;

#include <vector>
#include <map>
#include <fstream>

class ObjectLayout {
    // Layout of an object
    /*****************************
     *    length (if an array)   *
     *---------------------------*
     *     static indicator      *
     *---------------------------*
     *     virtual table         *
     *---------------------------*
     *     inheritance table     *
     *---------------------------*
     *   interface method table  *
     *---------------------------*
     *         members           *
     *                           *
     * --------------------------*/

    private:
        // fields declared in the class, in the order they were declared
        // with superclass's fields coming first
        std::vector<FieldTable*> declaredFields;
        std::map<FieldTable*, bool> staticFieldsIndicator;

        void createLayout(ObjectLayout* parentLayout, CompilationTable*);
    public:
        ObjectLayout(ObjectLayout*, CompilationTable*);

        unsigned int sizeOfObject();
        unsigned int indexOfFieldInObject(FieldTable*);
        void generateStaticIndicatorRowToFile(std::ofstream&);
};

#endif
