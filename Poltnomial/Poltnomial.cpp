 #include <algorithm>
#include "Poltnomial.h"
using namespace std;
Polynomial Polynomial::Add(Polynomial a,Polynomial b)
{
    Polynomial c;
    int aPos=0;
    int bPos=0;
    while((aPos<a.terms)&&(bPos<b.terms))                       //a,b两个任意多项式没有搜到数组尾的时候
    {
        if((a.termArray[aPos].exp)==(b.termArray[bPos].exp))    //如果指数相同，系数相加
        {
            float t;
            t=a.termArray[aPos].coef+b.termArray[bPos].coef;
            if(t){ c.NewTerm(c,t,c.termArray[aPos].exp);}                //相加后归到c数组
            aPos++;             
            bPos++;
        }
        else if(a.termArray[aPos].exp<b.termArray[bPos].exp)             //因为多项式从大到小，所以B大的B先归
        {
            c.NewTerm(b,b.termArray[bPos].coef,b.termArray[bPos].exp);
            bPos++;
        }
        else                                                             //因为多项式从大到小，所以A大的A先归        
        {
            c.NewTerm(a,a.termArray[aPos].coef,a.termArray[aPos].exp);
            aPos++;
        }
        for(;aPos<=a.terms;aPos++)                                       //任意一个多项式处理完则直接把另一个多项式加到队尾
        {
            c.NewTerm(a,a.termArray[aPos].coef,a.termArray[aPos].exp);
        }
        for(;bPos<=b.terms;bPos++)
        {
            c.NewTerm(b,b.termArray[bPos].coef,b.termArray[bPos].exp);
        }
    }
}
void Polynomial::NewTerm(Polynomial a,const float theCoeff,const int theExp) 
//Add a new term to the end of termArray  添加一个新的项在多项式的数组尾
{
   if(a.terms == a.capacity)
   {
       a.capacity*=2;
       Term *temp=new Term[a.capacity];             //根据重新乘好的参数  重新设置一个 new array
       copy(a.termArray,a.termArray+a.terms,temp);
       delete [] a.termArray;                       //删除掉以前的数组。
       a.termArray=temp;
   }
   a.terms=a.terms+1;
   a.termArray[terms].coef=theCoeff;
   a.termArray[terms].exp=theExp;
}


















