#ifndef VECTORTEMPLATE_H
#define VECTORTEMPLATE_H

template <class VT,unsigned n>
class VectorTemplate
{
    VT *array;
    unsigned capacitate;
    unsigned dim;


    public:
        VectorTemplate();
        unsigned getSize();
        //virtual ~VectorTemplate();


};

#endif // VECTORTEMPLATE_H
