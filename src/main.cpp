#include "c_printf.h"

int main(int argc, char const *argv[])
{
	auto test_str1 = 
R"test_string(

%%
print integer %d
print float %f
print string %s

/r]dim red/!]
/rr]dim red on dim red/!]
/rg]dim red on dim green/!]
/rb]dim red on dim blue/!]
/ry]dim red on dim yellow/!]
/rm]dim red on dim magenta/!]
/rc]dim red on dim cyan/!]
/rw]dim red on dim white/!]

/r!]bright red/!]
/r!r]bright red on dim red/!]
/r!g]bright red on dim green/!]
/r!b]bright red on dim blue/!]
/r!y]bright red on dim yellow/!]
/r!m]bright red on dim magenta/!]
/r!c]bright red on dim cyan/!]
/r!w]bright red on dim white/!]

/rr!]dim red on bright red/!]
/rg!]dim red on bright green/!]
/rb!]dim red on bright blue/!]
/ry!]dim red on bright yellow/!]
/rm!]dim red on bright magenta/!]
/rc!]dim red on bright cyan/!]
/rw!]dim red on bright white/!]

/r!r!]bright red on bright red/!]
/r!g!]bright red on bright green/!]
/r!b!]bright red on bright blue/!]
/r!y!]bright red on bright yellow/!]
/r!m!]bright red on bright magenta/!]
/r!c!]bright red on bright cyan/!]
/r!w!]bright red on bright white/!]

/g]dim green /g!]bright green/!]

/b]dim blue /b!]bright blue/!]

/y]dim yellow /y!]bright yellow/!]

/m]dim magenta /m!]bright magenta/!]

/c]dim cyan /c!]bright cyan/!]

/w]dim white /w!]bright white/!]

)test_string";

	/* test code */
	c_printf(stdout, test_str1, 10u, 10.0f, "hello world!");

	c_printf(stdout, "writing in /r!]red\n");
	
	auto test_str2 = 
R"test_foo(

/_60r!]

Sample code:

/b!]#include/c!]<iostream>/!]

/b!]using namespace/!] std;

/b!]int/!] main(/b!]int/!] argc, /b!]char/!] argv**)
{
    /b!]int/!] num, factorial = %d;

    cout << /r!]" Enter Number To Find Its Factorial:  "/!];

    cin >> num;

    /b!]for/!](/b!]int/!] a=1; a <= num; a++)
    {
        factorial = factorial * a;
    }
%%
	cout << /r!]"Factorial of Given Number is = "/!] << factorial <<endl;

    /b!]return/!] 0;
}

/_60r!]

)test_foo";

	c_printf(stdout, test_str2, 7);

auto test_str3 = 
R"test_foo(
              .----.
    .----.    
     /w!]</b!](o)/!]/w!]>/!]|  |/w!]</b!](o)/!]/w!]>/!] 
  {       |  |       }
         _|  |_
        (_    _)
     ,    `--`    ,
      '-.______.-'

	)test_foo";
    
	c_printf(stdout, test_str3);
	return 0;
}
