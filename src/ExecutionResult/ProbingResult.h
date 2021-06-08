#ifndef ABC_PROBING_RESULT_H
#define ABC_PROBING_RESULT_H


#include "ExecutionResult.h"


namespace abc
{

class ProbingResult : public ExecutionResult
{
public:
    ProbingResult(ResultCode code) : ExecutionResult(code) { }
    ProbingResult(int code) : ExecutionResult(code) { }
};

}

#endif
