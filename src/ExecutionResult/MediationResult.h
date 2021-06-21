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
};

}

#endif
