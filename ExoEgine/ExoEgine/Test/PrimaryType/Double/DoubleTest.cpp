#include "DoubleTest.h"

#include "../../../Engine/PrimaryType/Double/Double.h"
#include "../../../Engine/PrimaryType/Integer/Integer.h"
#include "../../../Engine/Utils/DebugMacro.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../../Engine/PrimaryType/Float/Float.h"

void Test::DoubleTest::Test()
{
	Engine::PrimaryType::Double _a = 10;
	Engine::PrimaryType::Double _b = 15;

	checkLow((_a < _b), "_a is not < to _b")
		checkLow((_b > _a), "_b is not > to _a")

		Engine::PrimaryType::Double _c = Engine::PrimaryType::Double::Parse("15");
	checkLow((_c == 15.), "_c is not equals to 15")
		checkLow((_c != _a), " _c is not != to a")
		checkLow((_b >= _c), "_b is not >= to _c")
		checkLow((_a <= _c), "a is not <= to c")

		Engine::PrimaryType::Double _d = _a + _b;
	checkLow((_d == 25.), "d is not equals to a+b = 25")
		_d = _b - _a;
	checkLow((_d == 5.), "d us bit equals to b - a = 5")
		_d = _a * _b;
	checkLow((_d == 150.), "d is not equals to a*b = 150")
		_d = _a / 2.;
	checkLow((_d == 5.), "d is not equals to a % b = 10")
		_d += 250.f;
	checkLow((_d == 255.0), "d is not equals to d+= 150 = 260")
		_d -= 30.f;
	checkLow((_d == 225.), "d is not equals to d -= 30 = 230")
		_d *= 2.f;
	checkLow((_d = 450.), "d is not equals to d *= 2 = 460")
		_d /= 4.f;
	checkLow((_d == 112.5), "d is not equals to d/= 4 = 112.5")


		_d = Engine::PrimaryType::Double::NaN;
	checkLow((Engine::PrimaryType::Double::IsNaN(_d)), "d is not equals to NaN")
		_d = Engine::PrimaryType::Double::Epsilon;
	checkLow((Engine::PrimaryType::Double::IsEpsilon(_d)), "d is not equals to Epsilon")
		_d = Engine::PrimaryType::Double::PositiveInfinity;
	checkLow((Engine::PrimaryType::Double::IsPositiveInfinity(_d)), "d is not equals to PositiveInfinity")
		_d = Engine::PrimaryType::Double::NegativeInfinity;
	checkLow((Engine::PrimaryType::Double::IsNegativeInfinity(_d)), "d is not equals to 	NegativeInfinity")

		Engine::Utils::Console::Log("[Double][Test] => successful !");
}
