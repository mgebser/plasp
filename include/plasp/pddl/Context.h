#ifndef __PLASP__PDDL__CONTEXT_H
#define __PLASP__PDDL__CONTEXT_H

#include <memory>
#include <unordered_map>
#include <vector>

#include <plasp/utils/Logger.h>

namespace plasp
{
namespace pddl
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Context
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Context
{
	public:
		Context(utils::Parser &parser)
		:	parser(parser)
		{
		}

		utils::Parser &parser;
		utils::Logger logger;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
