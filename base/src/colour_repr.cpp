#include "colour_repr.h"

extern "C" const _cpf_types::string_vector _cpf_colour_tokens= {

	/*default*/
	"!",

	/*dim text colour no background*/
	"r", "g", "b", "y", "m", "c", "w",

	/*bright text colour no background*/
	"r!", "g!", "b!", "y!", "m!", "c!", "w!",

	/*dim text and background colour*/
	"rr", "rb", "rg", "ry", "rm", "rc", "rw", /*red*/
	"gg", "gb", "gr", "gy", "gm", "gc", "gw", /*green*/
	"bb", "br", "bg", "by", "bm", "bc", "bw", /*blue*/
	"yy", "yb", "yg", "yr", "ym", "yc", "yw", /*yellow*/
	"mm", "mr", "mg", "my", "mb", "mc", "mw", /*magenta*/
	"cc", "cr", "cg", "cy", "cm", "cb", "cw", /*cyan*/
	"ww", "wr", "wg", "wy", "wm", "wc", "wb", /*white*/

	/*bright text colour and dim background colour*/
	"r!r", "r!b", "r!g", "r!y", "r!m", "r!c", "r!w", /*red*/
	"g!g", "g!b", "g!r", "g!y", "g!m", "g!c", "g!w", /*green*/
	"b!b", "b!r", "b!g", "b!y", "b!m", "b!c", "b!w", /*blue*/
	"y!y", "y!b", "y!g", "y!r", "y!m", "y!c", "y!w", /*yellow*/
	"m!m", "m!r", "m!g", "m!y", "m!b", "m!c", "m!w", /*magenta*/
	"c!c", "c!r", "c!g", "c!y", "c!m", "c!b", "c!w", /*cyan*/
	"w!w", "w!r", "w!g", "w!y", "w!m", "w!c", "w!b", /*white*/

	/*dim text colour and bright background colour*/
	"rr!", "rb!", "rg!", "ry!", "rm!", "rc!", "rw!", /*red*/
	"gg!", "gb!", "gr!", "gy!", "gm!", "gc!", "gw!", /*green*/
	"bb!", "br!", "bg!", "by!", "bm!", "bc!", "bw!", /*blue*/
	"yy!", "yb!", "yg!", "yr!", "ym!", "yc!", "yw!", /*yellow*/
	"mm!", "mr!", "mg!", "my!", "mb!", "mc!", "mw!", /*magenta*/
	"cc!", "cr!", "cg!", "cy!", "cm!", "cb!", "cw!", /*cyan*/
	"ww!", "wr!", "wg!", "wy!", "wm!", "wc!", "wb!", /*white*/

	/*bright text and background colour*/
	"r!r!", "r!b!", "r!g!", "r!y!", "r!m!", "r!c!", "r!w!", /*red*/
	"g!g!", "g!b!", "g!r!", "g!y!", "g!m!", "g!c!", "g!w!", /*green*/
	"b!b!", "b!r!", "b!g!", "b!y!", "b!m!", "b!c!", "b!w!", /*blue*/
	"y!y!", "y!b!", "y!g!", "y!r!", "y!m!", "y!c!", "y!w!", /*yellow*/
	"m!m!", "m!r!", "m!g!", "m!y!", "m!b!", "m!c!", "m!w!", /*magenta*/
	"c!c!", "c!r!", "c!g!", "c!y!", "c!m!", "c!b!", "c!w!", /*cyan*/
	"w!w!", "w!r!", "w!g!", "w!y!", "w!m!", "w!c!", "w!b!", /*white*/

#ifndef _WIN32
	"bld", "dim", "uln", "blk",	"rvs",	"hid",	
	"!bld",	"!dim",	"!uln",	"!blk",	"!rvs",	"!hid",
#endif /*#ifndef _WIN32*/
};

#ifdef _WIN32

