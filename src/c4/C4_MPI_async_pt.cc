//----------------------------------*-C++-*----------------------------------//
/*!
 * \file   c4/C4_MPI_async_pt.cc
 * \author Thomas M. Evans
 * \date   Mon Mar 25 14:44:54 2002
 * \brief  C4 MPI non-blocking send/recv instantiations.
 * \note   Copyright (C) 2016-2017 Los Alamos National Security, LLC.
 *         All rights reserved.
 */
//---------------------------------------------------------------------------//
// $Id$
//---------------------------------------------------------------------------//

#include "c4/config.h"

#ifdef C4_MPI

#include "C4_MPI.t.hh"

namespace rtt_c4 {

//---------------------------------------------------------------------------//
// EXPLICIT INSTANTIATIONS OF NON-BLOCKING SEND/RECEIVE
//---------------------------------------------------------------------------//

//! Send char data asynchronously.
template C4_Req DLL_PUBLIC_c4 send_async<char>(const char *, int, int, int);
//! Send uchar data asynchronously.
template C4_Req DLL_PUBLIC_c4 send_async<unsigned char>(const unsigned char *,
                                                        int, int, int);
//! Send short data asynchronously.
template C4_Req DLL_PUBLIC_c4 send_async<short>(const short *, int, int, int);
//! Send ushort data asynchronously.
template C4_Req DLL_PUBLIC_c4 send_async<unsigned short>(const unsigned short *,
                                                         int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<int>(const int *, int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<unsigned int>(const unsigned int *,
                                                       int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<long>(const long *, int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<unsigned long>(const unsigned long *,
                                                        int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<float>(const float *, int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<double>(const double *, int, int, int);
template C4_Req DLL_PUBLIC_c4 send_async<long double>(const long double *, int,
                                                      int, int);
template C4_Req DLL_PUBLIC_c4 send_async<long long>(const long long *, int, int,
                                                    int);
template C4_Req DLL_PUBLIC_c4
send_async<unsigned long long>(const unsigned long long *, int, int, int);

template C4_Req DLL_PUBLIC_c4 receive_async<char>(char *, int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<unsigned char>(unsigned char *, int,
                                                           int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<short>(short *, int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<unsigned short>(unsigned short *,
                                                            int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<int>(int *, int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<unsigned int>(unsigned int *, int,
                                                          int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<long>(long *, int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<unsigned long>(unsigned long *, int,
                                                           int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<float>(float *, int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<double>(double *, int, int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<long double>(long double *, int,
                                                         int, int);
template C4_Req DLL_PUBLIC_c4 receive_async<long long>(long long *, int, int,
                                                       int);
template C4_Req DLL_PUBLIC_c4
receive_async<unsigned long long>(unsigned long long *, int, int, int);

template void DLL_PUBLIC_c4 send_async<char>(C4_Req &, const char *, int, int,
                                             int);
template void DLL_PUBLIC_c4 send_async<unsigned char>(C4_Req &,
                                                      const unsigned char *,
                                                      int, int, int);
template void DLL_PUBLIC_c4 send_async<short>(C4_Req &, const short *, int, int,
                                              int);
template void DLL_PUBLIC_c4 send_async<unsigned short>(C4_Req &,
                                                       const unsigned short *,
                                                       int, int, int);
template void DLL_PUBLIC_c4 send_async<int>(C4_Req &, const int *, int, int,
                                            int);
template void DLL_PUBLIC_c4 send_async<unsigned int>(C4_Req &,
                                                     const unsigned int *, int,
                                                     int, int);
template void DLL_PUBLIC_c4 send_async<long>(C4_Req &, const long *, int, int,
                                             int);
template void DLL_PUBLIC_c4 send_async<unsigned long>(C4_Req &,
                                                      const unsigned long *,
                                                      int, int, int);
template void DLL_PUBLIC_c4 send_async<float>(C4_Req &, const float *, int, int,
                                              int);
template void DLL_PUBLIC_c4 send_async<double>(C4_Req &, const double *, int,
                                               int, int);
template void DLL_PUBLIC_c4 send_async<long double>(C4_Req &,
                                                    const long double *, int,
                                                    int, int);
template void DLL_PUBLIC_c4 send_async<long long>(C4_Req &, const long long *,
                                                  int, int, int);
template void DLL_PUBLIC_c4 send_async<unsigned long long>(
    C4_Req &, const unsigned long long *, int, int, int);

template void DLL_PUBLIC_c4 send_is<char>(C4_Req &, const char *, int, int,
                                          int);
template void DLL_PUBLIC_c4 send_is<unsigned char>(C4_Req &,
                                                   const unsigned char *, int,
                                                   int, int);
template void DLL_PUBLIC_c4 send_is<short>(C4_Req &, const short *, int, int,
                                           int);
template void DLL_PUBLIC_c4 send_is<unsigned short>(C4_Req &,
                                                    const unsigned short *, int,
                                                    int, int);
template void DLL_PUBLIC_c4 send_is<int>(C4_Req &, const int *, int, int, int);
template void DLL_PUBLIC_c4 send_is<unsigned int>(C4_Req &,
                                                  const unsigned int *, int,
                                                  int, int);
template void DLL_PUBLIC_c4 send_is<long>(C4_Req &, const long *, int, int,
                                          int);
template void DLL_PUBLIC_c4 send_is<unsigned long>(C4_Req &,
                                                   const unsigned long *, int,
                                                   int, int);
template void DLL_PUBLIC_c4 send_is<float>(C4_Req &, const float *, int, int,
                                           int);
template void DLL_PUBLIC_c4 send_is<double>(C4_Req &, const double *, int, int,
                                            int);
template void DLL_PUBLIC_c4 send_is<long double>(C4_Req &, const long double *,
                                                 int, int, int);
template void DLL_PUBLIC_c4 send_is<long long>(C4_Req &, const long long *, int,
                                               int, int);
template void DLL_PUBLIC_c4 send_is<unsigned long long>(
    C4_Req &, const unsigned long long *, int, int, int);

template void DLL_PUBLIC_c4 receive_async<char>(C4_Req &, char *, int, int,
                                                int);
template void DLL_PUBLIC_c4 receive_async<unsigned char>(C4_Req &,
                                                         unsigned char *, int,
                                                         int, int);
template void DLL_PUBLIC_c4 receive_async<short>(C4_Req &, short *, int, int,
                                                 int);
template void DLL_PUBLIC_c4 receive_async<unsigned short>(C4_Req &,
                                                          unsigned short *, int,
                                                          int, int);
template void DLL_PUBLIC_c4 receive_async<int>(C4_Req &, int *, int, int, int);
template void DLL_PUBLIC_c4 receive_async<unsigned int>(C4_Req &,
                                                        unsigned int *, int,
                                                        int, int);
template void DLL_PUBLIC_c4 receive_async<long>(C4_Req &, long *, int, int,
                                                int);
template void DLL_PUBLIC_c4 receive_async<unsigned long>(C4_Req &,
                                                         unsigned long *, int,
                                                         int, int);
template void DLL_PUBLIC_c4 receive_async<float>(C4_Req &, float *, int, int,
                                                 int);
template void DLL_PUBLIC_c4 receive_async<double>(C4_Req &, double *, int, int,
                                                  int);
template void DLL_PUBLIC_c4 receive_async<long double>(C4_Req &, long double *,
                                                       int, int, int);
template void DLL_PUBLIC_c4 receive_async<long long>(C4_Req &, long long *, int,
                                                     int, int);
template void DLL_PUBLIC_c4 receive_async<unsigned long long>(
    C4_Req &, unsigned long long *, int, int, int);

} // end namespace rtt_c4

#endif // C4_MPI

//---------------------------------------------------------------------------//
// end of C4_MPI_async_pt.cc
//---------------------------------------------------------------------------//
