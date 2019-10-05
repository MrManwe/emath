#pragma once
#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_INCLUDED
#include <array>
#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/empty.hpp>



template<typename Element, typename List>
struct combine_element
{
	using type =
		typename boost::mpl::push_front
		<
		typename combine_element
		<
		Element,
		typename boost::mpl::pop_front
		<
		List
		>::type
		>::type,
		std::pair<Element, typename boost::mpl::front<List>::type>
		>::type;
};

template<typename Element>
struct combine_element<Element, boost::mpl::list<>::type>
{
	using type = boost::mpl::list<>::type;
};


template<typename List1, typename List2>
struct combine_lists
{
	using type =
		typename boost::mpl::joint_view
		<
		typename combine_element
		<
		typename boost::mpl::front<List1>::type,
		List2
		>::type,
		typename combine_lists
		<
		typename boost::mpl::pop_front
		<
		List1
		>::type,
		List2
		>::type
		>::type
		;
};

template<typename List2>
struct combine_lists<boost::mpl::list<>::type, List2>
{
	using type =
		boost::mpl::list<>::type
		;
};