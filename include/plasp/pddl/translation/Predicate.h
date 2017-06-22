#ifndef __PLASP__PDDL__TRANSLATION__PREDICATE_H
#define __PLASP__PDDL__TRANSLATION__PREDICATE_H

#include <colorlog/Formatting.h>

#include <pddlparse/AST.h>
#include <pddlparse/Parse.h>

#include <plasp/pddl/translation/Primitives.h>
#include <plasp/pddl/translation/Variables.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Predicate
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void translatePredicate(colorlog::ColorStream &outputStream, const ::pddl::ast::Predicate &predicate);
void translatePredicateDeclaration(colorlog::ColorStream &outputStream, const ::pddl::ast::PredicateDeclaration &predicateDeclaration);

////////////////////////////////////////////////////////////////////////////////////////////////////

inline void translatePredicate(colorlog::ColorStream &outputStream, const ::pddl::ast::Predicate &predicate)
{
	const auto &arguments = predicate.arguments;

	if (arguments.empty())
	{
		outputStream << *predicate.declaration;
		return;
	}

	outputStream << "(" << *predicate.declaration;

	for (const auto &argument : arguments)
	{
		outputStream << ", ";

		const auto handleConstant =
			[&](const ::pddl::ast::ConstantPointer &constant)
			{
				outputStream << colorlog::Keyword("constant") << "(" << *constant << ")";
			};

		const auto handleVariable =
			[&](const ::pddl::ast::VariablePointer &variable)
			{
				outputStream << *variable;
			};

		const auto handleUnsupported =
			[&](const auto &)
			{
				throw TranslatorException("only variables and constants supported in predicates currently");
			};

		argument.match(handleConstant, handleVariable, handleUnsupported);
	}

	outputStream << ")";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

inline void translatePredicateDeclaration(colorlog::ColorStream &outputStream, const ::pddl::ast::PredicateDeclaration &predicateDeclaration)
{
	outputStream << colorlog::Keyword("variable") << "(";

	if (predicateDeclaration.parameters.empty())
	{
		outputStream << predicateDeclaration << ")";
		return;
	}

	outputStream << "(" << predicateDeclaration;
	translateVariablesForRuleHead(outputStream, predicateDeclaration.parameters);
	outputStream << "))";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void translatePredicateToVariable(colorlog::ColorStream &outputStream, const ::pddl::ast::Predicate &predicate, bool isPositive = true)
{
	outputStream << colorlog::Keyword("variable") << "(";
	translatePredicate(outputStream, predicate);
	outputStream << "), " << colorlog::Keyword("value") << "(";
	translatePredicate(outputStream, predicate);
	outputStream << ", ";

	if (isPositive)
		outputStream << colorlog::Boolean("true");
	else
		outputStream << colorlog::Boolean("false");

	outputStream << ")";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
