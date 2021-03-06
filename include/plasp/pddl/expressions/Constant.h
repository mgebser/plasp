#ifndef __PLASP__PDDL__EXPRESSIONS__CONSTANT_H
#define __PLASP__PDDL__EXPRESSIONS__CONSTANT_H

#include <plasp/pddl/Expression.h>
#include <plasp/utils/Parser.h>
#include <plasp/utils/ParserException.h>

namespace plasp
{
namespace pddl
{
namespace expressions
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constant
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Constant: public ExpressionCRTP<Constant>
{
	public:
		static const Expression::Type ExpressionType = Expression::Type::Constant;

		static void parseTypedDeclaration(Context &context, Domain &domain);
		static void parseTypedDeclarations(Context &context, Domain &domain);
		static void parseTypedDeclaration(Context &context, Problem &problem);
		static void parseTypedDeclarations(Context &context, Problem &problem);

		static Constant *parseAndFind(Context &context, const Domain &domain);
		static Constant *parseAndFind(Context &context, const Problem &problem);

	public:
		const std::string &name() const;
		const PrimitiveType *type() const;

	private:
		static ConstantPointer parseDeclaration(Context &context);
		static void parseTypedDeclaration(Context &context, Domain &domain, Constants &constants);

		static Constant *parseAndFind(const std::string &constantName, const Constants &constants);

		Constant();

		void setDirty(bool isDirty = true);
		bool isDirty() const;

		void setType(const PrimitiveType *parentType);

		bool m_isDirty;

		std::string m_name;

		const PrimitiveType *m_type;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

#endif
