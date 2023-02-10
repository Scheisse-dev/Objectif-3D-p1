#include "DoubleTest.h"
#include "../../../Engine/PrimaryType/Double/Double.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include "../../../Engine/Utils/DebugMacro.h"

#pragma region methods
void Test::DoubleTest::Test()
{
    Engine::PrimaryType::Double a = 10.f;
    Engine::PrimaryType::Double b = 15.f;

    checkLow((a < b), "a is not < to b")
        checkLow((b > a), "b is not > to a")

        Engine::PrimaryType::Double c = Engine::PrimaryType::Double::Parse("15");
    checkLow((c == 15.0), "c is not == to 15")
        checkLow((c != a), "c is not != to a")
        checkLow((b >= c), "b is not >= to c")
        checkLow((a <= c), "a is not <= to c")

        Engine::PrimaryType::Double d = a + b;
    checkLow((d == 25.0), "d is not == to a+b")
        d = b - a;
    checkLow((d == 5.0), "d is not == to b-a")
        d = a * b;
    checkLow((d == 150.0), "d is not == to a*b")
        d = a / 2.0;
    checkLow((d == 5.0), "d is not == to a/2")
        d += 250;
    checkLow((d == 255.0), "d is not == to d += 250")
        d -= 30;
    checkLow((d == 225.0), "d is not == to d -= 30")
        d *= 2;
    checkLow((d == 450.0), "d is not == to d *= 2")
        d /= 4;
    checkLow((d == 112.50), "d is not == to d /= 4")
        d = Engine::PrimaryType::Double::NaN;
    checkLow((Engine::PrimaryType::Double::IsNaN(d)), "d is not == to NaN")
        d = Engine::PrimaryType::Double::Epsilon;
    checkLow((Engine::PrimaryType::Double::IsEpsilon(d)), "d is not == to Epsilon")
        d = Engine::PrimaryType::Double::PositiveInfinity;
    checkLow((Engine::PrimaryType::Double::IsPositifInfinite(d)), "d is not == to PositiveInfinity")
        d = Engine::PrimaryType::Double::NegativeInfinity;
    checkLow((Engine::PrimaryType::Double::IsNegatifInFinite(d)), "d is not == to NegativeInfinity")

        Engine::Utils::Console::Log("[Double][test] => succesfull");
}
#pragma endregion

