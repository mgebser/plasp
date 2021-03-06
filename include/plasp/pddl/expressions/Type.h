#ifndef __PLASP__PDDL__EXPRESSIONS__TYPE_H
#define __PLASP__PDDL__EXPRESSIONS__TYPE_H

#include <plasp/pddl/Expression.h>

namespace plasp
{
namespace pddl
{
namespace expressions
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Type
//
////////////////////////////////////////////////////////////////////////////////////////////////////

const Expression *parseExistingPrimitiveType(Context &context,
	ExpressionContext &expressionContext);

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}

#endif
