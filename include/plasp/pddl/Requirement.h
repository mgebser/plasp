#ifndef __PLASP__PDDL__REQUIREMENT_H
#define __PLASP__PDDL__REQUIREMENT_H

#include <vector>

#include <plasp/pddl/Context.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Requirement
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Requirement;
using Requirements = std::vector<Requirement>;

////////////////////////////////////////////////////////////////////////////////////////////////////

class Requirement
{
	public:
		enum class Type
		{
			STRIPS,
			Typing,
			NegativePreconditions,
			DisjunctivePreconditions,
			Equality,
			ExistentialPreconditions,
			UniversalPreconditions,
			QuantifiedPreconditions,
			ConditionalEffects,
			Fluents,
			NumericFluents,
			ObjectFluents,
			ADL,
			DurativeActions,
			DurationInequalities,
			ContinuousEffects,
			DerivedPredicates,
			TimedInitialLiterals,
			Preferences,
			Constraints,
			ActionCosts,
			GoalUtilities
		};

		static Requirement parse(Context &context);

	public:
		Requirement(Type type);

		Type type() const;

		std::string toPDDL() const;
		std::string toASP() const;

	private:
		Type m_type;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
