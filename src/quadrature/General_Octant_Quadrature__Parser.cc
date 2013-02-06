//----------------------------------*-C++-*----------------------------------------------//
/*!
 * \file   quadrature/General_Octant_Quadrature.cc
 * \author Kelly Thompson
 * \brief  Parse routines for parsing a General_Octant_Quadrature specification.
 * \note   � Copyright 2006-2012 LANSLLC All rights reserved.

 */
//---------------------------------------------------------------------------------------//
// $Id: Quadrature.hh 6718 2012-08-30 20:03:01Z warsa $
//---------------------------------------------------------------------------------------//

#include "parser/utilities.hh"
#include "General_Octant_Quadrature.hh"

namespace rtt_quadrature
{
using namespace rtt_parser;

//---------------------------------------------------------------------------------------//
/*!
 * The specification body must specify the number of ordinates and the number
 * of levels.
 * If it's organized in levels, then there is an sn order 
 * with which it can be associated naturally.
 * A quadrature class specification is optional; the default is octant.
 * The mu, eta, xi, and weight of each ordinate is then specified before
 * the terminating "end" statement.
 *
 * /param tokens Token stream from which to parse the specification.
 */
/*static*/
SP<Quadrature> General_Octant_Quadrature::parse(Token_Stream &tokens)
{
    Token token = tokens.shift();
    tokens.check_syntax(token.text()=="sn order", "expected sn order");

    unsigned sn_order = parse_positive_integer(tokens);


    token = tokens.shift();
    tokens.check_syntax(token.text()=="number of ordinates",
                        "expected number of ordinates");

    unsigned N = parse_positive_integer(tokens);

    token = tokens.shift();
    tokens.check_syntax(token.text()=="number of levels",
                        "expected number of levels");

    unsigned number_of_levels = parse_unsigned_integer(tokens);

    token = tokens.lookahead();

    Quadrature_Class quadrature_class = OCTANT_QUADRATURE;
    if (token.text()=="quadrature class")
    {
        tokens.shift();
        token = tokens.shift();
        if (token.text()=="triangle")
        {
            quadrature_class = TRIANGLE_QUADRATURE;
        }
        else if (token.text()=="square")
        {
            quadrature_class = SQUARE_QUADRATURE;
        }
        else
        {
            tokens.check_semantics(token.text()=="octant",
                                   "unrecognized quadrature class");
        }
    }

    vector<double> mu(N), eta(N), xi(N), wt(N);

    for (unsigned i=0; i<N; ++i)
    {
        mu[i] = parse_real(tokens);
        eta[i] = parse_real(tokens);
        xi[i] = parse_real(tokens);
        wt[i] = parse_real(tokens);
    }

    tokens.check_syntax(tokens.shift().type()==END, "missing end?");

    return SP<Quadrature>(new General_Octant_Quadrature(sn_order,
                                                        mu, eta, xi, wt,
                                                        number_of_levels,
                                                        quadrature_class));
}

} // end namespace rtt_quadrature

//---------------------------------------------------------------------------------------//
//                       end of quadrature/Quadrature.cc
//---------------------------------------------------------------------------------------//
