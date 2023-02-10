#include "IntegerTest.h"
#include "../../../Engine/PrimaryType/Integer/Integer.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../../Engine/Utils/DebugMacro.h"

#pragma region methods
void Test::IntegerTest::Test()
{
	Engine::PrimaryType::Integer a = 10;
	Engine::PrimaryType::Integer b = 15;

	checkLow((a < b), "a is not < to b")
	checkLow((b > a), "b is not > to a")

	Engine::PrimaryType::Integer c = Engine::PrimaryType::Integer::Parse("15");
	checkLow((c == 15), "c is not == to 15")
    checkLow((c != a), "c is not != to a")
    checkLow((b >= c), "b is not >= to c")
    checkLow((a <= c), "a is not <= to c")

		Engine::PrimaryType::Integer d = a + b;
	checkLow((d == 25), "d is not == to a+b")
		d = b - a;
	checkLow((d == 5), "d is not == to b-a")
		d = a * b;
	checkLow((d == 150), "d is not == to a*b")
		d = a / 2;
	checkLow((d == 5), "d is not == to a/2")
		d = a % b;
	checkLow((d == 10), "d is not == to a%b")
		d += 250;
	checkLow((d == 260), "d is not == to d += 250")
		d -= 30; 
	checkLow((d == 230), "d is not == to d -= 30")
		d *= 2;
	checkLow((d == 460), "d is not == to d *= 2")
		d /= 4;
	checkLow((d == 115), "d is not == to d /= 4")
		d %= 2;
	checkLow((d == 1), "d is not == to d %= 2")
		++d;
	checkLow((d == 2), "d is not == to ++d")
		--d;
	checkLow((d == 1), "d is not == to -d")

		Engine::Utils::Console::Log("[Integer][Test] => succesfull");
}
#pragma endregion

