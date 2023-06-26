#include <MGenDeviceDef.h>
#include <QObject>

MGEN_NAMESPACE_START

class SuperlumBS840VM
{
    Q_OBJECT

public:
    explicit SuperlumBS840VM(QObject *parent = nullptr);
    virtual ~SuperlumBS840VM();

/*
 * 필요한 함수 모음
 * onClickedConnect
 * onClickedClose
 * onClickedRefresh
 * onClickedPowerOn
 * onClickedPowerOff
 * onClickedLaserOn
 * onClickedLaserOff
 *
 * OnClickedSetSingleToneWaveLength
 * OnClickedSetStartWaveLength
 * OnClickedSetStopWaveLength
 * OnClickedSetSweptSpeed
 * OnClickedSetPauseTime
 * OnClickedSetSweptMode
 * OnClickedSetControlMode
 *
*/


};

MGEN_NAMESPACE_END
