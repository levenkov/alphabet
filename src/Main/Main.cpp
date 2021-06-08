#include <iostream>

#include <ToolsetSearcher/ToolsetSearcher.h>
#include <Toolset/Toolset.h>
#include <Tool/Tool.h>

#include "Main.h"


using namespace std;

using namespace abc;


namespace {
    const string kAlphabetExecutableName = "abc";
    const string kAlphabetVersion = "0.0.1";
}


int Main::run(const string programName, const vector<string> arguments) {
    if (programName == kAlphabetExecutableName) {
        return runDirectMode(arguments);
    }

    return runMediatorMode(programName, arguments);
}

int Main::runDirectMode(const vector<string> arguments) {
    cout << kAlphabetExecutableName << " " << kAlphabetVersion << endl;

    return 0;
}

int Main::runMediatorMode(const string programName, const vector<string> arguments) {
    // TODO: CommandContext commandContext;
    ToolsetSearcher searcher(programName, arguments);

    for(auto toolset: searcher.search()) {
        for(auto tool: toolset.tools()) {
            ProbingResult probingResult = tool.probe(arguments);

            if(probingResult.isFailed())
                continue;

            // TODO: auto mediationContext = commandContext.prepareMediationContext();

            MediationResult mediationResult = tool.execute();

            if (
                mediationResult == MediationResult::kFailed ||
                mediationResult == MediationResult::kSuccessAndFinal
            ) {
                return mediationResult.exitCode();
            }
        }
    }

    return 0;
}
