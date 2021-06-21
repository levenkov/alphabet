#ifndef ABC_PROBING_RESULT_H
#define ABC_PROBING_RESULT_H


#include "ExecutionResult.h"


namespace abc
{

class ProbingResult : public ExecutionResult
{
public:
    ProbingResult(ResultCode code) : ExecutionResult(code) { }
    ProbingResult(int code) : ExecutionResult(fromIntegerCode(code)) { }

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

    virtual int exitCode() const { return toIntegerCode(m_code); }
};

}

#endif
