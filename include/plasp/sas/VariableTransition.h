#ifndef __PLASP__SAS__VARIABLE_TRANSITION_H
#define __PLASP__SAS__VARIABLE_TRANSITION_H

#include <iosfwd>

#include <plasp/sas/Value.h>
#include <plasp/sas/Variable.h>
#include <plasp/utils/Parser.h>

namespace plasp
{
namespace sas
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// VariableTransition
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class VariableTransition;
using VariableTransitions = std::vector<VariableTransition>;

////////////////////////////////////////////////////////////////////////////////////////////////////

class VariableTransition
{
	public:
		static VariableTransition fromSAS(utils::Parser<> &parser, const Variables &variables);

	public:
		const Variable &variable() const;
		const Value &valueBefore() const;
		const Value &valueAfter() const;

	private:
		VariableTransition();

		const Variable *m_variable;
		const Value *m_valueBefore;
		const Value *m_valueAfter;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
