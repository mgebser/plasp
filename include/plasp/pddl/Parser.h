#ifndef __PLASP__PDDL__PARSER_H
#define __PLASP__PDDL__PARSER_H

#include <plasp/utils/Parser.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Parser
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class PDDLParserPolicy
{
	public:
		static char transformCharacter(char c) noexcept
		{
			return std::tolower(c);
		}

		static bool isWhiteSpaceCharacter(char c)
		{
			return std::iswspace(c);
		}

		static bool isBlankCharacter(char c)
		{
			return std::isblank(c);
		}

		static bool isIdentifierCharacter(char c)
		{
			return c != '?'
				&& c != '('
				&& c != ')'
				&& c != ';'
				&& std::isgraph(c);
		}
};

////////////////////////////////////////////////////////////////////////////////////////////////////

using Parser = utils::Parser<PDDLParserPolicy>;

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
