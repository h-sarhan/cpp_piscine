/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarhan <hsarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:32:27 by hsarhan           #+#    #+#             */
/*   Updated: 2022/11/08 17:01:02 by hsarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	addOneAndPrint(const int &num)
{
	std::cout << num << " + 1 is " << num + 1 << std::endl;
}

void	printFirstChar(const std::string &str)
{
	std::cout << "First char is " << str.substr(0, 1) << std::endl;
}

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}