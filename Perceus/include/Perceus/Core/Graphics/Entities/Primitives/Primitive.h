#pragma once

#include "Perceus/Data/Inc.h"
#include "../Model.h"

#define PRIMITIVE_TYPE(class_name) \
    struct PERC_API class_name##Type : public IPrimitiveType<class_name##Type> {\
    protected:\
        void genRawModel(RawModel*& rawModel) override;\
        \
        std::string getName() const override { return #class_name; }\
    };\
    typedef Primitive<class_name##Type> class_name;

namespace pcs
{
    template<typename T>
    struct IPrimitiveType
    {
        static RawModel* getRawModel()
        {
            static RawModel* rawModel;
            if (!rawModel)
            { 
                IPrimitiveType<T>* t = new T();
                PS_CORE_DEBUG("Generating Primitive: {0}", t->getName());

                t->genRawModel(rawModel);

                delete t;
            }
            return rawModel;
        }

        virtual std::string getName() const = 0;

    protected:
        virtual void genRawModel(RawModel*& rawModel) = 0;
    };

    template<typename _PRIM_TYPE>
    class PERC_API Primitive : public pcs::Model
    {
    public:
        Primitive();
    };

    PRIMITIVE_TYPE(Plane );
    PRIMITIVE_TYPE(Sphere);
    PRIMITIVE_TYPE(Cube  );
}