#include <plasp/pddl/expressions/Unsupported.h>

#include <plasp/pddl/IO.h>

namespace plasp
{
namespace pddl
{
namespace expressions
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Unsupported
//
////////////////////////////////////////////////////////////////////////////////////////////////////

UnsupportedPointer Unsupported::parse(Context &context)
{
	auto &parser = context.parser;

	auto expression = std::make_unique<Unsupported>(Unsupported());

	parser.expect<std::string>("(");

	expression->m_type = parser.parseIdentifier();

	context.logger.logWarning(parser.coordinate(), "expression type “" + expression->m_type + "” currently unsupported in this context");

	skipSection(parser);

	return expression;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const std::string &Unsupported::type() const
{
	return m_type;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
