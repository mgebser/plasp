#ifndef __PLASP__PDDL__EXPRESSIONS__PREDICATE_H
#define __PLASP__PDDL__EXPRESSIONS__PREDICATE_H

#include <plasp/pddl/Expression.h>

namespace plasp
{
namespace pddl
{
namespace expressions
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Predicate
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Predicate: public ExpressionCRTP<Predicate>
{
	public:
		static const Expression::Type ExpressionType = Expression::Type::Predicate;

		static PredicatePointer parse(Context &context, ExpressionContext &expressionContext);
		static PredicatePointer parse(Context &context, const Problem &problem);

	public:
		const std::string &name() const;
		const std::vector<const Expression *> &arguments() const;

		bool isDeclared() const;

	private:
		Predicate();

		void setDeclared();

		bool m_isDeclared;

		std::string m_name;
		std::vector<const Expression *> m_arguments;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

#endif
