#include <MGenNamespaceDef.h>
#pragma once

MGEN_NAMESPACE_START

#pragma region LASER_DEFINTION

    enum ELaserType{
        SuperlumBS840
    };

    enum ELaserStatusMode // 매뉴얼에는 없던데 어떤 기준으로 하셨는지 궁금함, NexMet 참조함
    {
        PowerOff,
        PowerOn,
        ReadyToFire,
        Fire,
        LasorError
    };

    enum ESuperlumPowerMode
    {
        Shutdown = 0,
        WarmUp = 1,
        Function = 2,
        PowerError = 3
    };

    enum ESuperlumControlMode
    {
        Local = 0,
        Remote = 1,
        USB = 2
    };

    enum ESuperlumLaserSweepMode
    {
        SingleTone = 0,
        SingleSweep = 1,
        ContinuousSwwp = 2
    };

#pragma endregion
MGEN_NAMESPACE_END
