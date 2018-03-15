#include "SparseMatrix.h"
#include <algorithm>
#include <iostream>
using namespace std;
SparseMatrix SparseMatrix::Transpose() 
{//Return the transpose of *this
    SparseMatrix b(cols,rows,terms);//capacity of b.smArray is terms
    if(terms>0)
    {
        //nonzero matrix
        int currentB=0;
        for(int c=0;c<cols;c++)
        {
            for(int i=0;i<terms;i++)
            {
                if(smArray[i].col==c)                             //列匹配之后进行横纵坐标转化
                {
                    b.smArray[currentB].row=c;                    //横纵坐标转化
                    b.smArray[currentB].col=smArray[i].row;       
                    b.smArray[currentB++].value=smArray[i].value; //value不变 最主要的是B++
                }
            }
        }
    }
    return b;
}

SparseMatrix SparseMatrix::FastTranspose()
{
    SparseMatrix b(cols,rows,terms);
    if(terms>0)
    {
        int *rowSize=new int[cols];
        int *rowStart=new int[cols];
        fill(rowSize,rowSize+cols,0);
        for(int i=0;i<terms;i++)
        {
            rowSize[smArray[i].col]++;
        }
        rowStart[0]=0;
        for(int i=0;i<cols;i++)
        {
            rowStart[i]=rowStart[i-1]+rowSize[i-1];     //快速变化核心  快速转置里不是if判断比较的 而是一种类似枚举的方式进行进行判断 直接排列；
        }
        for(int i=0;i<terms;i++)
        {
            //copy from *this to b
            int j=rowStart[smArray[i].col];            //rowStart是确定新矩阵之中各行的起始位置
            b.smArray[j].row=smArray[i].col;           //交换行列
            b.smArray[j].col=smArray[i].row;
            b.smArray[j].value=smArray[i].value;           
            rowStart[smArray[i].col]++;                //位置++
        }
        delete [] rowSize;
        delete [] rowStart;
    }
    return b;
}

void SparseMatrix::ChangeSizeID(const int newSize)      //改变一个一维数组的大小
{
    if(newSize<terms) throw"New size must be >=number of terms";
    MatrixTerm *temp=new MatrixTerm[newSize];//new array
    copy(smArray,smArray+terms,temp);

}

void SparseMatrix::StoreSum(const int sum,const int r,const int c)
{

} 

