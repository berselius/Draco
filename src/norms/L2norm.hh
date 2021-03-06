//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   norms/L2norm.hh
 * \author Kent Budge
 * \date   Tue Sep 18 08:22:08 2007
 * \brief  Define template function L2norm
 * \note   Copyright (C) 2016-2017 Los Alamos National Security, LLC.
 *         All rights reserved.
 */
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#ifndef norms_L2norm_hh
#define norms_L2norm_hh

namespace rtt_norms {
//! Compute the L2-norm of a vector.
template <class In> double L2norm(In const &x);

} // end namespace rtt_norms

#endif // norms_L2norm_hh

//---------------------------------------------------------------------------//
// end of norms/L2norm.hh
//---------------------------------------------------------------------------//
