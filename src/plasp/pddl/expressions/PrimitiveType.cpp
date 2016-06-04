#include <plasp/pddl/expressions/PrimitiveType.h>

#include <algorithm>

#include <plasp/pddl/Context.h>
#include <plasp/pddl/ExpressionVisitor.h>

namespace plasp
{
namespace pddl
{
namespace expressions
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// PrimitiveType
//
////////////////////////////////////////////////////////////////////////////////////////////////////

PrimitiveType::PrimitiveType()
:	m_isDirty{false},
	m_isDeclared{false}
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////

PrimitiveType *PrimitiveType::parseDeclaration(utils::Parser &parser, Context &context)
{
	parser.skipWhiteSpace();

	const auto typeName = parser.parseIdentifier(isIdentifier);

	// TODO: use hash map
	const auto match = std::find_if(context.primitiveTypes.cbegin(), context.primitiveTypes.cend(),
		[&](const auto &primitiveType)
		{
			return primitiveType->name() == typeName;
		});

	// Return existing primitive type
	if (match != context.primitiveTypes.cend())
	{
		auto *type = match->get();

		type->setDirty();

		return type;
	}

	// Create new primitive type if not already existing
	auto type = std::make_unique<PrimitiveType>(PrimitiveType());

	type->m_name = typeName;

	BOOST_ASSERT(!type->m_name.empty());

	// Flag type for potentially upcoming parent type declaration
	type->setDirty();

	// TODO: Store constant in hash map
	context.primitiveTypes.emplace_back(std::move(type));

	return context.primitiveTypes.back().get();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveType::parseTypedDeclaration(utils::Parser &parser, Context &context)
{
	// Parse and store type
	auto *type = parseDeclaration(parser, context);

	// Flag type as correctly declared in the types section
	type->setDeclared();

	parser.skipWhiteSpace();

	// Check for type inheritance
	if (!parser.advanceIf('-'))
		return;

	// If existing, parse and store parent type
	auto *parentType = parseExisting(parser, context.primitiveTypes);

	parentType->setDirty(false);

	// Flag parent tpe as correctly declared in the types section
	parentType->setDeclared();

	// Assign parent type to all types that were previously flagged
	std::for_each(context.primitiveTypes.begin(), context.primitiveTypes.end(),
		[&](auto &childType)
		{
			if (!childType->isDirty())
				return;

			childType->m_parentTypes.push_back(parentType);
			childType->setDirty(false);
		});
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveType::accept(plasp::pddl::ExpressionVisitor &expressionVisitor) const
{
	expressionVisitor.visit(*this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveType::setDirty(bool isDirty)
{
	m_isDirty = isDirty;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool PrimitiveType::isDirty() const
{
	return m_isDirty;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void PrimitiveType::setDeclared()
{
	m_isDeclared = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool PrimitiveType::isDeclared() const
{
	return m_isDeclared;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const std::string &PrimitiveType::name() const
{
	return m_name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const std::vector<const PrimitiveType *> &PrimitiveType::parentTypes() const
{
	return m_parentTypes;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
