#include <N1ghtTheF0x/LibKitsune/Math/Random.hpp>
#include <N1ghtTheF0x/LibKitsune/Math.hpp>

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace Math
        {
            Random::Random(u64 seed)
            {
                _seed = seed;
            }
            u64 Random::seed() const
            {
                return _seed;
            }
            Random &Random::setSeed(u64 seed)
            {
                _seed = (seed ^ 0x5deec366dl) & ((1l << 48) - 1);
                return *this;
            }
            s32 Random::next(Size bits)
            {
                _seed = (_seed * 0x5deece66dl + 0xbl) & ((1l << 48) - 1);
                return (s32)(_seed >> (48 - max((Size)32,min(bits,(Size)1))));
            }
            s32 Random::nextSInt32()
            {
                return next(32);
            }
            s32 Random::nextSInt32(Size bound)
            {
                if((bound & -bound) == bound)
                    return (s32)((bound * next(31)) >> 31);
                Size bits, val;
                do {
                    bits = next(31);
                    val = bits % bound;
                } while(bits - val + (bound - 1) < 0);
                return val;
            }
            s64 Random::nextSInt64()
            {
                return ((s64)next(32) << 32) + next(32);
            }
            bool Random::nextBool()
            {
                return next(1) != 0;
            }
            float Random::nextFloat()
            {
                return next(24) / ((float)(1 << 24));
            }
            double Random::nextDouble()
            {
                return (((s64)next(26) << 27) + next(27)) / (double)(1l << 53);
            }
            double Random::nextGaussian()
            {
                if(_hasNextGaussian)
                {
                    _hasNextGaussian = false;
                    return _nextGaussian;
                }
                double v1, v2, s;
                do {
                    v1 = 2 * nextDouble() - 1;
                    v2 = 2 * nextDouble() - 1;
                    s = v1 * v1 + v2 * v2;
                } while(s >= 1 || s == 0);
                double multiplier = squareRoot(-2 * logarithm(s)/s);
                _nextGaussian = v2 * multiplier;
                _hasNextGaussian = true;
                return v1 * multiplier;
            }
            Size Random::nextIndex(Size length)
            {
                return (Size)(nextDouble() * length);
            }
        }
    }
}