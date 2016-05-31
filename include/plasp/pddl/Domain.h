#ifndef __PLASP__PDDL__DOMAIN_H
#define __PLASP__PDDL__DOMAIN_H

#include <unordered_map>

#include <plasp/pddl/Context.h>
#include <plasp/pddl/Predicate.h>
#include <plasp/pddl/Requirement.h>
#include <plasp/pddl/Type.h>
#include <plasp/utils/Parser.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Domain
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Domain
{
	public:
		static Domain fromPDDL(utils::Parser &parser, Context &context);

	public:
		const std::string &name() const;
		const Requirements &requirements() const;
		const TypeHashMap &types() const;
		const PredicateHashMap &predicates() const;

	private:
		Domain(Context &context);

		void parseSection(utils::Parser &parser);

		void parseRequirementsSection(utils::Parser &parser);
		bool hasRequirement(Requirement::Type requirementType) const;
		void computeDerivedRequirements();

		void parseTypingSection(utils::Parser &parser);

		void parsePredicateSection(utils::Parser &parser);

		void checkConsistency();

		Context &m_context;

		std::string m_name;
		Requirements m_requirements;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
