#ifndef CPF_TEST_COMMON_H
#define CPF_TEST_COMMON_H

/*
	note: cant used c_printf to test c_printf that is why
	printf is used.
*/
#define TEST_PERIMETER_EMPLACE_BEGIN \
auto pstr_start =\
R"pstr_s(

================================================================
TEST START
================================================================

)pstr_s";\
\
printf(pstr_start);

#define TEST_PERIMETER_EMPLACE_END \
	auto pstr_end =\
	R"pstr_e(

================================================================
TEST END					
================================================================

)pstr_e"; \
\
printf(pstr_end);

#endif