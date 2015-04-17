/*
	Copyright (C) 2014 Floyd Mulenga Chitalu jnr									

	Permission is hereby granted, free of charge, to obtain a copy					
	of this software, to deal in the Software without restriction, including		
	without limitation the rights to [use], [copy], [modify], [merge], [publish],	
	[distribute], [sublicense], and/or [sell] copies of the Software, and to		
	permit persons to whom the Software is furnished to do so, subject to			
	the following conditions:														
																				
	The above copyright notice and this permission notice shall be included in		
	all copies or substantial portions of the Software.								
																				
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR		
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,		
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE		
	AUTHOR OR COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM(S), DAMAGE(S) OR OTHER		
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,	
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN		
	THE SOFTWARE.	
*/

#ifndef __CPF_H__
#define __CPF_H__

#include <cprintf/internal/cpf_hlpr.h>

//template<typename T0>
//struct fstype_check_t : public std::enable_if <
//	std::is_same<T0, std::string>::value or
//	std::is_same<T0, std::wstring>::value or
//	std::is_pointer<T0>::value and
//	(
//	std::is_same<wchar_t*, T0>::value			or std::is_same<char*, T0>::value					or
//	std::is_same<unsigned char*, T0>::value		or std::is_same<signed char*, T0>::value			or
//	std::is_same<const wchar_t*, T0>::value		or std::is_same<const char*, T0>::value				or
//	std::is_same<const signed char*, T0>::value	or std::is_same<const unsigned char*, T0>::value
//	),
//	T0 > {};

template<	std::size_t FLAGS = CPF_STDO, 
			typename T0, 
			typename... Ts>
typename cpf::type::ret_t<	std::is_same<T0, std::string>::value or
							std::is_same<T0, std::wstring>::value or
							std::is_pointer<T0>::value and
							(
								std::is_same<wchar_t*, T0>::value			or std::is_same<char*, T0>::value					or
								std::is_same<unsigned char*, T0>::value		or std::is_same<signed char*, T0>::value			or
								std::is_same<const wchar_t*, T0>::value		or std::is_same<const char*, T0>::value				or
								std::is_same<const signed char*, T0>::value	or std::is_same<const unsigned char*, T0>::value
							),//end of test condition
							T0>
cprintf(T0 f, Ts... args)
{
	static_assert(	(((FLAGS bitand CPF_STDO) == CPF_STDO) and	((FLAGS bitand CPF_STDE) != CPF_STDE)) or
					(((FLAGS bitand CPF_STDO) != CPF_STDO) and	((FLAGS bitand CPF_STDE) == CPF_STDE)),
					"CPF-CT-ERR: invalid stream specification");

	static_assert(	(FLAGS xor CPF_FLAG_MASK_) <= CPF_FLAG_MASK_,
					"CPF-CT-ERR: invalid API flags detected");

	//so close!!!
	//TODO: resolve this
	cpf::type::ret_t<true, T0> ret;	ret.f = f;
	//typename std::result_of<decltype(cprintf<FLAGS, T0, Ts...>(f, args...))>::type ret2;
	//static_assert(std::is_same<decltype(ret2), decltype(ret)>::value, "");


	CPF_MARK_CRITICAL_SECTION_;
	{
		ret.c = cpf::intern::dispatch(	((FLAGS bitand CPF_STDO) == CPF_STDO) ? stdout : stderr,
										std::forward<T0>(f),
										std::forward<Ts>(args)...);
	}
	CPF_UNMARK_CRITICAL_SECTION_;

	return ret;
}

//template<std::size_t FLAGS = CPF_STDO, typename T>
//inline void cprintf_arg0_impl(std::enable_if<std::is_floating_point<T>::value, T>::type &&arg0)
//{
//	cprintf<FLAGS, T>("%f", static_cast<double>(arg0));
//}
//
//template<std::size_t FLAGS = CPF_STDO, typename T>
//inline void cprintf_arg0_impl(std::enable_if<std::is_integral<T>::value, T>::type &&arg0)
//{
//	cprintf<FLAGS, T>("%" PRId64, static_cast<std::int64_t>(arg0));
//}

//template<std::size_t FLAGS = CPF_STDO, typename T>
//inline void cprintf_(std::enable_if<std::is_arithmetic<T>::value, T>::type arg0)
//{
//	//cprintf_arg0_impl<FLAGS, T>(std::forward<T>(arg0));
//}

template<	std::size_t FLAGS = CPF_STDO, 
			typename T0, 
			typename... Ts>
inline void cprintf_t(	T0 f,
						cpf::type::arg_pack<Ts...> args_tup)
{
	auto predef_args_tup = std::make_tuple(f);
	auto call_args = std::tuple_cat(predef_args_tup, args_tup);

	cpf::intern::apply_tuple(cprintf<FLAGS, T0, Ts...>, call_args);
}

template<	std::size_t FLAGS = CPF_STDO,
			typename T0, 
			unsigned N,
			typename... Ts>
inline void cprintf_s(T0 (&f)[N], Ts... args)
{
	static_assert(N >= 2, "CPF-CT-ERR: expected string-literal of size >= 1");
	cprintf<FLAGS>(	f, std::forward<Ts>(args)...);
}

template<	std::size_t FLAGS = CPF_STDO,
			typename T0,
			unsigned N,
			typename... Ts>
inline void cprintf_ts(T0(&f)[N], cpf::type::arg_pack<Ts...> args_tup)
{
	static_assert(N >= 2, "CPF-CT-ERR: expected string-literal of size >= 1");
	cprintf_t<FLAGS>(f,	std::forward<cpf::type::arg_pack<Ts...>>(args_tup));
}

#include <cprintf/internal/cpf_dbgh.h>

#endif /* __CPF_H__ */
