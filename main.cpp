#include <iostream>

using namespace std;

//CLASA MEA
template <class VT,unsigned n>
class VectorTemplate
{
    VT *array;
    unsigned capacitate;
    unsigned dim;


    public:
        VectorTemplate();
        VectorTemplate(int);
        unsigned getSize();
        template<class WT,unsigned m>
        friend ostream& operator << (ostream&, const VectorTemplate<WT,m>&);
        VT& operator[](unsigned) const;
        VectorTemplate (const VectorTemplate &);
        VectorTemplate& operator = (const VectorTemplate&);
        VectorTemplate operator+(const VectorTemplate &);
        VectorTemplate operator-(const VectorTemplate &);
        VectorTemplate operator*(const VectorTemplate &);
        friend VectorTemplate operator*(int,const VectorTemplate &);
        //virtual ~VectorTemplate();


};

//CONSTRUCTOR GOL
template <typename VT,unsigned n>
VectorTemplate<VT,n>::VectorTemplate()
{
    capacitate=0;
    dim=n;
    array=new VT[n];
    for (int i=0;i<n;i++)
    {
        array[i]=0;
    }
}


//CONSTRUCTOR CU X PESTE TOT
template <typename VT,unsigned n>
VectorTemplate<VT,n>::VectorTemplate(int x)
{
    capacitate=0;
    dim=n;
    array=new VT[n];
    for (unsigned int i=0;i<n;i++)
    {
        array[i]=x;
    }

}

//COUT
template <typename VT,unsigned n>
ostream& operator << (ostream& out, const VectorTemplate<VT,n>& vt) {
    for(unsigned i=0;i<vt.dim;i++)
    {
        out<<vt.array[i]<<' ';
    }
    return out;
}

//RETURNEAZA DIMENSIUNEA
template <typename VT,unsigned n>
unsigned VectorTemplate<VT,n>::getSize ()
{
    return dim;
}

//VT[I]
template <typename VT,unsigned n>
VT& VectorTemplate<VT,n>::operator [](unsigned i) const
{
    return array[i];
}

//CONSTRUCTOR DE COPIERE
template <typename VT,unsigned n>
VectorTemplate<VT,n>::VectorTemplate(const VectorTemplate<VT,n> &vt)
{
    dim=vt.dim;
    capacitate=vt.capacitate;
    this->array=new VT[dim];
    for(int i=0;i<dim;i++)
        this->array[i]=vt.array[i];
}

//OPERATOR =
template <typename VT,unsigned n>
VectorTemplate<VT,n>& VectorTemplate<VT,n>::operator=(const VectorTemplate<VT,n>& vt)
{
    delete[] this->vt;
    this->dim=vt.dim;
    this->capacitate=vt.capacitate;
    this->VT=new VT[this->dim];
    for (int i=0; i<this->dim; i++)
        this->VT[i]=vt.VT[i];
    return *this;
}

//OPERATOR +
template <typename VT,unsigned n>
VectorTemplate<VT,n> VectorTemplate<VT,n>::operator+(const VectorTemplate<VT,n> &vt)
{
    VectorTemplate<int,n> wt(dim);
    wt.dim=dim;

    for(int i=0;i<dim;i++)
    {
        wt[i]=vt.array[i]+this->array[i];
    }
    return wt;
}

//OPERATOR -
template <typename VT,unsigned n>
VectorTemplate<VT,n> VectorTemplate<VT,n>::operator-(const VectorTemplate<VT,n> &vt)
{
    VectorTemplate<int,n> wt(dim);
    wt.dim=dim;

    for(int i=0;i<dim;i++)
    {
        wt[i]=vt.array[i]-this->array[i];
    }
    return wt;
}

//OPERATOR * CU UN INT.
template <typename VT,unsigned n>
VectorTemplate<VT,n> operator * (int x, const VectorTemplate<VT,n> &vt)
{
    VectorTemplate<VT,n> wt;
    for(int i=0; i<vt.dim; i++)
    {
        wt[i]=x*vt.array[i];
    }
    return wt;
}

template <typename VT,unsigned n>
VectorTemplate<VT,n> VectorTemplate<VT,n>::operator * (const VectorTemplate<VT,n> &vt)
{
    VectorTemplate<VT,n> wt;
    for(int i=0; i<vt.dim; i++)
    {
        wt[i]=this->array[i]*vt.array[i];
    }
    return wt;
}


/*
VectorTemplate::~VectorTemplate()
{
    //dtor
}
*/



int main()
{

    VectorTemplate <int,15> vt(3);
    VectorTemplate <int,15> wt(2);
    cout<<vt<<endl<<wt<<endl;
    cout<<vt+wt<<endl;
    cout<<vt*wt;
    //cout<<3*vt;

    return 0;
}
