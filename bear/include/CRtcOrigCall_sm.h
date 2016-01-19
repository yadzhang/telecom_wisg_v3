#ifndef _H_CRTCORIGCALL_SM
#define _H_CRTCORIGCALL_SM

/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : CRtcOrigCall_sm.sm
 */


#define SMC_USES_IOSTREAMS

#include <statemap.h>

// Forward declarations.
class CRtcOrigCallState;
class CRtcOrigCallState_IDLE;
class CRtcOrigCallState_RTC_CONFIRMING;
class CRtcOrigCallState_BEAR_CONFIRMING;
class CRtcOrigCallState_BEAR_CONFIRMED;
class CRtcOrigCallState_ACTIVE;
class CRtcOrigCallState_ACTIVE_WAIT1;
class CRtcOrigCallState_ACTIVE_WAIT2;
class CRtcOrigCallState_CLOSED;
class CRtcOrigCallState_Default;
class CR2SCallModuleState;
class CRtcOrigCallContext;
class CR2SCallModule;

class CR2SCallModuleState :
    public statemap::State
{
public:

    CR2SCallModuleState(const char *name, int stateId)
    : statemap::State(name, stateId)
    {};

    virtual void Entry(CRtcOrigCallContext&) {};
    virtual void Exit(CRtcOrigCallContext&) {};

    virtual void onAnswer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onError(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onNotify(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onOK(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onOffer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onSdpAnswer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onTimeOut(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onTimeOut(CRtcOrigCallContext& context, TTimeMarkExt timerMark);

protected:

    virtual void Default(CRtcOrigCallContext& context);
};

class CRtcOrigCallState
{
public:

    static CRtcOrigCallState_IDLE IDLE;
    static CRtcOrigCallState_RTC_CONFIRMING RTC_CONFIRMING;
    static CRtcOrigCallState_BEAR_CONFIRMING BEAR_CONFIRMING;
    static CRtcOrigCallState_BEAR_CONFIRMED BEAR_CONFIRMED;
    static CRtcOrigCallState_ACTIVE ACTIVE;
    static CRtcOrigCallState_ACTIVE_WAIT1 ACTIVE_WAIT1;
    static CRtcOrigCallState_ACTIVE_WAIT2 ACTIVE_WAIT2;
    static CRtcOrigCallState_CLOSED CLOSED;
};

class CRtcOrigCallState_Default :
    public CR2SCallModuleState
{
public:

    CRtcOrigCallState_Default(const char *name, int stateId)
    : CR2SCallModuleState(name, stateId)
    {};

    virtual void onSdpAnswer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onError(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onOK(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onOffer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onAnswer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onNotify(CRtcOrigCallContext& context, TUniNetMsg* msg);
    virtual void onTimeOut(CRtcOrigCallContext& context, TTimeMarkExt timerMark);
};

class CRtcOrigCallState_IDLE :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_IDLE(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onOffer(CRtcOrigCallContext& context, TUniNetMsg* msg);
};

class CRtcOrigCallState_RTC_CONFIRMING :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_RTC_CONFIRMING(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onError(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onNotify(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onTimeOut(CRtcOrigCallContext& context, TTimeMarkExt timerMark);
};

class CRtcOrigCallState_BEAR_CONFIRMING :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_BEAR_CONFIRMING(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onError(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onSdpAnswer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onTimeOut(CRtcOrigCallContext& context, TUniNetMsg* msg);
};

class CRtcOrigCallState_BEAR_CONFIRMED :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_BEAR_CONFIRMED(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onOK(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onTimeOut(CRtcOrigCallContext& context, TTimeMarkExt timerMark);
};

class CRtcOrigCallState_ACTIVE :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_ACTIVE(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onNotify(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onOffer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
};

class CRtcOrigCallState_ACTIVE_WAIT1 :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_ACTIVE_WAIT1(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onError(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onSdpAnswer(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onTimeOut(CRtcOrigCallContext& context, TUniNetMsg* msg);
};

class CRtcOrigCallState_ACTIVE_WAIT2 :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_ACTIVE_WAIT2(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void onClose(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onOK(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onShutDown(CRtcOrigCallContext& context, TUniNetMsg* msg);
    void onTimeOut(CRtcOrigCallContext& context, TTimeMarkExt timerMark);
};

class CRtcOrigCallState_CLOSED :
    public CRtcOrigCallState_Default
{
public:
    CRtcOrigCallState_CLOSED(const char *name, int stateId)
    : CRtcOrigCallState_Default(name, stateId)
    {};

    void Entry(CRtcOrigCallContext&);
};

class CRtcOrigCallContext :
    public statemap::FSMContext
{
public:

    CRtcOrigCallContext(CR2SCallModule& owner)
    : FSMContext(CRtcOrigCallState::IDLE),
      _owner(owner)
    {};

    CRtcOrigCallContext(CR2SCallModule& owner, const statemap::State& state)
    : FSMContext(state),
      _owner(owner)
    {};

    virtual void enterStartState()
    {
        getState().Entry(*this);
        return;
    }

    CR2SCallModule& getOwner() const
    {
        return (_owner);
    };

    CR2SCallModuleState& getState() const
    {
        if (_state == NULL)
        {
            throw statemap::StateUndefinedException();
        }

        return (dynamic_cast<CR2SCallModuleState&>(*_state));
    };

    void onAnswer(TUniNetMsg* msg)
    {
        (getState()).onAnswer(*this, msg);
    };

    void onClose(TUniNetMsg* msg)
    {
        (getState()).onClose(*this, msg);
    };

    void onError(TUniNetMsg* msg)
    {
        (getState()).onError(*this, msg);
    };

    void onNotify(TUniNetMsg* msg)
    {
        (getState()).onNotify(*this, msg);
    };

    void onOK(TUniNetMsg* msg)
    {
        (getState()).onOK(*this, msg);
    };

    void onOffer(TUniNetMsg* msg)
    {
        (getState()).onOffer(*this, msg);
    };

    void onSdpAnswer(TUniNetMsg* msg)
    {
        (getState()).onSdpAnswer(*this, msg);
    };

    void onShutDown(TUniNetMsg* msg)
    {
        (getState()).onShutDown(*this, msg);
    };

    void onTimeOut(TUniNetMsg* msg)
    {
        (getState()).onTimeOut(*this, msg);
    };

    void onTimeOut(TTimeMarkExt timerMark)
    {
        (getState()).onTimeOut(*this, timerMark);
    };

private:

    CR2SCallModule& _owner;
};


/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */

#endif // _H_CRTCORIGCALL_SM
