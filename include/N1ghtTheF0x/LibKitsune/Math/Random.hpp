#ifndef __N1GHTTHEF0X_LIBKITSUNE_MATH_RANDOM_HPP
#define __N1GHTTHEF0X_LIBKITSUNE_MATH_RANDOM_HPP

#include "../Memory.hpp"

namespace N1ghtTheF0x
{
    namespace LibKitsune
    {
        namespace Math
        {   
            class Random
            {
            private:
                u64 _seed;
                double _nextGaussian;
                bool _hasNextGaussian = false;
            public:
                Random(u64 seed);

                u64 seed() const;
                Random &setSeed(u64 seed);

                s32 next(Size bits);
                s32 nextSInt32();
                s32 nextSInt32(Size bound);
                s64 nextSInt64();
                bool nextBool();
                float nextFloat();
                double nextDouble();
                double nextGaussian();
                Size nextIndex(Size length);
            };
        }
    }
}

#endif