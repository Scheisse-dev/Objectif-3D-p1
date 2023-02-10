#include "FloatTest.h"
#include "../../../Engine/PrimaryType/Float/Float.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../../Engine/Utils/DebugMacro.h"

#pragma region methods
void Test::FloatTest::Test()
{
	Engine::PrimaryType::Float a = 10.f;
	Engine::PrimaryType::Float b = 15.f;

	checkLow((a < b), "a is not < to b")
		checkLow((b > a), "b is not > to a")

		Engine::PrimaryType::Float c = Engine::PrimaryType::Float::Parse("15");
	checkLow((c == 15.f), "c is not == to 15")
		checkLow((c != a), "c is not != to a")
		checkLow((b >= c), "b is not >= to c")
		checkLow((a <= c), "a is not <= to c")

		Engine::PrimaryType::Float d = a + b;
	checkLow((d == 25.f), "d is not == to a+b")
		d = b - a;
	checkLow((d == 5.f), "d is not == to b-a")
		d = a * b;
	checkLow((d == 150.f), "d is not == to a*b")
		d = a / 2.f;
	checkLow((d == 5.f), "d is not == to a/2")
		d += 250;
	checkLow((d == 255.f), "d is not == to d += 250")
		d -= 30;
	checkLow((d == 225.f), "d is not == to d -= 30")
		d *= 2;
	checkLow((d == 450.f), "d is not == to d *= 2")
		d /= 4;
	checkLow((d == 112.5f), "d is not == to d /= 4")
		d = Engine::PrimaryType::Float::NaN;
	checkLow((Engine::PrimaryType::Float::IsNaN(d)), "d is not == to NaN")
		d = Engine::PrimaryType::Float::Epsilon;
	checkLow((Engine::PrimaryType::Float::IsEpsilon(d)), "d is not == to Epsilon")
		d = Engine::PrimaryType::Float::PositiveInfinity;
	checkLow((Engine::PrimaryType::Float::IsPositifInfinite(d)), "d is not == to PositiveInfinity")
		d = Engine::PrimaryType::Float::NegativeInfinity;
	checkLow((Engine::PrimaryType::Float::IsNegatifInFinite(d)), "d is not == to NegativeInfinity")

	Engine::Utils::Console::Log("[Float][test] => succesfull");
}
#pragma endregion

