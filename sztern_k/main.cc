#include <iostream>
#include <armadillo>
#include "TP1.h"
#include "QuadraticFunction.h"

int main(int argc, char const *argv[])
{
    QuadraticFunction qf;

    TP1::GetExample1(qf);

    std::cout << qf << std::endl;

    arma::mat a(qf.getN(), qf.getN());
    for (const auto& terms : qf.getBilTerms())
    {
        a(terms.first.first, terms.first.second) = terms.second;
    }

    std::cout << a << std::endl;

    arma::vec eig_val;
    arma::mat eig_vec;
    arma::eig_sym(eig_val, eig_vec, a);

    std::cout << eig_val << std::endl;
    return (0);
}
