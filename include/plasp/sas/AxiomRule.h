#ifndef __PLASP__SAS__AXIOM_RULE_H
#define __PLASP__SAS__AXIOM_RULE_H

#include <vector>

#include <plasp/sas/AssignedVariable.h>
#include <plasp/sas/Variable.h>
#include <plasp/utils/Parser.h>

namespace plasp
{
namespace sas
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// AxiomRule
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class AxiomRule;
using AxiomRules = std::vector<AxiomRule>;

////////////////////////////////////////////////////////////////////////////////////////////////////

class AxiomRule
{
	public:
		using Condition = AssignedVariable;
		using Conditions = AssignedVariables;

		static AxiomRule fromSAS(utils::Parser<> &parser, const Variables &variables);

	public:
		const Conditions &conditions() const;
		const Condition &postcondition() const;

	private:
		AxiomRule() = default;
		explicit AxiomRule(Conditions conditions, Condition postcondition);

		Conditions m_conditions;
		Condition m_postcondition;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
