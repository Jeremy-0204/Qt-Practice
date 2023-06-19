#include <MGenNamespaceDef.h>
#pragma once

MGEN_NAMESPACE_START

#pragma region LASER_DEFINTION

    enum ELaserType{
        superlumBS840
    };

    enum ELaserStatusMode // 매뉴얼에는 없던데 어떤 기준으로 하셨는지 궁금함, NexMet 참조함
    {
        PowerOff,
        PowerOn,
        ReadyToFire,
        Fire,
        LasorError
    };

    enum ESuperlumLaserPowerMode
    {
        Shutdown = 0,
        WarmUp = 1,
        Function = 2,
        PowerError = 3
    };

    enum ESuperlumLaserControlMode
    {
        Local = 0,
        Remote = 1,
        USB = 2
    };

    enum ESuperlumLaserSweepMode
    {
        SingleTone = 0,
        SingleSweep = 1,
        ContinuousSweep = 2
    };

    struct SuperlumLaserParam
    {
        // Superlum Swept Source Command Set 참조

        // 1.1 Read Device type - READ ONLY
        // e.g. "I\r\n"
        char DeviceType[256] = { 0, };


        // 1.2 Read Device Status, Set Device Operation Mode - READ, WRITE
        // e.g. "M\r\n"         – For READ operation
        //      "M[CMD]\r\n     – For SET operation
        ELaserStatusMode StatusMode = ELaserStatusMode :: PowerOff;
        ESuperlumLaserControlMode ControlMode = ESuperlumLaserControlMode :: Local;
        ESuperlumLaserSweepMode SweepMode = ESuperlumLaserSweepMode :: SingleTone;
        ESuperlumLaserPowerMode PowerMode = ESuperlumLaserPowerMode :: Shutdown;

        // Acknowledge MSB Status
        bool bAotfTecPower = false;             // true : ON        false : OFF
        bool bAotfTecStable = false;            // true : Stable    false : Unstable
        bool bAotfTecStatus = false;            // true : OK        false : Error
        bool bSldTecPower = false;
        bool bSldTecStable = false;
        bool bSldTecStatus = false;

        bool bSldPower = false;
        bool bSldCurrentLimit = false;          // true : OK        false : Limit Reached


        // 1.3 Read, Set Device Parameter
        // e.g. "P[PN]\r\n"         – For READ operation
        //      "P[PN][DATA]\r\n     – For SET operation

        // [PN] : 0X
        char Firmware[128] = { 0, };
        int BaseFrequency = 0;                  // [0x00] : 0MHz    [0xFF] : 255MHz
        int MeanWaveLength = 0;                 // [0x0000] : 0nm   [0xFFF] : 4095nm
        int BaseWaveLength = 0;                 // [0x0000] : 0nm   [0xFFF] : 4095nm
        int MinimumSweepRange = 0;              // [0x1] : 1nm      [0xA] : 10nm

        // [PN] : 1X
        char SerialNumber[128] = { 0, };
        float MinWaveLength = 0;
        float MaxWaveLength = 0;

        // [PN] : 2X
        int OffModeData = 0;
        int SweepTime = 0;
        int SweepDirection = 0;
    };

#pragma endregion
MGEN_NAMESPACE_END
