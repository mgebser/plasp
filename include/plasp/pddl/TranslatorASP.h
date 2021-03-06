#ifndef __PLASP__PDDL__TRANSLATOR_ASP_H
#define __PLASP__PDDL__TRANSLATOR_ASP_H

#include <plasp/pddl/Description.h>

#include <iosfwd>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TranslatorASP
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class TranslatorASP
{
	public:
		explicit TranslatorASP(Description &description, utils::LogStream &outputStream);

		void translate() const;

	private:
		void translateDomain() const;
		void translateTypes() const;
		void translatePredicates() const;
		void translateActions() const;

		void translateProblem() const;
		void translateInitialState() const;
		void translateGoal() const;

		void translateConstants(const std::string &heading, const expressions::Constants &constants) const;
		void translateVariablesHead(const expressions::Variables &variables) const;
		void translateVariablesBody(const expressions::Variables &variables) const;
		void translateLiteral(const Expression &literal) const;
		void translatePredicate(const expressions::Predicate &predicate) const;

		Description &m_description;
		utils::LogStream &m_outputStream;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
