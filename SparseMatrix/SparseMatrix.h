class SparseMatrix;
class MatrixTerm
{
    friend class SparseMatrix;
    private:
    int row;
    int col;
    int value;
};
class SparseMatrix
//稀疏矩阵是一个 三元组 <row,column,value> 
{
    public: 
      SparseMatrix(int r,int c,int t);
      //稀疏初始化
      SparseMatrix Transpose();
      //稀疏矩阵转置
      SparseMatrix Add(SparseMatrix b);
      //稀疏矩阵相加
      SparseMatrix Multiply(SparseMatrix b);
      //稀疏矩阵乘法
      SparseMatrix FastTranspose();
      //稀疏矩阵快速转置
      void StoreSum(int sum,int r,int c);
      void ChangeSizeID(int newSize);
      private:
      int rows;
      int cols;
      int terms;
      int capacity;
      MatrixTerm * smArray;

}