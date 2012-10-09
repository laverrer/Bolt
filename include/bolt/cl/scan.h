/***************************************************************************                                                                                     
*   Copyright 2012 Advanced Micro Devices, Inc.                                     
*                                                                                    
*   Licensed under the Apache License, Version 2.0 (the "License");   
*   you may not use this file except in compliance with the License.                 
*   You may obtain a copy of the License at                                          
*                                                                                    
*       http://www.apache.org/licenses/LICENSE-2.0                      
*                                                                                    
*   Unless required by applicable law or agreed to in writing, software              
*   distributed under the License is distributed on an "AS IS" BASIS,              
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.         
*   See the License for the specific language governing permissions and              
*   limitations under the License.                                                   

***************************************************************************/                                                                                     

#if !defined( SCAN_H )
#define SCAN_H
#pragma once

#include <bolt/cl/bolt.h>
#include <bolt/cl/functional.h>
#include <bolt/cl/device_vector.h>

namespace bolt
{
    namespace cl
    {

        /*! \addtogroup algorithms
         */

        /*! \addtogroup PrefixSums Prefix Sums
        *   \ingroup algorithms
        *   The sorting Algorithm for sorting the given InputIterator.
        */ 

        /*! \addtogroup scan
        *   \ingroup PrefixSums
        *   \{
        *   \todo The user_code parameter is not used yet
        *   \todo The performance of the Sort routines should be proven using a benchmark program that can 
        *   show decent results across a range of values (a graph)
        */

        /*! \brief inclusive_scan calculates a running sum over a range of values, inclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::inclusive_scan( a, a+10, a );
        * // a => {1, 3, 6, 10, 15, 21, 28, 36, 45, 55}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator >
        OutputIterator 
            inclusive_scan( InputIterator first, InputIterator last, OutputIterator result, 
            const std::string& user_code="" );

        /*! \brief inclusive_scan calculates a running sum over a range of values, inclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param binary_op A functor object specifying the operation between two elements in the input range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::inclusive_scan( a, a+10, a );
        * // a => {1, 3, 6, 10, 15, 21, 28, 36, 45, 55}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator, typename BinaryFunction > 
        OutputIterator 
            inclusive_scan( InputIterator first, InputIterator last, OutputIterator result, BinaryFunction binary_op,
                const std::string& user_code="" );

        /*! \brief inclusive_scan calculates a running sum over a range of values, inclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param ctl A Bolt control object, to describe the environment the function should run under
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::inclusive_scan( a, a+10, a );
        * // a => {1, 3, 6, 10, 15, 21, 28, 36, 45, 55}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator >
        OutputIterator 
            inclusive_scan( const control &ctl, InputIterator first, InputIterator last, 
            OutputIterator result, const std::string& user_code="" );

        /*! \brief inclusive_scan calculates a running sum over a range of values, inclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param ctl A Bolt control object, to describe the environment the function should run under
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param binary_op A functor object specifying the operation between two elements in the input range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::inclusive_scan( a, a+10, a );
        * // a => {1, 3, 6, 10, 15, 21, 28, 36, 45, 55}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator, typename BinaryFunction >
        OutputIterator
            inclusive_scan( const control &ctl, InputIterator first, InputIterator last, 
            OutputIterator result, BinaryFunction binary_op, const std::string& user_code="" );

        /*! \brief exclusive_scan calculates a running sum over a range of values, exclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::exclusive_scan( a, a+10, a );
        * // a => {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator >
        OutputIterator 
            exclusive_scan( InputIterator first, InputIterator last, OutputIterator result,
            const std::string& user_code="" );

        /*! \brief exclusive_scan calculates a running sum over a range of values, exclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param init  The value used to initialize the output scan sequence
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator implements an input iterator
        * \tparam OutputIterator implements an output iterator
        * \tparam T should be convertible to std::iterator_traits< OutputIterator >::value_type
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::exclusive_scan( a, a+10, a, 0 );
        * // a => {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator, typename T >
        OutputIterator 
            exclusive_scan( InputIterator first, InputIterator last, OutputIterator result, T init,
            const std::string& user_code="" );

        /*! \brief exclusive_scan calculates a running sum over a range of values, exclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param init  The value used to initialize the output scan sequence
        * \param binary_op A functor object specifying the operation between two elements in the input range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \tparam T should be convertible to std::iterator_traits< OutputIterator >::value_type
        * \tparam BinaryFunction implements a binary function and its result should be convertible to 
        *   std::iterator_traits< OutputIterator >::value_type
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::exclusive_scan( a, a+10, a, 0, bolt::cl::plus< int >( ) );
        * // a => {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator, typename T, typename BinaryFunction > 
        OutputIterator 
            exclusive_scan( InputIterator first, InputIterator last, OutputIterator result, T init, BinaryFunction binary_op,
            const std::string& user_code="" );

        /*! \brief exclusive_scan calculates a running sum over a range of values, exclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param ctl A Bolt control object, to describe the environment the function should run under
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::exclusive_scan( a, a+10, a );
        * // a => {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator >
        OutputIterator 
            exclusive_scan( const control& ctl, InputIterator first, InputIterator last, 
            OutputIterator result, const std::string& user_code="" );

        /*! \brief exclusive_scan calculates a running sum over a range of values, exclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param ctl A Bolt control object, to describe the environment the function should run under
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param init  The value used to initialize the output scan sequence
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator implements an input iterator
        * \tparam OutputIterator implements an output iterator
        * \tparam T should be convertible to std::iterator_traits< OutputIterator >::value_type
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::exclusive_scan( a, a+10, a, 0 );
        * // a => {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator, typename T >
        OutputIterator 
            exclusive_scan( const control& ctl, InputIterator first, InputIterator last, OutputIterator result, T init,
            const std::string& user_code="" );

        /*! \brief exclusive_scan calculates a running sum over a range of values, exclusive of the current value.
        *   The result value at iterator position \p i is the running sum of all values less than \p i in the input range
        *
        * \param ctl A Bolt control object, to describe the environment the function should run under
        * \param first The first iterator in the input range to be scanned
        * \param last  The last iterator in the input range to be scanned
        * \param result  The first iterator in the output range
        * \param binary_op A functor object specifying the operation between two elements in the input range
        * \param user_code A client specified string that will be appended to the generated OpenCL kernel
        * \tparam InputIterator An iterater signifying the range is used as input
        * \tparam OutputIterator An iterater signifying the range is used as output
        * \tparam T should be convertible to std::iterator_traits< OutputIterator >::value_type
        * \tparam BinaryFunction implements a binary function and its result should be convertible to 
        *   std::iterator_traits< OutputIterator >::value_type
        * \return An iterator pointing at the end of the result range
        *
        * \code
        * #include "bolt/cl/scan.h"
        *
        * int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        *
        * // Calculate the inclusive scan of an input range, modifying the values in-place
        * bolt::cl::exclusive_scan( a, a+10, a, 0, bolt::cl::plus< int >( ) );
        * // a => {0, 1, 3, 6, 10, 15, 21, 28, 36, 45}
        *  \endcode
        * \sa http://www.sgi.com/tech/stl/partial_sum.html
        */
        template< typename InputIterator, typename OutputIterator, typename T, typename BinaryFunction >
        OutputIterator
            exclusive_scan( const control &ctl, InputIterator first, InputIterator last, 
            OutputIterator result, T init, BinaryFunction binary_op, const std::string& user_code="" );

        /*!   \}  */

    }// end of bolt::cl namespace
}// end of bolt namespace

#include <bolt/cl/detail/scan.inl>

#endif