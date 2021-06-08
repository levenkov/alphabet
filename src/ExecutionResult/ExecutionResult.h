#ifndef ABC_EXECUTION_RESULT_H
#define ABC_EXECUTION_RESULT_H

namespace abc
{

class ExecutionResult
{
public:
    enum ResultCode {
        kFailed,
        kSuccess,
        kSuccessAndFinal
    };

    ExecutionResult(ResultCode code) : m_code(code) { }
    ExecutionResult(int code) : m_code(fromIntegerCode(code)) { }

    int exitCode() const {
        return toIntegerCode(m_code);
    }

    bool isFailed() const { return m_code == kFailed; }

    static ResultCode fromIntegerCode(int code) {
        switch (code)
        {
        case 0:
            return kSuccess;
        default:
            return kFailed;
        }
    }

    static int toIntegerCode(ResultCode code) {
        switch (code)
        {
        case kSuccess:
            return 0;
        default:
            return 1;
        }
    }

protected:
    ResultCode m_code;

    friend bool operator==(const ExecutionResult &result, ExecutionResult::ResultCode resultCode);
};

inline bool operator==(const ExecutionResult &result, ExecutionResult::ResultCode resultCode) {
    return result.m_code == resultCode;
}

}

#endif
