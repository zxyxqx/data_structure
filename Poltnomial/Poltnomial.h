//Polymial ADT
class Polynomial    //forward declaration
{
//p(x)=a0X^e0+a1X^e1+...+anx^ex  是二元组<ei,ai>的有序集合 x是变量
//其中，ai是非零的浮点系数值，ei是非负的整数型指数值。    
public:
    Polynomial();
    //构造一个空的多项式p(x)=0;
    Polynomial Add(Polynomial a,Polynomial b);
    //返回来个多项式的和 *this+poly
    Polynomial Mult(Polynomial a,Polynomial b);
    //返回两个多项式*this和poly的乘积
    void NewTerm(Polynomial a,const float theCoeff,const int theExp);
    //Add a new term to the end of termArray  添加一个新的项在多项式的后面
    float Eval(float f);
    //计算多项式 *this 的变量取f的值，并且返回结果。    
private:
    Term *termArray; //  array of nonzero terms;     多项式非零项数组；
    int capacity;    //  size of termArray;          多项式数组的大小  
    int terms;       //  number of nonzero terms;    项数的多少；
};
class Term      
{
    friend class Polynomial; //当一个类作为另一个类的友元时，这就意味着这个类的所有成员函数都是另一个类的友元函数，都可以访问另一个类中的隐藏信息（包括私有成员和保护成员）。
    private:    
    float coef;  //变量 
    int exp;     //指数
}