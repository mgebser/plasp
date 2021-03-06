#include <gtest/gtest.h>

#include <plasp/utils/Parser.h>
#include <plasp/utils/ParserException.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UtilsTests, ParserParse)
{
	std::stringstream s("  identifier  5   \n-51\t 0 1 100 200 -300 -400");
	plasp::utils::Parser<> p("input", s);

	ASSERT_EQ(p.parse<std::string>(), "identifier");
	ASSERT_EQ(p.parse<size_t>(), 5u);
	ASSERT_EQ(p.parse<int>(), -51);
	ASSERT_EQ(p.parse<bool>(), false);
	ASSERT_EQ(p.parse<bool>(), true);

	ASSERT_EQ(p.parse<int>(), 100);
	ASSERT_EQ(p.parse<size_t>(), 200u);
	ASSERT_EQ(p.parse<int>(), -300);
	ASSERT_THROW(p.parse<size_t>(), plasp::utils::ParserException);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UtilsTests, ParserExpect)
{
	std::stringstream s("  identifier  5   \n-51\t 0 1 100 200 -300 -400");
	plasp::utils::Parser<> p("input", s);

	ASSERT_NO_THROW(p.expect<std::string>("identifier"));
	ASSERT_NO_THROW(p.expect<size_t>(5u));
	ASSERT_NO_THROW(p.expect<int>(-51));
	ASSERT_NO_THROW(p.expect<bool>(false));
	ASSERT_NO_THROW(p.expect<bool>(true));

	ASSERT_NO_THROW(p.expect<int>(100));
	ASSERT_NO_THROW(p.expect<size_t>(200u));
	ASSERT_NO_THROW(p.expect<int>(-300));
	ASSERT_THROW(p.expect<size_t>(-400), plasp::utils::ParserException);

	p.seek(0);
	ASSERT_THROW(p.expect<std::string>("error"), plasp::utils::ParserException);

	p.seek(14);
	ASSERT_THROW(p.expect<size_t>(6u), plasp::utils::ParserException);

	p.seek(17);
	ASSERT_THROW(p.expect<int>(-50), plasp::utils::ParserException);

	p.seek(24);
	ASSERT_THROW(p.expect<bool>(true), plasp::utils::ParserException);

	p.seek(26);
	ASSERT_THROW(p.expect<bool>(false), plasp::utils::ParserException);

	p.seek(28);
	ASSERT_THROW(p.expect<int>(101), plasp::utils::ParserException);

	p.seek(31);
	ASSERT_THROW(p.expect<size_t>(201), plasp::utils::ParserException);

	p.seek(34);
	ASSERT_THROW(p.expect<int>(-299), plasp::utils::ParserException);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UtilsTests, ParserTest)
{
	std::stringstream s("  identifier  5   \n-51\t 0 1");
	plasp::utils::Parser<> p("input", s);

	plasp::utils::Parser<>::Position pos;

	pos = p.position();
	ASSERT_EQ(p.testAndReturn<std::string>("error"), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndReturn<std::string>("identifier"), true);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<std::string>("error"), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<std::string>("identifier"), true);
	ASSERT_EQ(p.position(), 12);

	pos = p.position();
	ASSERT_EQ(p.testAndReturn<size_t>(6u), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndReturn<size_t>(5u), true);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<size_t>(6u), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<size_t>(5u), true);
	ASSERT_EQ(p.position(), 15);

	pos = p.position();
	ASSERT_EQ(p.testAndReturn<int>(-50), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndReturn<int>(-51), true);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<int>(-50), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<int>(-51), true);
	ASSERT_EQ(p.position(), 22);

	pos = p.position();
	ASSERT_EQ(p.testAndReturn<bool>(true), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndReturn<bool>(false), true);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<bool>(true), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<bool>(false), true);
	ASSERT_EQ(p.position(), 25);

	pos = p.position();
	ASSERT_EQ(p.testAndReturn<bool>(false), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndReturn<bool>(true), true);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<bool>(false), false);
	ASSERT_EQ(p.position(), pos);
	ASSERT_EQ(p.testAndSkip<bool>(true), true);
	ASSERT_EQ(p.position(), 27);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UtilsTests, ParseEndOfFile)
{
	std::stringstream s1("test");
	plasp::utils::Parser<> p1("input", s1);

	ASSERT_NO_THROW(p1.expect<std::string>("test"));
	ASSERT_THROW(p1.parse<std::string>(), plasp::utils::ParserException);

	std::stringstream s2("test1 test2 test3");
	plasp::utils::Parser<> p2("input", s2);

	ASSERT_NO_THROW(p2.expect<std::string>("test1"));
	ASSERT_NO_THROW(p2.expect<std::string>("test2"));
	ASSERT_NO_THROW(p2.expect<std::string>("test3"));
	ASSERT_THROW(p2.parse<std::string>(), plasp::utils::ParserException);

	std::stringstream s3("-127");
	plasp::utils::Parser<> p3("input", s3);

	p3.expect<int>(-127);
	ASSERT_THROW(p3.parse<int>(), plasp::utils::ParserException);

	std::stringstream s4("128 -1023 -4095");
	plasp::utils::Parser<> p4("input", s4);

	ASSERT_NO_THROW(p4.expect<size_t>(128));
	ASSERT_NO_THROW(p4.expect<int>(-1023));
	ASSERT_NO_THROW(p4.expect<int>(-4095));
	ASSERT_THROW(p4.parse<int>(), plasp::utils::ParserException);

	std::stringstream s5("0");
	plasp::utils::Parser<> p5("input", s5);

	p5.expect<bool>(false);
	ASSERT_THROW(p5.parse<bool>(), plasp::utils::ParserException);

	std::stringstream s6("0 1 0");
	plasp::utils::Parser<> p6("input", s6);

	ASSERT_NO_THROW(p6.expect<bool>(false));
	ASSERT_NO_THROW(p6.expect<bool>(true));
	ASSERT_NO_THROW(p6.expect<bool>(false));
	ASSERT_THROW(p6.parse<bool>(), plasp::utils::ParserException);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UtilsTests, ParserPosition)
{
	std::stringstream s("123 \n4\ntest1\n test2\ntest3 \ntest4\n\n\n\n");
	plasp::utils::Parser<> p("input", s);

	const auto startPosition = p.position();

	plasp::utils::StreamCoordinate c;

	c = p.coordinate();
	ASSERT_EQ(c.row, 1u);
	ASSERT_EQ(c.column, 1u);
	ASSERT_EQ(p.currentCharacter(), '1');

	ASSERT_NO_THROW(p.advance());

	c = p.coordinate();
	ASSERT_EQ(c.row, 1u);
	ASSERT_EQ(c.column, 2u);
	ASSERT_EQ(p.currentCharacter(), '2');

	ASSERT_NO_THROW(p.advance());

	c = p.coordinate();
	ASSERT_EQ(c.row, 1u);
	ASSERT_EQ(c.column, 3u);
	ASSERT_EQ(p.currentCharacter(), '3');

	ASSERT_NO_THROW(p.advance());

	c = p.coordinate();
	ASSERT_EQ(c.row, 1u);
	ASSERT_EQ(c.column, 4u);
	ASSERT_EQ(p.currentCharacter(), ' ');

	ASSERT_NO_THROW(p.advance());

	c = p.coordinate();
	ASSERT_EQ(c.row, 1u);
	ASSERT_EQ(c.column, 5u);
	ASSERT_EQ(p.currentCharacter(), '\n');

	ASSERT_NO_THROW(p.advance());

	c = p.coordinate();
	ASSERT_EQ(c.row, 2u);
	ASSERT_EQ(c.column, 1u);
	ASSERT_EQ(p.currentCharacter(), '4');

	ASSERT_NO_THROW(p.advance());

	ASSERT_NO_THROW(p.expect<std::string>("test1"));

	c = p.coordinate();
	ASSERT_EQ(c.row, 3u);
	ASSERT_EQ(c.column, 6u);

	ASSERT_NO_THROW(p.expect<std::string>("test2"));

	c = p.coordinate();
	ASSERT_EQ(c.row, 4u);
	ASSERT_EQ(c.column, 7u);

	ASSERT_NO_THROW(p.expect<std::string>("test3"));

	c = p.coordinate();
	ASSERT_EQ(c.row, 5u);
	ASSERT_EQ(c.column, 6u);

	ASSERT_NO_THROW(p.skipLine());

	c = p.coordinate();
	ASSERT_EQ(c.row, 6u);
	ASSERT_EQ(c.column, 1u);

	ASSERT_NO_THROW(p.skipLine());

	c = p.coordinate();
	ASSERT_EQ(c.row, 7u);
	ASSERT_EQ(c.column, 1u);

	ASSERT_NO_THROW(p.skipWhiteSpace());

	c = p.coordinate();
	ASSERT_EQ(c.row, 10u);
	ASSERT_EQ(c.column, 1u);
	ASSERT_TRUE(p.atEnd());

	p.reset();
	ASSERT_EQ(p.position(), startPosition);
	ASSERT_FALSE(p.atEnd());

	for (size_t i = 0; i < 5; i++)
		p.advance();

	ASSERT_EQ(p.position(), static_cast<std::istream::pos_type>(5));

	p.seek(static_cast<std::istream::pos_type>(7));

	ASSERT_EQ(p.position(), static_cast<std::istream::pos_type>(7));

	ASSERT_NO_THROW(p.expect<std::string>("test1"));

	// TODO: test parser with multiple sections
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(UtilsTests, ParserRemoveComments)
{
	std::stringstream s1("; comment at beginning\ntest1; comment in between\ntest2; comment at end");
	plasp::utils::Parser<> p1("input", s1);

	p1.removeComments(";", "\n", false);

	plasp::utils::StreamCoordinate c;

	ASSERT_NO_THROW(p1.expect<std::string>("test1"));

	c = p1.coordinate();
	ASSERT_EQ(c.row, 2u);
	ASSERT_EQ(c.column, 6u);

	ASSERT_NO_THROW(p1.expect<std::string>("test2"));

	c = p1.coordinate();
	ASSERT_EQ(c.row, 3u);
	ASSERT_EQ(c.column, 6u);

	p1.skipWhiteSpace();

	ASSERT_TRUE(p1.atEnd());

	std::stringstream s2("test;");
	plasp::utils::Parser<> p2("input", s2);

	p2.removeComments(";", "\n", false);

	ASSERT_NO_THROW(p2.expect<std::string>("test"));

	p2.skipWhiteSpace();

	ASSERT_TRUE(p2.atEnd());

	std::stringstream s3("/* comment at start */ test1 /* comment in between */ test2 /*");
	plasp::utils::Parser<> p3("input", s3);

	p3.removeComments("/*", "*/", true);

	ASSERT_NO_THROW(p3.expect<std::string>("test1"));
	ASSERT_NO_THROW(p3.expect<std::string>("test2"));

	p3.skipWhiteSpace();

	ASSERT_TRUE(p3.atEnd());
}