const std::map<const _cpf_types::_string_type_, _cpf_types::colour> _cpf_colour_token_vals{
	/*default*/
	{ "!",	[&]()->_cpf_types::colour
			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				assert(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi));
				auto a = csbi.wAttributes;
				return static_cast<_cpf_types::colour>(a);
			}()
	},

	/*red*/
	{ "r", (_cpf_Rf) },
	{ "r!", (_cpf_Rf | _cpf_fgi) },

	{ "rr", (_cpf_Rf | _cpf_Rb) },
	{ "rb", (_cpf_Rf | _cpf_Bb) },
	{ "rg", (_cpf_Rf | _cpf_Gb) },
	{ "ry", (_cpf_Rf | _cpf_Rb | _cpf_Gb) },
	{ "rm", (_cpf_Rf | _cpf_Rb | _cpf_Bb) },
	{ "rc", (_cpf_Rf | _cpf_Gb | _cpf_Bb) },
	{ "rw", (_cpf_Rf | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "r!r", ((_cpf_Rf | _cpf_fgi) | _cpf_Rb) },
	{ "r!b", ((_cpf_Rf | _cpf_fgi) | _cpf_Bb) },
	{ "r!g", ((_cpf_Rf | _cpf_fgi) | _cpf_Gb) },
	{ "r!y", ((_cpf_Rf | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "r!m", ((_cpf_Rf | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "r!c", ((_cpf_Rf | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "r!w", ((_cpf_Rf | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "rr!", ((_cpf_Rf) | (_cpf_Rb | _cpf_bgi)) },
	{ "rb!", ((_cpf_Rf) | (_cpf_Bb | _cpf_bgi)) },
	{ "rg!", (_cpf_Rf | (_cpf_Gb | _cpf_bgi)) },
	{ "ry!", (_cpf_Rf | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "rm!", (_cpf_Rf | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "rc!", (_cpf_Rf | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "rw!", (_cpf_Rf | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "r!r!", ((_cpf_Rf | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "r!b!", ((_cpf_Rf | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "r!g!", ((_cpf_Rf | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "r!y!", ((_cpf_Rf | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "r!m!", ((_cpf_Rf | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "r!c!", ((_cpf_Rf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "r!w!", ((_cpf_Rf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	/*green*/

	{ "g", (_cpf_Gf) },
	{ "g!", (_cpf_Gf | _cpf_fgi) },

	{ "gr", (_cpf_Gf | _cpf_Rb) },
	{ "gb", (_cpf_Gf | _cpf_Bb) },
	{ "gg", (_cpf_Gf | _cpf_Gb) },
	{ "gy", (_cpf_Gf | _cpf_Rb | _cpf_Gb) },
	{ "gm", (_cpf_Gf | _cpf_Rb | _cpf_Bb) },
	{ "gc", (_cpf_Gf | _cpf_Gb | _cpf_Bb) },
	{ "gw", (_cpf_Gf | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "g!r", ((_cpf_Gf | _cpf_fgi) | _cpf_Rb) },
	{ "g!b", ((_cpf_Gf | _cpf_fgi) | _cpf_Bb) },
	{ "g!g", ((_cpf_Gf | _cpf_fgi) | _cpf_Gb) },
	{ "g!y", ((_cpf_Gf | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "g!m", ((_cpf_Gf | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "g!c", ((_cpf_Gf | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "g!w", ((_cpf_Gf | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "gr!", ((_cpf_Gf) | (_cpf_Rb | _cpf_bgi)) },
	{ "gb!", ((_cpf_Gf) | (_cpf_Bb | _cpf_bgi)) },
	{ "gg!", (_cpf_Gf | (_cpf_Gb | _cpf_bgi)) },
	{ "gy!", (_cpf_Gf | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "gm!", (_cpf_Gf | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "gc!", (_cpf_Gf | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "gw!", (_cpf_Gf | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "g!r!", ((_cpf_Gf | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "g!b!", ((_cpf_Gf | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "g!g!", ((_cpf_Gf | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "g!y!", ((_cpf_Gf | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "g!m!", ((_cpf_Gf | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "g!c!", ((_cpf_Gf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "g!w!", ((_cpf_Gf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	/*blue*/

	{ "b", (_cpf_Bf) },
	{ "b!", (_cpf_Bf | _cpf_fgi) },

	{ "br", (_cpf_Bf | _cpf_Rb) },
	{ "bb", (_cpf_Bf | _cpf_Bb) },
	{ "bg", (_cpf_Bf | _cpf_Gb) },
	{ "by", (_cpf_Bf | _cpf_Rb | _cpf_Gb) },
	{ "bm", (_cpf_Bf | _cpf_Rb | _cpf_Bb) },
	{ "bc", (_cpf_Bf | _cpf_Gb | _cpf_Bb) },
	{ "bw", (_cpf_Bf | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "b!r", ((_cpf_Bf | _cpf_fgi) | _cpf_Rb) },
	{ "b!b", ((_cpf_Bf | _cpf_fgi) | _cpf_Bb) },
	{ "b!g", ((_cpf_Bf | _cpf_fgi) | _cpf_Gb) },
	{ "b!y", ((_cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "b!m", ((_cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "b!c", ((_cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "b!w", ((_cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "br!", ((_cpf_Bf) | (_cpf_Rb | _cpf_bgi)) },
	{ "bb!", ((_cpf_Bf) | (_cpf_Bb | _cpf_bgi)) },
	{ "bg!", (_cpf_Bf | (_cpf_Gb | _cpf_bgi)) },
	{ "by!", (_cpf_Bf | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "bm!", (_cpf_Bf | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "bc!", (_cpf_Bf | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "bw!", (_cpf_Bf | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "b!r!", ((_cpf_Bf | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "b!b!", ((_cpf_Bf | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "b!g!", ((_cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "b!y!", ((_cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "b!m!", ((_cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "b!c!", ((_cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "b!w!", ((_cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	/*yellow*/

	{ "y", (_cpf_Rf | _cpf_Gf) },
	{ "y!", ((_cpf_Rf | _cpf_Gf) | _cpf_fgi) },

	{ "yr", ((_cpf_Rf | _cpf_Gf) | _cpf_Rb) },
	{ "yb", ((_cpf_Rf | _cpf_Gf) | _cpf_Bb) },
	{ "yg", ((_cpf_Rf | _cpf_Gf) | _cpf_Gb) },
	{ "yy", ((_cpf_Rf | _cpf_Gf) | _cpf_Rb | _cpf_Gb) },
	{ "ym", ((_cpf_Rf | _cpf_Gf) | _cpf_Rb | _cpf_Bb) },
	{ "yc", ((_cpf_Rf | _cpf_Gf) | _cpf_Gb | _cpf_Bb) },
	{ "yw", ((_cpf_Rf | _cpf_Gf) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "y!r", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Rb) },
	{ "y!b", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Bb) },
	{ "y!g", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Gb) },
	{ "y!y", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "y!m", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "y!c", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "y!w", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "yr!", (((_cpf_Rf | _cpf_Gf)) | (_cpf_Rb | _cpf_bgi)) },
	{ "yb!", (((_cpf_Rf | _cpf_Gf)) | (_cpf_Bb | _cpf_bgi)) },
	{ "yg!", ((_cpf_Rf | _cpf_Gf) | (_cpf_Gb | _cpf_bgi)) },
	{ "yy!", ((_cpf_Rf | _cpf_Gf) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "ym!", ((_cpf_Rf | _cpf_Gf) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "yc!", ((_cpf_Rf | _cpf_Gf) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "yw!", ((_cpf_Rf | _cpf_Gf) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "y!r!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "y!b!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "y!g!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "y!y!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "y!m!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "y!c!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "y!w!", (((_cpf_Rf | _cpf_Gf) | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	/*magenta*/

	{ "m", (_cpf_Rf | _cpf_Bf) },
	{ "m!", (_cpf_Rf | _cpf_Bf | _cpf_fgi) },

	{ "mr", (_cpf_Rf | _cpf_Bf | _cpf_Rb) },
	{ "mb", (_cpf_Rf | _cpf_Bf | _cpf_Bb) },
	{ "mg", (_cpf_Rf | _cpf_Bf | _cpf_Gb) },
	{ "my", (_cpf_Rf | _cpf_Bf | _cpf_Rb | _cpf_Gb) },
	{ "mm", (_cpf_Rf | _cpf_Bf | _cpf_Rb | _cpf_Bb) },
	{ "mc", (_cpf_Rf | _cpf_Bf | _cpf_Gb | _cpf_Bb) },
	{ "mw", (_cpf_Rf | _cpf_Bf | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "m!r", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Rb) },
	{ "m!b", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Bb) },
	{ "m!g", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Gb) },
	{ "m!y", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "m!m", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "m!c", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "m!w", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "mr!", ((_cpf_Rf | _cpf_Bf) | (_cpf_Rb | _cpf_bgi)) },
	{ "mb!", ((_cpf_Rf | _cpf_Bf) | (_cpf_Bb | _cpf_bgi)) },
	{ "mg!", (_cpf_Rf | _cpf_Bf | (_cpf_Gb | _cpf_bgi)) },
	{ "my!", (_cpf_Rf | _cpf_Bf | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "mm!", (_cpf_Rf | _cpf_Bf | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "mc!", (_cpf_Rf | _cpf_Bf | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "mw!", (_cpf_Rf | _cpf_Bf | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "m!r!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "m!b!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "m!g!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "m!y!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "m!m!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "m!c!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "m!w!", ((_cpf_Rf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	/*cyan*/

	{ "c", (_cpf_Gf | _cpf_Bf) },
	{ "c!", (_cpf_Gf | _cpf_Bf | _cpf_fgi) },

	{ "cr", (_cpf_Gf | _cpf_Bf | _cpf_Rb) },
	{ "cb", (_cpf_Gf | _cpf_Bf | _cpf_Bb) },
	{ "cg", (_cpf_Gf | _cpf_Bf | _cpf_Gb) },
	{ "cy", (_cpf_Gf | _cpf_Bf | _cpf_Rb | _cpf_Gb) },
	{ "cm", (_cpf_Gf | _cpf_Bf | _cpf_Rb | _cpf_Bb) },
	{ "cc", (_cpf_Gf | _cpf_Bf | _cpf_Gb | _cpf_Bb) },
	{ "cw", (_cpf_Gf | _cpf_Bf | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "c!r", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Rb) },
	{ "c!b", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Bb) },
	{ "c!g", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Gb) },
	{ "c!y", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "c!m", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "c!c", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "c!w", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "cr!", ((_cpf_Gf | _cpf_Bf) | (_cpf_Rb | _cpf_bgi)) },
	{ "cb!", ((_cpf_Gf | _cpf_Bf) | (_cpf_Bb | _cpf_bgi)) },
	{ "cg!", (_cpf_Gf | _cpf_Bf | (_cpf_Gb | _cpf_bgi)) },
	{ "cy!", (_cpf_Gf | _cpf_Bf | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "cm!", (_cpf_Gf | _cpf_Bf | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "cc!", (_cpf_Gf | _cpf_Bf | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "cw!", (_cpf_Gf | _cpf_Bf | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "c!r!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "c!b!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "c!g!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "c!y!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "c!m!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "c!c!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "c!w!", ((_cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	/*white*/

	{ "w", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi)) },
	{ "w!", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) },

	{ "wr", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Rb) },
	{ "wb", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Bb) },
	{ "wg", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Gb) },
	{ "wy", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "wm", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "wc", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "ww", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "w!r", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Rb) },
	{ "w!b", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Bb) },
	{ "w!g", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Gb) },
	{ "w!y", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Rb | _cpf_Gb) },
	{ "w!m", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Rb | _cpf_Bb) },
	{ "w!c", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Gb | _cpf_Bb) },
	{ "w!w", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | _cpf_Gb | _cpf_Bb | _cpf_Rb) },

	{ "wr!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi)) | (_cpf_Rb | _cpf_bgi)) },
	{ "wb!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi)) | (_cpf_Bb | _cpf_bgi)) },
	{ "wg!", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "wy!", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "wm!", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "wc!", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "ww!", ((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) },

	{ "w!r!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_bgi | _cpf_Rb)) },
	{ "w!b!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_Bb | _cpf_bgi)) },
	{ "w!g!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_Gb | _cpf_bgi)) },
	{ "w!y!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_Rb | _cpf_Gb | _cpf_bgi)) },
	{ "w!m!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_Rb | _cpf_Bb | _cpf_bgi)) },
	{ "w!c!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_bgi)) },
	{ "w!w!", (((_cpf_Rf | _cpf_Gf | _cpf_Bf | _cpf_fgi) | _cpf_fgi) | (_cpf_Gb | _cpf_Bb | _cpf_Rb | _cpf_bgi)) }

};

#else /*#ifdef _WIN32*/
//http://www.linuxhomenetworking.com/forums/showthread.php/1095-Linux-console-Colors-And-Other-Trick-s
//http://stackoverflow.com/questions/3506504/c-code-changes-terminal-text-color-how-to-restore-defaults-linux
//http://linuxgazette.net/issue65/padala.html
//http://misc.flogisoft.com/bash/tip_colors_and_formatting
extern const std::map<const _cpf_types::_string_type_, _cpf_types::colour> _cpf_colour_token_vals{

	/*attributes specifiers*/
	{	"bld", 		"\x1B[1m"},
	{	"dim", 		"\x1B[2m"},
	{	"uln", 		"\x1B[4m"},
	{	"blk", 		"\x1B[5m"},
	{	"rvs", 		"\x1B[7m"},
	{	"hid", 		"\x1B[8m"},
	{	"!bld", 	"\x1B[21m"},
	{	"!dim", 	"\x1B[22m"},
	{	"!uln", 	"\x1B[24m"},
	{	"!blk", 	"\x1B[25m"},
	{	"!rvs", 	"\x1B[27m"},
	{	"!hid", 	"\x1B[28m"},

	/*colours*/
	/*<ESC>[{attr};{fg};{bg}m*/
	{	"0",	"\x1B[0;0;0m" },
	/*default (reset all colours and attribs)*/
	{ 	"!", 	"\x1B[0m"},

	{	"r",	"\x1B[0;0;31m" },
	{	"rr",	"\x1B[0;31;41m" },
	{	"rg",	"\x1B[0;31;42m" },
	{	"rb",	"\x1B[0;31;44m" },
	{	"ry",	"\x1B[0;31;43m" },
	{	"rm",	"\x1B[0;31;45m" },
	{	"rc",	"\x1B[0;31;46m" },
	{	"rw",	"\x1B[0;31;47m" },

	{	"r!",	"\x1B[0;0;91m" },
	{	"r!r",	"\x1B[0;91;41m" },
	{	"r!g",	"\x1B[0;91;42m" },
	{	"r!b",	"\x1B[0;91;44m" },
	{	"r!y",	"\x1B[0;91;43m" },
	{	"r!m",	"\x1B[0;91;45m" },
	{	"r!c",	"\x1B[0;91;46m" },
	{	"r!w",	"\x1B[0;91;47m" },

	{	"rr!",	"\x1B[0;31;101m" },
	{	"rg!",	"\x1B[0;31;102m" },
	{	"rb!",	"\x1B[0;31;104m" },
	{	"ry!",	"\x1B[0;31;103m" },
	{	"rm!",	"\x1B[0;31;105m" },
	{	"rc!",	"\x1B[0;31;106m" },
	{	"rw!",	"\x1B[0;31;107m" },

	{	"r!r!",	"\x1B[0;91;101m" },
	{	"r!g!",	"\x1B[0;91;102m" },
	{	"r!b!",	"\x1B[0;31;104m" },
	{	"r!y!",	"\x1B[0;91;103m" },
	{	"r!m!",	"\x1B[0;91;105m" },
	{	"r!c!",	"\x1B[0;91;106m" },
	{	"r!w!",	"\x1B[0;91;107m" },

    {	"g",	"\x1B[0;0;32m" },
    {	"b",	"\x1B[0;0;34m" },
	{	"y",	"\x1B[0;0;33m" },
	{	"m",	"\x1B[0;0;35m" },
	{	"c",	"\x1B[0;0;36m" },
	{	"w",	"\x1B[0;0;37m" },
    
    {	"g!",	"\x1B[0;0;92m" },
    {	"b!",	"\x1B[0;0;94m" },
    {	"y!",	"\x1B[0;0;93m" },
	{	"m!",	"\x1B[0;0;95m" },
	{	"c!",	"\x1B[0;0;96m" },
	{	"w!",	"\x1B[0;0;97m" },

	/*full foreground colour spectrum*/
	{"0f", "\x1B[38;5;0m"},
	{"1f", "\x1B[38;5;1m"},
	{"2f", "\x1B[38;5;2m"},
	{"3f", "\x1B[38;5;3m"},
	{"4f", "\x1B[38;5;4m"},
	{"5f", "\x1B[38;5;5m"},
	{"6f", "\x1B[38;5;6m"},
	{"7f", "\x1B[38;5;7m"},
	{"8f", "\x1B[38;5;8m"},
	{"9f", "\x1B[38;5;9m"},
	{"10f", "\x1B[38;5;10m"},
	{"11f", "\x1B[38;5;11m"},
	{"12f", "\x1B[38;5;12m"},
	{"13f", "\x1B[38;5;13m"},
	{"14f", "\x1B[38;5;14m"},
	{"15f", "\x1B[38;5;15m"},
	{"16f", "\x1B[38;5;16m"},
	{"17f", "\x1B[38;5;17m"},
	{"18f", "\x1B[38;5;18m"},
	{"19f", "\x1B[38;5;19m"},
	{"20f", "\x1B[38;5;20m"},
	{"21f", "\x1B[38;5;21m"},
	{"22f", "\x1B[38;5;22m"},
	{"23f", "\x1B[38;5;23m"},
	{"24f", "\x1B[38;5;24m"},
	{"25f", "\x1B[38;5;25m"},
	{"26f", "\x1B[38;5;26m"},
	{"27f", "\x1B[38;5;27m"},
	{"28f", "\x1B[38;5;28m"},
	{"29f", "\x1B[38;5;29m"},
	{"30f", "\x1B[38;5;30m"},
	{"31f", "\x1B[38;5;31m"},
	{"32f", "\x1B[38;5;32m"},
	{"33f", "\x1B[38;5;33m"},
	{"34f", "\x1B[38;5;34m"},
	{"35f", "\x1B[38;5;35m"},
	{"36f", "\x1B[38;5;36m"},
	{"37f", "\x1B[38;5;37m"},
	{"38f", "\x1B[38;5;38m"},
	{"39f", "\x1B[38;5;39m"},
	{"40f", "\x1B[38;5;40m"},
	{"41f", "\x1B[38;5;41m"},
	{"42f", "\x1B[38;5;42m"},
	{"43f", "\x1B[38;5;43m"},
	{"44f", "\x1B[38;5;44m"},
	{"45f", "\x1B[38;5;45m"},
	{"46f", "\x1B[38;5;46m"},
	{"47f", "\x1B[38;5;47m"},
	{"48f", "\x1B[38;5;48m"},
	{"49f", "\x1B[38;5;49m"},
	{"50f", "\x1B[38;5;50m"},
	{"51f", "\x1B[38;5;51m"},
	{"52f", "\x1B[38;5;52m"},
	{"53f", "\x1B[38;5;53m"},
	{"54f", "\x1B[38;5;54m"},
	{"55f", "\x1B[38;5;55m"},
	{"56f", "\x1B[38;5;56m"},
	{"57f", "\x1B[38;5;57m"},
	{"58f", "\x1B[38;5;58m"},
	{"59f", "\x1B[38;5;59m"},
	{"60f", "\x1B[38;5;60m"},
	{"61f", "\x1B[38;5;61m"},
	{"62f", "\x1B[38;5;62m"},
	{"63f", "\x1B[38;5;63m"},
	{"64f", "\x1B[38;5;64m"},
	{"65f", "\x1B[38;5;65m"},
	{"66f", "\x1B[38;5;66m"},
	{"67f", "\x1B[38;5;67m"},
	{"68f", "\x1B[38;5;68m"},
	{"69f", "\x1B[38;5;69m"},
	{"70f", "\x1B[38;5;70m"},
	{"71f", "\x1B[38;5;71m"},
	{"72f", "\x1B[38;5;72m"},
	{"73f", "\x1B[38;5;73m"},
	{"74f", "\x1B[38;5;74m"},
	{"75f", "\x1B[38;5;75m"},
	{"76f", "\x1B[38;5;76m"},
	{"77f", "\x1B[38;5;77m"},
	{"78f", "\x1B[38;5;78m"},
	{"79f", "\x1B[38;5;79m"},
	{"80f", "\x1B[38;5;80m"},
	{"81f", "\x1B[38;5;81m"},
	{"82f", "\x1B[38;5;82m"},
	{"83f", "\x1B[38;5;83m"},
	{"84f", "\x1B[38;5;84m"},
	{"85f", "\x1B[38;5;85m"},
	{"86f", "\x1B[38;5;86m"},
	{"87f", "\x1B[38;5;87m"},
	{"88f", "\x1B[38;5;88m"},
	{"89f", "\x1B[38;5;89m"},
	{"90f", "\x1B[38;5;90m"},
	{"91f", "\x1B[38;5;91m"},
	{"92f", "\x1B[38;5;92m"},
	{"93f", "\x1B[38;5;93m"},
	{"94f", "\x1B[38;5;94m"},
	{"95f", "\x1B[38;5;95m"},
	{"96f", "\x1B[38;5;96m"},
	{"97f", "\x1B[38;5;97m"},
	{"98f", "\x1B[38;5;98m"},
	{"99f", "\x1B[38;5;99m"},
	{"100f", "\x1B[38;5;100m"},
	{"101f", "\x1B[38;5;101m"},
	{"102f", "\x1B[38;5;102m"},
	{"103f", "\x1B[38;5;103m"},
	{"104f", "\x1B[38;5;104m"},
	{"105f", "\x1B[38;5;105m"},
	{"106f", "\x1B[38;5;106m"},
	{"107f", "\x1B[38;5;107m"},
	{"108f", "\x1B[38;5;108m"},
	{"109f", "\x1B[38;5;109m"},
	{"110f", "\x1B[38;5;110m"},
	{"111f", "\x1B[38;5;111m"},
	{"112f", "\x1B[38;5;112m"},
	{"113f", "\x1B[38;5;113m"},
	{"114f", "\x1B[38;5;114m"},
	{"115f", "\x1B[38;5;115m"},
	{"116f", "\x1B[38;5;116m"},
	{"117f", "\x1B[38;5;117m"},
	{"118f", "\x1B[38;5;118m"},
	{"119f", "\x1B[38;5;119m"},
	{"120f", "\x1B[38;5;120m"},
	{"121f", "\x1B[38;5;121m"},
	{"122f", "\x1B[38;5;122m"},
	{"123f", "\x1B[38;5;123m"},
	{"124f", "\x1B[38;5;124m"},
	{"125f", "\x1B[38;5;125m"},
	{"126f", "\x1B[38;5;126m"},
	{"127f", "\x1B[38;5;127m"},
	{"128f", "\x1B[38;5;128m"},
	{"129f", "\x1B[38;5;129m"},
	{"130f", "\x1B[38;5;130m"},
	{"131f", "\x1B[38;5;131m"},
	{"132f", "\x1B[38;5;132m"},
	{"133f", "\x1B[38;5;133m"},
	{"134f", "\x1B[38;5;134m"},
	{"135f", "\x1B[38;5;135m"},
	{"136f", "\x1B[38;5;136m"},
	{"137f", "\x1B[38;5;137m"},
	{"138f", "\x1B[38;5;138m"},
	{"139f", "\x1B[38;5;139m"},
	{"140f", "\x1B[38;5;140m"},
	{"141f", "\x1B[38;5;141m"},
	{"142f", "\x1B[38;5;142m"},
	{"143f", "\x1B[38;5;143m"},
	{"144f", "\x1B[38;5;144m"},
	{"145f", "\x1B[38;5;145m"},
	{"146f", "\x1B[38;5;146m"},
	{"147f", "\x1B[38;5;147m"},
	{"148f", "\x1B[38;5;148m"},
	{"149f", "\x1B[38;5;149m"},
	{"150f", "\x1B[38;5;150m"},
	{"151f", "\x1B[38;5;151m"},
	{"152f", "\x1B[38;5;152m"},
	{"153f", "\x1B[38;5;153m"},
	{"154f", "\x1B[38;5;154m"},
	{"155f", "\x1B[38;5;155m"},
	{"156f", "\x1B[38;5;156m"},
	{"157f", "\x1B[38;5;157m"},
	{"158f", "\x1B[38;5;158m"},
	{"159f", "\x1B[38;5;159m"},
	{"160f", "\x1B[38;5;160m"},
	{"161f", "\x1B[38;5;161m"},
	{"162f", "\x1B[38;5;162m"},
	{"163f", "\x1B[38;5;163m"},
	{"164f", "\x1B[38;5;164m"},
	{"165f", "\x1B[38;5;165m"},
	{"166f", "\x1B[38;5;166m"},
	{"167f", "\x1B[38;5;167m"},
	{"168f", "\x1B[38;5;168m"},
	{"169f", "\x1B[38;5;169m"},
	{"170f", "\x1B[38;5;170m"},
	{"171f", "\x1B[38;5;171m"},
	{"172f", "\x1B[38;5;172m"},
	{"173f", "\x1B[38;5;173m"},
	{"174f", "\x1B[38;5;174m"},
	{"175f", "\x1B[38;5;175m"},
	{"176f", "\x1B[38;5;176m"},
	{"177f", "\x1B[38;5;177m"},
	{"178f", "\x1B[38;5;178m"},
	{"179f", "\x1B[38;5;179m"},
	{"180f", "\x1B[38;5;180m"},
	{"181f", "\x1B[38;5;181m"},
	{"182f", "\x1B[38;5;182m"},
	{"183f", "\x1B[38;5;183m"},
	{"184f", "\x1B[38;5;184m"},
	{"185f", "\x1B[38;5;185m"},
	{"186f", "\x1B[38;5;186m"},
	{"187f", "\x1B[38;5;187m"},
	{"188f", "\x1B[38;5;188m"},
	{"189f", "\x1B[38;5;189m"},
	{"190f", "\x1B[38;5;190m"},
	{"191f", "\x1B[38;5;191m"},
	{"192f", "\x1B[38;5;192m"},
	{"193f", "\x1B[38;5;193m"},
	{"194f", "\x1B[38;5;194m"},
	{"195f", "\x1B[38;5;195m"},
	{"196f", "\x1B[38;5;196m"},
	{"197f", "\x1B[38;5;197m"},
	{"198f", "\x1B[38;5;198m"},
	{"199f", "\x1B[38;5;199m"},
	{"200f", "\x1B[38;5;200m"},
	{"201f", "\x1B[38;5;201m"},
	{"202f", "\x1B[38;5;202m"},
	{"203f", "\x1B[38;5;203m"},
	{"204f", "\x1B[38;5;204m"},
	{"205f", "\x1B[38;5;205m"},
	{"206f", "\x1B[38;5;206m"},
	{"207f", "\x1B[38;5;207m"},
	{"208f", "\x1B[38;5;208m"},
	{"209f", "\x1B[38;5;209m"},
	{"210f", "\x1B[38;5;210m"},
	{"211f", "\x1B[38;5;211m"},
	{"212f", "\x1B[38;5;212m"},
	{"213f", "\x1B[38;5;213m"},
	{"214f", "\x1B[38;5;214m"},
	{"215f", "\x1B[38;5;215m"},
	{"216f", "\x1B[38;5;216m"},
	{"217f", "\x1B[38;5;217m"},
	{"218f", "\x1B[38;5;218m"},
	{"219f", "\x1B[38;5;219m"},
	{"220f", "\x1B[38;5;220m"},
	{"221f", "\x1B[38;5;221m"},
	{"222f", "\x1B[38;5;222m"},
	{"223f", "\x1B[38;5;223m"},
	{"224f", "\x1B[38;5;224m"},
	{"225f", "\x1B[38;5;225m"},
	{"226f", "\x1B[38;5;226m"},
	{"227f", "\x1B[38;5;227m"},
	{"228f", "\x1B[38;5;228m"},
	{"229f", "\x1B[38;5;229m"},
	{"230f", "\x1B[38;5;230m"},
	{"231f", "\x1B[38;5;231m"},
	{"232f", "\x1B[38;5;232m"},
	{"233f", "\x1B[38;5;233m"},
	{"234f", "\x1B[38;5;234m"},
	{"235f", "\x1B[38;5;235m"},
	{"236f", "\x1B[38;5;236m"},
	{"237f", "\x1B[38;5;237m"},
	{"238f", "\x1B[38;5;238m"},
	{"239f", "\x1B[38;5;239m"},
	{"240f", "\x1B[38;5;240m"},
	{"241f", "\x1B[38;5;241m"},
	{"242f", "\x1B[38;5;242m"},
	{"243f", "\x1B[38;5;243m"},
	{"244f", "\x1B[38;5;244m"},
	{"245f", "\x1B[38;5;245m"},
	{"246f", "\x1B[38;5;246m"},
	{"247f", "\x1B[38;5;247m"},
	{"248f", "\x1B[38;5;248m"},
	{"249f", "\x1B[38;5;249m"},
	{"250f", "\x1B[38;5;250m"},
	{"251f", "\x1B[38;5;251m"},
	{"252f", "\x1B[38;5;252m"},
	{"253f", "\x1B[38;5;253m"},
	{"254f", "\x1B[38;5;254m"},
	{"255f", "\x1B[38;5;255m"},
	{"256f", "\x1B[38;5;256m"},


	/*full background spectrum colour*/
	{"0b", "\x1B[48;5;0m"},
	{"1b", "\x1B[48;5;1m"},
	{"2b", "\x1B[48;5;2m"},
	{"3b", "\x1B[48;5;3m"},
	{"4b", "\x1B[48;5;4m"},
	{"5b", "\x1B[48;5;5m"},
	{"6b", "\x1B[48;5;6m"},
	{"7b", "\x1B[48;5;7m"},
	{"8b", "\x1B[48;5;8m"},
	{"9b", "\x1B[48;5;9m"},
	{"10b", "\x1B[48;5;10m"},
	{"11b", "\x1B[48;5;11m"},
	{"12b", "\x1B[48;5;12m"},
	{"13b", "\x1B[48;5;13m"},
	{"14b", "\x1B[48;5;14m"},
	{"15b", "\x1B[48;5;15m"},
	{"16b", "\x1B[48;5;16m"},
	{"17b", "\x1B[48;5;17m"},
	{"18b", "\x1B[48;5;18m"},
	{"19b", "\x1B[48;5;19m"},
	{"20b", "\x1B[48;5;20m"},
	{"21b", "\x1B[48;5;21m"},
	{"22b", "\x1B[48;5;22m"},
	{"23b", "\x1B[48;5;23m"},
	{"24b", "\x1B[48;5;24m"},
	{"25b", "\x1B[48;5;25m"},
	{"26b", "\x1B[48;5;26m"},
	{"27b", "\x1B[48;5;27m"},
	{"28b", "\x1B[48;5;28m"},
	{"29b", "\x1B[48;5;29m"},
	{"30b", "\x1B[48;5;30m"},
	{"31b", "\x1B[48;5;31m"},
	{"32b", "\x1B[48;5;32m"},
	{"33b", "\x1B[48;5;33m"},
	{"34b", "\x1B[48;5;34m"},
	{"35b", "\x1B[48;5;35m"},
	{"36b", "\x1B[48;5;36m"},
	{"37b", "\x1B[48;5;37m"},
	{"38b", "\x1B[48;5;38m"},
	{"39b", "\x1B[48;5;39m"},
	{"40b", "\x1B[48;5;40m"},
	{"41b", "\x1B[48;5;41m"},
	{"42b", "\x1B[48;5;42m"},
	{"43b", "\x1B[48;5;43m"},
	{"44b", "\x1B[48;5;44m"},
	{"45b", "\x1B[48;5;45m"},
	{"46b", "\x1B[48;5;46m"},
	{"47b", "\x1B[48;5;47m"},
	{"48b", "\x1B[48;5;48m"},
	{"49b", "\x1B[48;5;49m"},
	{"50b", "\x1B[48;5;50m"},
	{"51b", "\x1B[48;5;51m"},
	{"52b", "\x1B[48;5;52m"},
	{"53b", "\x1B[48;5;53m"},
	{"54b", "\x1B[48;5;54m"},
	{"55b", "\x1B[48;5;55m"},
	{"56b", "\x1B[48;5;56m"},
	{"57b", "\x1B[48;5;57m"},
	{"58b", "\x1B[48;5;58m"},
	{"59b", "\x1B[48;5;59m"},
	{"60b", "\x1B[48;5;60m"},
	{"61b", "\x1B[48;5;61m"},
	{"62b", "\x1B[48;5;62m"},
	{"63b", "\x1B[48;5;63m"},
	{"64b", "\x1B[48;5;64m"},
	{"65b", "\x1B[48;5;65m"},
	{"66b", "\x1B[48;5;66m"},
	{"67b", "\x1B[48;5;67m"},
	{"68b", "\x1B[48;5;68m"},
	{"69b", "\x1B[48;5;69m"},
	{"70b", "\x1B[48;5;70m"},
	{"71b", "\x1B[48;5;71m"},
	{"72b", "\x1B[48;5;72m"},
	{"73b", "\x1B[48;5;73m"},
	{"74b", "\x1B[48;5;74m"},
	{"75b", "\x1B[48;5;75m"},
	{"76b", "\x1B[48;5;76m"},
	{"77b", "\x1B[48;5;77m"},
	{"78b", "\x1B[48;5;78m"},
	{"79b", "\x1B[48;5;79m"},
	{"80b", "\x1B[48;5;80m"},
	{"81b", "\x1B[48;5;81m"},
	{"82b", "\x1B[48;5;82m"},
	{"83b", "\x1B[48;5;83m"},
	{"84b", "\x1B[48;5;84m"},
	{"85b", "\x1B[48;5;85m"},
	{"86b", "\x1B[48;5;86m"},
	{"87b", "\x1B[48;5;87m"},
	{"88b", "\x1B[48;5;88m"},
	{"89b", "\x1B[48;5;89m"},
	{"90b", "\x1B[48;5;90m"},
	{"91b", "\x1B[48;5;91m"},
	{"92b", "\x1B[48;5;92m"},
	{"93b", "\x1B[48;5;93m"},
	{"94b", "\x1B[48;5;94m"},
	{"95b", "\x1B[48;5;95m"},
	{"96b", "\x1B[48;5;96m"},
	{"97b", "\x1B[48;5;97m"},
	{"98b", "\x1B[48;5;98m"},
	{"99b", "\x1B[48;5;99m"},
	{"100b", "\x1B[48;5;100m"},
	{"101b", "\x1B[48;5;101m"},
	{"102b", "\x1B[48;5;102m"},
	{"103b", "\x1B[48;5;103m"},
	{"104b", "\x1B[48;5;104m"},
	{"105b", "\x1B[48;5;105m"},
	{"106b", "\x1B[48;5;106m"},
	{"107b", "\x1B[48;5;107m"},
	{"108b", "\x1B[48;5;108m"},
	{"109b", "\x1B[48;5;109m"},
	{"110b", "\x1B[48;5;110m"},
	{"111b", "\x1B[48;5;111m"},
	{"112b", "\x1B[48;5;112m"},
	{"113b", "\x1B[48;5;113m"},
	{"114b", "\x1B[48;5;114m"},
	{"115b", "\x1B[48;5;115m"},
	{"116b", "\x1B[48;5;116m"},
	{"117b", "\x1B[48;5;117m"},
	{"118b", "\x1B[48;5;118m"},
	{"119b", "\x1B[48;5;119m"},
	{"120b", "\x1B[48;5;120m"},
	{"121b", "\x1B[48;5;121m"},
	{"122b", "\x1B[48;5;122m"},
	{"123b", "\x1B[48;5;123m"},
	{"124b", "\x1B[48;5;124m"},
	{"125b", "\x1B[48;5;125m"},
	{"126b", "\x1B[48;5;126m"},
	{"127b", "\x1B[48;5;127m"},
	{"128b", "\x1B[48;5;128m"},
	{"129b", "\x1B[48;5;129m"},
	{"130b", "\x1B[48;5;130m"},
	{"131b", "\x1B[48;5;131m"},
	{"132b", "\x1B[48;5;132m"},
	{"133b", "\x1B[48;5;133m"},
	{"134b", "\x1B[48;5;134m"},
	{"135b", "\x1B[48;5;135m"},
	{"136b", "\x1B[48;5;136m"},
	{"137b", "\x1B[48;5;137m"},
	{"138b", "\x1B[48;5;138m"},
	{"139b", "\x1B[48;5;139m"},
	{"140b", "\x1B[48;5;140m"},
	{"141b", "\x1B[48;5;141m"},
	{"142b", "\x1B[48;5;142m"},
	{"143b", "\x1B[48;5;143m"},
	{"144b", "\x1B[48;5;144m"},
	{"145b", "\x1B[48;5;145m"},
	{"146b", "\x1B[48;5;146m"},
	{"147b", "\x1B[48;5;147m"},
	{"148b", "\x1B[48;5;148m"},
	{"149b", "\x1B[48;5;149m"},
	{"150b", "\x1B[48;5;150m"},
	{"151b", "\x1B[48;5;151m"},
	{"152b", "\x1B[48;5;152m"},
	{"153b", "\x1B[48;5;153m"},
	{"154b", "\x1B[48;5;154m"},
	{"155b", "\x1B[48;5;155m"},
	{"156b", "\x1B[48;5;156m"},
	{"157b", "\x1B[48;5;157m"},
	{"158b", "\x1B[48;5;158m"},
	{"159b", "\x1B[48;5;159m"},
	{"160b", "\x1B[48;5;160m"},
	{"161b", "\x1B[48;5;161m"},
	{"162b", "\x1B[48;5;162m"},
	{"163b", "\x1B[48;5;163m"},
	{"164b", "\x1B[48;5;164m"},
	{"165b", "\x1B[48;5;165m"},
	{"166b", "\x1B[48;5;166m"},
	{"167b", "\x1B[48;5;167m"},
	{"168b", "\x1B[48;5;168m"},
	{"169b", "\x1B[48;5;169m"},
	{"170b", "\x1B[48;5;170m"},
	{"171b", "\x1B[48;5;171m"},
	{"172b", "\x1B[48;5;172m"},
	{"173b", "\x1B[48;5;173m"},
	{"174b", "\x1B[48;5;174m"},
	{"175b", "\x1B[48;5;175m"},
	{"176b", "\x1B[48;5;176m"},
	{"177b", "\x1B[48;5;177m"},
	{"178b", "\x1B[48;5;178m"},
	{"179b", "\x1B[48;5;179m"},
	{"180b", "\x1B[48;5;180m"},
	{"181b", "\x1B[48;5;181m"},
	{"182b", "\x1B[48;5;182m"},
	{"183b", "\x1B[48;5;183m"},
	{"184b", "\x1B[48;5;184m"},
	{"185b", "\x1B[48;5;185m"},
	{"186b", "\x1B[48;5;186m"},
	{"187b", "\x1B[48;5;187m"},
	{"188b", "\x1B[48;5;188m"},
	{"189b", "\x1B[48;5;189m"},
	{"190b", "\x1B[48;5;190m"},
	{"191b", "\x1B[48;5;191m"},
	{"192b", "\x1B[48;5;192m"},
	{"193b", "\x1B[48;5;193m"},
	{"194b", "\x1B[48;5;194m"},
	{"195b", "\x1B[48;5;195m"},
	{"196b", "\x1B[48;5;196m"},
	{"197b", "\x1B[48;5;197m"},
	{"198b", "\x1B[48;5;198m"},
	{"199b", "\x1B[48;5;199m"},
	{"200b", "\x1B[48;5;200m"},
	{"201b", "\x1B[48;5;201m"},
	{"202b", "\x1B[48;5;202m"},
	{"203b", "\x1B[48;5;203m"},
	{"204b", "\x1B[48;5;204m"},
	{"205b", "\x1B[48;5;205m"},
	{"206b", "\x1B[48;5;206m"},
	{"207b", "\x1B[48;5;207m"},
	{"208b", "\x1B[48;5;208m"},
	{"209b", "\x1B[48;5;209m"},
	{"210b", "\x1B[48;5;210m"},
	{"211b", "\x1B[48;5;211m"},
	{"212b", "\x1B[48;5;212m"},
	{"213b", "\x1B[48;5;213m"},
	{"214b", "\x1B[48;5;214m"},
	{"215b", "\x1B[48;5;215m"},
	{"216b", "\x1B[48;5;216m"},
	{"217b", "\x1B[48;5;217m"},
	{"218b", "\x1B[48;5;218m"},
	{"219b", "\x1B[48;5;219m"},
	{"220b", "\x1B[48;5;220m"},
	{"221b", "\x1B[48;5;221m"},
	{"222b", "\x1B[48;5;222m"},
	{"223b", "\x1B[48;5;223m"},
	{"224b", "\x1B[48;5;224m"},
	{"225b", "\x1B[48;5;225m"},
	{"226b", "\x1B[48;5;226m"},
	{"227b", "\x1B[48;5;227m"},
	{"228b", "\x1B[48;5;228m"},
	{"229b", "\x1B[48;5;229m"},
	{"230b", "\x1B[48;5;230m"},
	{"231b", "\x1B[48;5;231m"},
	{"232b", "\x1B[48;5;232m"},
	{"233b", "\x1B[48;5;233m"},
	{"234b", "\x1B[48;5;234m"},
	{"235b", "\x1B[48;5;235m"},
	{"236b", "\x1B[48;5;236m"},
	{"237b", "\x1B[48;5;237m"},
	{"238b", "\x1B[48;5;238m"},
	{"239b", "\x1B[48;5;239m"},
	{"240b", "\x1B[48;5;240m"},
	{"241b", "\x1B[48;5;241m"},
	{"242b", "\x1B[48;5;242m"},
	{"243b", "\x1B[48;5;243m"},
	{"244b", "\x1B[48;5;244m"},
	{"245b", "\x1B[48;5;245m"},
	{"246b", "\x1B[48;5;246m"},
	{"247b", "\x1B[48;5;247m"},
	{"248b", "\x1B[48;5;248m"},
	{"249b", "\x1B[48;5;249m"},
	{"250b", "\x1B[48;5;250m"},
	{"251b", "\x1B[48;5;251m"},
	{"252b", "\x1B[48;5;252m"},
	{"253b", "\x1B[48;5;253m"},
	{"254b", "\x1B[48;5;254m"},
	{"255b", "\x1B[48;5;255m"},
	{"256b", "\x1B[48;5;256m"}
};
//};

#endif /*#ifdef _WIN32*/
