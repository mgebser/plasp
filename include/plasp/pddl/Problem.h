#ifndef __PLASP__PDDL__PROBLEM_H
#define __PLASP__PDDL__PROBLEM_H

#include <plasp/pddl/Context.h>
#include <plasp/pddl/Expression.h>
#include <plasp/pddl/InitialState.h>
#include <plasp/pddl/Parser.h>
#include <plasp/pddl/Requirement.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Problem
{
	public:
		Problem(Context &context, Domain &domain);

		void findSections();
		void parse();

		Domain &domain();
		const Domain &domain() const;

		const std::string &name() const;

		const Requirements &requirements() const;
		bool hasRequirement(Requirement::Type requirementType) const;
		void checkRequirement(Requirement::Type requirementType);

		expressions::Constants &objects();
		const expressions::Constants &objects() const;

		InitialState &initialState();
		const InitialState &initialState() const;

		const Expression &goal() const;

		void checkConsistency();

	private:
		void parseRequirementSection();
		void computeDerivedRequirements();

		void parseDomainSection();

		void parseObjectSection();

		void parseInitialStateSection();

		void parseGoalSection();

		Context &m_context;
		Domain &m_domain;

		std::string m_name;

		utils::Stream::Position m_domainPosition;

		utils::Stream::Position m_requirementsPosition;
		Requirements m_requirements;

		utils::Stream::Position m_objectsPosition;
		expressions::Constants m_objects;

		utils::Stream::Position m_initialStatePosition;
		std::unique_ptr<InitialState> m_initialState;

		utils::Stream::Position m_goalPosition;
		ExpressionPointer m_goal;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
