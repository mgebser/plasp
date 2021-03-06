#include <plasp/sas/Goal.h>

#include <iostream>

namespace plasp
{
namespace sas
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Goal
//
////////////////////////////////////////////////////////////////////////////////////////////////////

Goal Goal::fromSAS(utils::Parser<> &parser, const Variables &variables)
{
	Goal goal;

	parser.expect<std::string>("begin_goal");

	const auto numberOfGoalFacts = parser.parse<size_t>();
	goal.m_facts.reserve(numberOfGoalFacts);

	for (size_t i = 0; i < numberOfGoalFacts; i++)
		goal.m_facts.emplace_back(Fact::fromSAS(parser, variables));

	parser.expect<std::string>("end_goal");

	return goal;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const Goal::Facts &Goal::facts() const
{
	return m_facts;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
