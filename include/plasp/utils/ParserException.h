#ifndef __PLASP__UTILS__PARSER_EXCEPTION_H
#define __PLASP__UTILS__PARSER_EXCEPTION_H

#include <exception>
#include <string>

#include <plasp/utils/Parser.h>

namespace plasp
{
namespace utils
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ParserException
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class ParserException: public std::exception
{
	public:
		explicit ParserException(const utils::Parser &parser)
		:	ParserException(parser, "Unspecified parser error")
		{
		}

		explicit ParserException(const utils::Parser &parser, const char *message)
		:	ParserException(parser, static_cast<std::string>(message))
		{
		}

		explicit ParserException(const utils::Parser &parser, const std::string &message)
		{
			const auto coordinate = parser.coordinate();

			m_message = coordinate.sectionName + ":" + std::to_string(coordinate.row) + ":" + std::to_string(coordinate.column) + " " + message;
		}

		~ParserException() throw()
		{
		}

		const char *what() const throw()
		{
			if (m_message.empty())
				return "Unspecified parser error";

			return m_message.c_str();
		}

	private:
		std::string m_message;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
