#include <stdexcept>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/process.hpp>

#include "Tool.h"


using namespace std;
using namespace boost::asio;
using namespace boost::process;

using namespace abc;


ProbingResult Tool::probe(const vector<string> arguments)
{
    future<string> output_buffer;

    auto result = ProbingResult(
        system(m_path.c_str(), arguments, std_out > output_buffer)
    );

    m_probingOutput = output_buffer.get();

    if (result.isFailed()) {
        m_bProbed = false;
        return result;
    }

    m_bProbed = true;

    return result;
}

MediationResult Tool::execute()
{
    if (!m_bProbed)
        throw logic_error("Can't execute unprobed Tool.");

    return MediationResult(
        system("/bin/bash", std_in < buffer(m_probingOutput), std_out > stdout, std_err > stderr)
    );
}
