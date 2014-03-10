/*
 * LinearFunction.cc
 *
 *  Created on: 7 mars 2014
 *      Author: mruiz
 */

#include "LinearFunction.h"

LinearFunction::LinearFunction() {
	clear();
}

LinearFunction::~LinearFunction() {

}

double LinearFunction::getValue(Point const & x) const {
	double result(_cst);
	for (auto const & term : _linearTerms)
		result += x[term.first] * term.second;
	return result;
}
void LinearFunction::getGradient(Point const & x, Point & result) const {
	result.assign(getN(), 0);
	for (auto const & term : _linearTerms)
		result[term.first] = term.second;
}

void LinearFunction::add(std::string name, double v) {
	_linearTerms[getId(name)] += v;
}
void LinearFunction::set(std::string name, double v) {
	_linearTerms[getId(name)] = v;
}
double LinearFunction::get(std::string name) const {
	Int2Double::const_iterator it(_linearTerms.find(getIdConst(name)));
	return it == _linearTerms.end() ? 0 : it->second;
}

void LinearFunction::clear() {
	IFunction::clear();
	_cst = 0;
	_linearTerms.clear();
}

void LinearFunction::print(std::ostream & stream) const {
	if (std::abs(_cst) > 1e-10)
	stream << _cst;

	for (auto const & term : _linearTerms) {
		if (PrintCoeff(stream, term.second)) {
			stream << getName(term.first);
		}
	}
}

void LinearFunction::add(double v) {
	_cst += v;
}
void LinearFunction::set(double v) {
	_cst = v;
}
double LinearFunction::get() const {
	return _cst;
}
Int2Double const & LinearFunction::getLinearTerms() const {
	return _linearTerms;
}
