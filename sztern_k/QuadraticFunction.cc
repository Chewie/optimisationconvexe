/*
 * QuadraticFunction.cc
 *
 *  Created on: 7 mars 2014
 *      Author: mruiz
 */

#include "QuadraticFunction.h"

QuadraticFunction::QuadraticFunction()
    : _bilinearTerms(), _cst(0)
{
}

void QuadraticFunction::clear() {
    IFunction::clear();
    _cst = 0;
    _bilinearTerms.clear();
}

void QuadraticFunction::add(std::string i, double v) {
}
void QuadraticFunction::set(std::string i, double v) {
}
double QuadraticFunction::get(std::string i) const {
	return 0;
}

void QuadraticFunction::add(std::string i, std::string j, double v) {
    _bilinearTerms[std::make_pair(getId(i), getId(j))] += v;
}
void QuadraticFunction::set(std::string i, std::string j, double v) {
    _bilinearTerms[std::make_pair(getId(i), getId(j))] = v;
}
double QuadraticFunction::get(std::string i, std::string j) const {
    auto it = _bilinearTerms.find(std::make_pair(getIdConst(i), getIdConst(j)));
    return it->second;
}

void QuadraticFunction::print(std::ostream& stream = std::cout) const {
    if (std::abs(_cst) > 1e-10)
        stream << _cst;

    for (auto const & term : _bilinearTerms) {
        if (PrintCoeff(stream, term.second)) {
            stream << getName(term.first.first);
            stream << getName(term.first.second);
        }
    }
}

IntMat2Double const & QuadraticFunction::getBilTerms() const {
	return _bilinearTerms;
}

double QuadraticFunction::getValue(const Point& x) const
{
    double result(_cst);
    for (const auto& term: _bilinearTerms)
        result += term.second * x[term.first.first]
            * x[term.first.second];
    return result;
}

void QuadraticFunction::getGradient(const Point& x, Point& result) const
{
    // FIXME
}

const Int2Double& QuadraticFunction::getLinearTerms() const
{
    // FIXME
    return _linearTerms;
}

void QuadraticFunction::add(double v) {
	_cst += v;
}
void QuadraticFunction::set(double v) {
	_cst = v;
}
double QuadraticFunction::get() const {
	return _cst;
}
