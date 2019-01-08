#include "eigen-git-mirror/Eigen/Geometry"
#include "eigen-git-mirror/Eigen/Eigen"
#include "eigen-git-mirror/Eigen/IterativeLinearSolvers"
#include <iostream>
#include <typeinfo>

//define a macro. Macros are pieces of code in a program which given some name
#define Area(l,b) l*b
using namespace std; 
using namespace Eigen;


#define MAX_ITERATIONS 10


int sparse_solver(){
    /*Carry out the Sparse Solver   
    */

    //There is a floating point exception due to division by zero
    int n = 10 ;
    VectorXd x(n), b(n);
    SparseMatrix<double, ColMajor> A;
    SparseLU<SparseMatrix<double, ColMajor>, COLAMDOrdering<int> > solver;
    // fill A and b;
    // Compute the ordering permutation vector from the structural pattern of A
    solver.analyzePattern(A); 
    // Compute the numerical factorization 
    solver.factorize(A); 
    //Use the factors to solve the linear system 
    x = solver.solve(b); 


    cout << "The value of x is: " << x; 

    return 0; 
}



int main() {

    //Check if A is positive 
    SparseMatrix<double> A; 
    bool A_positive = isPositive(); 
    bool A_postive = isPositive(A); 

    MatrixXd A = MatrixXd::Random(6,6);
    EigenSolver<MatrixXd> es; 
    complex<double> lambda = es.eigenvalues()[0]
    cout << lambda;



    DiagonalPreconditioner<double> t; 
    int n = 10000;
    VectorXd x(n), b(n);
    SparseMatrix<double> A(n,n);
    // fill A and b
    ConjugateGradient<SparseMatrix<double>, Lower|Upper> cg;
    cg.compute(A);
    x = cg.solve(b);
    std::cout << "#iterations:     " << cg.iterations() << std::endl;
    std::cout << "estimated error: " << cg.error()      << std::endl;
    // update b, and solve again
    x = cg.solve(b);


    cout << "Passing Conjugate Gradient solve \n"; 


    BiCGSTAB<SparseMatrix<double> > solver_2;
    solver_2.maxIterations();
    solver_2.compute(A); 
    x = solver_2.solve(b);
    std::cout << "#iterations:     " << solver_2.iterations() << std::endl;
    std::cout << "estimated error: " << solver_2.error()      << std::endl;
    x = solver_2.solve(b); // solve again 

    cout << "Passing BiCGSTAB solve"; 

    SparseQR<SparseMatrix<double, ColMajor>, COLAMDOrdering<int>> sparse_qr_solver; 
    sparse_qr_solver.analyzePattern(A);
    sparse_qr_solver.factorize(A);      

    MatrixXd r = sparse_qr_solver.matrixQ(); 
    cout << r;  






    /*Write 

    //solver.compute(A), solver,factorize(A), solver.solver(A)
    //The following steps are taken when using the solver*/ 
    //First there is a compute step that computes the decomposition of the matrix */ 
    //First analyze sparsity using analyze pattern to reduce fill-in 
    //Then do factorization
    //This is equivalent to cg.compute(A)
    //


    /*
     The main steps that are common to all these linear solvers are introduced as well.
     Depending on the properties of the matrix, the desired accuracy, the end-user is able 
     to tune those steps in order to improve the performance of its code. Note that it is not
      required to know deeply what's hiding behind these steps: the last section presents a
       benchmark routine that can be easily used to get an insight on the performance of all the available solvers.
    */


    int s = sparse_solver(); 

    return 0; 

}

