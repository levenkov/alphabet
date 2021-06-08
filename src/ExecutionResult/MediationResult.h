#ifndef ABC_MEDIATION_RESULT_H
#define ABC_MEDIATION_RESULT_H


#include "ExecutionResult.h"


namespace abc
{

class MediationResult : public ExecutionResult
{
public:
    MediationResult(ResultCode code) : ExecutionResult(code) { }
    MediationResult(int code) : ExecutionResult(code) { }

    static ResultCode fromIntegerCode(int code) {
        switch (code) {
        case 64: return kSuccess;
        case 0: return kSuccessAndFinal;
        default:
            return kFailed;
        }
    }

    static int toIntegerCode(ResultCode code) {
        switch (code) {
        case kSuccess: return 64;
        case kSuccessAndFinal: return 0;
        default:
            return 1;
        }
    }
};

}

#endif
