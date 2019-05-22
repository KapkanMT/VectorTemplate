#include "include\VectorTemplate.h"

template <class VT,unsigned n>
VectorTemplate<VT,n>::VectorTemplate()
{
    capacitate=0;
    dim=n;
    array=new VT[n];

}

template <typename VT,unsigned n>
unsigned VectorTemplate<VT,n>::getSize ()
{
    return dim;
}


/*
VectorTemplate::~VectorTemplate()
{
    //dtor
}
*/
